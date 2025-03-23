#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int MAX_INT = 1000000000;         // Manually defined "infinity" value for distances

// When called, the type across each Vertex, Edge, and Graph has to be consistent.

// Class representing a vertex in a graph
template <typename TYPE>
class Vertex 
{
    public:
        TYPE data;
        Vertex(const TYPE& vertexData) : data(vertexData) {} //Constructor
};

// Class representing a directed edge in a graph
template <typename TYPE>
class Edge 
{
    public:
        Vertex<TYPE>* fromVertex;
        Vertex<TYPE>* toVertex;
        int weight;
        
        //Constructor
        Edge(Vertex<TYPE>* from, Vertex<TYPE>* to, int edgeWeight) : fromVertex(from), toVertex(to), weight(edgeWeight) {}
};

// Class representing a directed graph
template <typename TYPE>
class Graph 
{
    private:
        // Mapping from each vertex to a list of outgoing and incoming edges
        unordered_map<Vertex<TYPE>*, vector<Edge<TYPE>*>*> fromEdges;
        unordered_map<Vertex<TYPE>*, vector<Edge<TYPE>*>*> toEdges;
    
    public:
        // Function to add a vertex to the graph
        Vertex<TYPE>* AddVertex(const TYPE& newVertexData) 
        {
            Vertex<TYPE>* newVertex = new Vertex<TYPE>(newVertexData);
            fromEdges[newVertex] = new vector<Edge<TYPE>*>();
            toEdges[newVertex] = new vector<Edge<TYPE>*>();
            return newVertex;
        }
        
        // Function to add a directed edge to the graph if it doesn't already exist
        Edge<TYPE>* AddDirectedEdge(Vertex<TYPE>* fromVertex, Vertex<TYPE>* toVertex, double weight = 1.0) 
        {
            if (HasEdge(fromVertex, toVertex)) 
            {
                return nullptr;
            }
            
            Edge<TYPE>* newEdge = new Edge<TYPE>(fromVertex, toVertex, weight);
            fromEdges[fromVertex]->push_back(newEdge);
            toEdges[toVertex]->push_back(newEdge);
            return newEdge;
        }
        
        // Check if an edge exists from 'fromVertex' to 'toVertex'
        bool HasEdge(Vertex<TYPE>* fromVertex, Vertex<TYPE>* toVertex) const 
        {
            if (fromEdges.find(fromVertex) == fromEdges.end()) 
            {
                return false;
            }
            for (Edge<TYPE>* edge : *fromEdges.at(fromVertex)) 
            {
                if (edge->toVertex == toVertex) 
                {
                    return true;
                }
            }
            return false;
        }
        
        // Implements Dijkstra's algorithm to find the shortest path from source to destination
        void DijkstraShortestPath(Vertex<TYPE>* source, Vertex<TYPE>* destination) 
        {
            unordered_map<Vertex<TYPE>*, int> distances;
            unordered_map<Vertex<TYPE>*, Vertex<TYPE>*> predecessors;
            unordered_set<Vertex<TYPE>*> visited;
    
            // adds every vertex to distances and predecessors with their respective key-pair values
            // the key for each is the vertex.
            for (auto& vertex : GetVertices()) 
            {
                distances[vertex] = MAX_INT; // since the distance to each vertex is unknown from the source, they are set to an impossibly high number.
                predecessors[vertex] = nullptr;
            }
    
            // sets the distance from the source vertex (passed as argument) to int.
            distances[source] = 0;
    
            // while the size of visited map is less than that of distances map
            while (visited.size() < distances.size()) 
            {
                // create current vertex and set to null and smallestDistance to the impossibly high number.
                Vertex<TYPE>* current = nullptr;
                int smallestDistance = MAX_INT;
                
                // Find the vertex with the smallest distance
                for (auto& dist : distances) 
                {
                    if (visited.find(dist.first) == visited.end() && dist.second < smallestDistance) // if 
                    {
                        smallestDistance = dist.second;
                        current = dist.first;
                    }
                }
    
                if (current == nullptr) break;
    
                visited.insert(current);
                
                // Update distances to neighboring vertices
                for (Edge<TYPE>* edge : *fromEdges[current]) 
                {
                    Vertex<TYPE>* neighbor = edge->toVertex;
                    int weight = edge->weight;
                    int distanceThroughU = distances[current] + weight;
                    if (distanceThroughU < distances[neighbor]) 
                    {
                        distances[neighbor] = distanceThroughU;
                        predecessors[neighbor] = current;
                    }
                }
            }
            
            // Output the shortest path and its distance if possible
            if (distances[destination] != MAX_INT) 
            {
                cout << "Time to cross: " << distances[destination] << " minutes" << endl;
                vector<Vertex<TYPE>*> path;
                
                for (Vertex<TYPE>* at = destination; at != nullptr; at = predecessors[at]) 
                {
                    path.insert(path.begin(), at); // Insert at the beginning to reverse the path
                }
                
                for (Vertex<TYPE>* v : path) 
                {
                    cout << v->data << (v == destination ? "" : " -> ");
                }
                
                cout << endl;
            } 
            else 
            {
                cout << "No path exists!" << endl;
            }
        }
    
        vector<Vertex<TYPE>*> GetVertices() const 
        {
            vector<Vertex<TYPE>*> vertices;
            for (auto& keyValue : fromEdges) 
            {
                vertices.push_back(keyValue.first);
            }
            return vertices;
        }
    
        // Print the entire graph
        void PrintGraph() 
        {
            for (auto& keyValue : fromEdges) // sorts through every vertice
            {
                Vertex<TYPE>* vertex = keyValue.first; // gets the current vertex
                vector<Edge<TYPE>*>* edges = keyValue.second; // gets the vector containing every edge that leads from it
                if (edges->empty()) // if no edges are found
                {
                    cout << "Bike Stop " << vertex->data << " does not go anywhere." << endl;
                } 
                else // otherwise print the edges
                {
                    cout << "Bike Stop " << vertex->data << " has paths to:" << endl;
                    for (Edge<TYPE>* edge : *edges) 
                    {
                        cout << "  - Bike Stop " << edge->toVertex->data << ", takes " << edge->weight << " minutes to cross." << endl;
                    }
                }
            }
        }
};
