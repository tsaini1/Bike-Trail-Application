#include <iostream>
//#include <unordered_set>
#include "headers/MinHeap.h"
#include "headers/Graph.h"
using namespace std;

// int main() {
//     MinHeap test;
//     test.insert(3);
//     test.insert(10);
//     test.insert(15);
//     test.insert(27);
//     test.insert(36);
//     test.insert(17);
//     test.printHeap();
//     cout << endl;
//     cout << test.extractMin() << endl;
//     test.printHeap();
//     test.insert(3);
//     cout << endl;
//     test.printHeap();
    
//     // this creates a graph, but need to figure out how to get graph and print it out.
//     // this code, and code in Graph.h was grabbed from zybooks.
//     Graph<string> test2;
//     Vertex<string> *vertex1 = test2.AddVertex("1");
//     Vertex<string> *vertex2 = test2.AddVertex("2");
//     Vertex<string> *vertex3 = test2.AddVertex("3");
//     Vertex<string> *vertex4 = test2.AddVertex("4");
//     Vertex<string> *vertex5 = test2.AddVertex("5");

//     test2.AddDirectedEdge(vertex1, vertex2, 8);
//     test2.AddDirectedEdge(vertex1, vertex3, 12);
//     test2.AddDirectedEdge(vertex1, vertex4, 17);
//     test2.AddDirectedEdge(vertex2, vertex5, 11);
//     test2.AddDirectedEdge(vertex5, vertex3, 23);
//     test2.AddDirectedEdge(vertex3, vertex4, 15);
//     test2.AddDirectedEdge(vertex5, vertex4, 6);

//     // Print the graph structure
//     test2.PrintGraph();
    
//     cout << "Finding shortest path from 1 to 4:" << endl;
//     test2.DijkstraShortestPath(vertex1, vertex4);

//     cout << "Finding shortest path from 1 to 5:" << endl;
//     test2.DijkstraShortestPath(vertex1, vertex5);
    
//     int placeholder;
//     cin >> placeholder;

//     return 0;
// }
