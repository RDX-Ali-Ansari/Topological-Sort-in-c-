#include "AdjList.h"
#include <iostream>
#include <queue>
#include <string>
using namespace std;

AdjList::AdjList()
{
    //Nothing Special Has Been Done Here.
}

AdjList::AdjList(int VerA) : noOfVertices(VerA)
{
    //AdjList();
    //Adj is pointing to the array of Lists.
    adj = new List*[noOfVertices];
    for(int i=0;i<noOfVertices;i++)
        {
            //Declaring as NULL.
            adj[i]=NULL;
        }
}

void AdjList::addEdge(int src, int des)
{
    //Creating a new Node.
    List* newNode=new List;

    //Initializing the vertex value.
    newNode->vertex=des;

    //Adding a new node at the head of specified array of list index.
    newNode->next=adj[src];
    adj[src]=newNode;
}

void AdjList::InDegree(void)
{
    for(int i=0;i<noOfVertices;i++)
     {
         //Finding In Degree of all the vertices.
         List* node=adj[i];
         while(node!=NULL)
         {
             //Setting In Degree values for nodes.
             InDegreeOfVertices[node->vertex]+=1;
             node=node->next;
         }
     }
}

void AdjList::TopologicalSort()
{
     InDegree();
     int flag=0;
     queue<int> Q;

     //Checking which vertex has zero InDegree.
     if(flag!=1)
     {
         for(int i=0;i<noOfVertices;i++)
         {
             if(InDegreeOfVertices[i]==0)
                //Pushing the vertex which has zero InDegree.
                Q.push(i);
         }
     }


     while (!Q.empty())
     {
        int vertex=Q.front();
        Q.pop();
        cout<<"|"<<NameOfVertices[vertex]<<"|"<<" -> ";

        // Populating the array of Lists to initialize the value of degree.
        List* node=adj[vertex];
        while (node!=NULL)
        {
            InDegreeOfVertices[node->vertex]-=1;
            if (InDegreeOfVertices[node->vertex]==0)
                Q.push(node->vertex);
            node=node->next;
        }
     }
    cout<<endl;
}

void AdjList::PrintVertices()
{
    cout<<"Vertices Of The Graph Are.\n";
    for(int i=0;i<noOfVertices;i++)
    {
        cout<<"|"<<NameOfVertices[i]<<"|"<<" ";
    }
    cout<<endl;
}

AdjList::~AdjList()
{
    //Freeing the memory.
    delete[] adj;
}
