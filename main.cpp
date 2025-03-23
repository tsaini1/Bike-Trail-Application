#include <iostream>
#include "headers/MinHeap.h"
#include "headers/Graph.h"

using namespace std;

void PrintMenu(Vertex<string> *start);
Vertex<string> *GetChoice(Vertex<string> *start, Vertex<string> *routes[], Graph<string> trails);


int main() 
{ 
    Graph<string> trails;

    // Initializes vertexes
    Vertex<string> *alfa = trails.AddVertex("Alfa");
    Vertex<string> *bravo = trails.AddVertex("Bravo");
    Vertex<string> *charlie = trails.AddVertex("Charlie");
    Vertex<string> *delta = trails.AddVertex("Delta");
    Vertex<string> *echo = trails.AddVertex("Echo");
    Vertex<string> *foxtrot = trails.AddVertex("Foxtrot");
    Vertex<string> *golf = trails.AddVertex("Golf");
    Vertex<string> *hotel = trails.AddVertex("Hotel");
    
    // adds all vertexes to route for passing to helper functions
    Vertex<string> *routes[] = {alfa, bravo, charlie, delta, echo, foxtrot, golf, hotel};

    // creates directed and weighted graph.
    trails.AddDirectedEdge(alfa, bravo, 70);
    trails.AddDirectedEdge(alfa, golf, 40);
    trails.AddDirectedEdge(bravo, hotel, 50);
    trails.AddDirectedEdge(bravo, charlie, 50);
    trails.AddDirectedEdge(charlie, delta, 20);
    trails.AddDirectedEdge(charlie, echo, 45);
    trails.AddDirectedEdge(charlie, hotel, 30);
    trails.AddDirectedEdge(echo, delta, 40);
    trails.AddDirectedEdge(delta, foxtrot, 15);
    trails.AddDirectedEdge(foxtrot, charlie, 15);
    trails.AddDirectedEdge(foxtrot, echo, 20);
    trails.AddDirectedEdge(hotel, golf, 50);
    trails.AddDirectedEdge(hotel, alfa, 20);
    trails.AddDirectedEdge(golf, charlie, 60);

    Vertex<string>* start = nullptr;
    Vertex<string>* to = nullptr; 

    // Gets start, end, and prints the route and destination time.
    start = GetChoice(start, routes, trails);
    to = GetChoice(start, routes, trails);
    trails.DijkstraShortestPath(start, to);

    int placeholder;
    cin >> placeholder;

    return 0;
}

void PrintMenu(Vertex<string> *start) 
{
    cout << "[-----------Routes-----------]" << endl;
    cout << "\t 0. Print Graph" << endl;
    
    if (start == nullptr || start->data != "Alfa") 
        cout << "\t1. Alfa" << endl;
        
    if (start == nullptr || start->data != "Bravo") 
        cout << "\t2. Bravo" << endl;
        
    if (start == nullptr || start->data != "Charlie") 
        cout << "\t3. Charlie" << endl;
        
    if (start == nullptr || start->data != "Delta") 
        cout << "\t4. Delta" << endl;
        
    if (start == nullptr || start->data != "Echo") 
        cout << "\t5. Echo" << endl;
        
    if (start == nullptr || start->data != "Foxtrot") 
        cout << "\t6. Foxtrot" << endl;
        
    if (start == nullptr || start->data != "Golf") 
        cout << "\t7. Golf" << endl;
        
    if (start == nullptr || start->data != "Hotel") 
        cout << "\t8. Hotel" << endl;
        
    cout << "[----------------------------]" << endl;
}

// Function to get the user's choice of a start or end destination vertex from a list of routes.
// Parameters:      1) start: Pointer to the starting vertex, or nullptr if no start has been selected.
//                  2) routes: Array of pointers to Vertex representing possible destinations.
//                  3) trails: A Graph object representing the entire network.
Vertex<string> *GetChoice(Vertex<string> *start, Vertex<string> *routes[], Graph<string> trails) 
{
    int choice = 0;

    // prints menu based on if the user has selected a start point.
    if (start == nullptr) 
    {
        PrintMenu(nullptr);
    }
    else 
    {
        PrintMenu(start);
    }

    while (1) 
    {
        // prints appropriate text based on whether user has selected a start point.
        if (start == nullptr) cout << "Select Start Destination: ";
        else cout << "Select End Destination: ";
        cin >> choice;
        cout << endl;

        if (choice > 0 && choice < 9) 
            return routes[choice - 1];
        else if (choice == 0) 
        {
            trails.PrintGraph();
            cout << endl;    
        }
        else 
        {
            cout << "Invalid Input. Try again." << endl;
        }
    }
    
    exit(1);
}
