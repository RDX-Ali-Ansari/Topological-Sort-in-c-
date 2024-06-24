#include <iostream>
#include <AdjMatrix.h>
#include <AdjList.h>
#include<iomanip>
using namespace std;

int main()
{
    AdjMatrix M(15);
    //Calling addEdge function multiple times to add edges.
    M.addEdge(0,1);
    M.addEdge(0,2);
    M.addEdge(0,3);
    M.addEdge(2,4);
    M.addEdge(3,5);
    M.addEdge(4,6);
    M.addEdge(4,7);
    M.addEdge(5,7);
    M.addEdge(5,8);
    M.addEdge(6,9);
    M.addEdge(7,10);
    M.addEdge(8,10);
    M.addEdge(8,11);
    M.addEdge(9,12);
    M.addEdge(9,13);
    M.addEdge(10,12);
    M.addEdge(11,14);
    M.addEdge(13,14);
    M.PrintVertices();

    cout<<right<<setw(90)<<"==============================\n";
    cout<<right<<setw(90)<<"Path from source to every node\n";
    cout<<right<<setw(90)<<"==============================\n";
    cout<<endl;
    //BFS Traversing the graph for Node '0' (PIEAS) using BFS algorithm.
    M.BFS(0);

    //Calling parametrized constructor to initialize all values of the matrix to zero.
    AdjList G(15);

    //Adding edges to the vertices whose are adjacent.
    G.addEdge(0,1);
    G.addEdge(0,2);
    G.addEdge(0,3);
    G.addEdge(2,4);
    G.addEdge(3,5);
    G.addEdge(4,6);
    G.addEdge(4,7);
    G.addEdge(5,8);
    G.addEdge(6,9);
    G.addEdge(7,5);
    G.addEdge(8,11);
    G.addEdge(9,12);
    G.addEdge(9,13);
    G.addEdge(10,8);
    G.addEdge(11,14);
    G.addEdge(12,10);
    G.addEdge(13,14);

    cout<<endl;
    cout<<right<<setw(90)<<"==============================\n";
    cout<<right<<setw(90)<<"Path Found By Topological Sort\n";
    cout<<right<<setw(90)<<"==============================\n";
    cout<<endl;
    //BFS Traversing the graph for Node '0' (PIEAS) using BFS algorithm.
    G.TopologicalSort();


    return 0;
}
