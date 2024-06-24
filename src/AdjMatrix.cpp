#include "AdjMatrix.h"
#include <iostream>
#include <queue>
#include <string>
#include<iomanip>

using namespace std;

AdjMatrix::AdjMatrix()
{
    //Nothing Special Has Been Done Here.
}

AdjMatrix::AdjMatrix(int noOfVertices)
{
    AdjMatrix();
    //Initializing the no of vertices.
    this->noOfVertices=noOfVertices;

    //Matrix is pointing to the array of pointers to strings.
    Matrix = new int*[noOfVertices];

    //Matrix[i] is now pointing to the array of strings for i-th row.
    for(int i=0;i<noOfVertices;i++)
        Matrix[i] = new int[noOfVertices];

    //Initializing all the entries in the matrix to zero.
     for(int i=0;i<noOfVertices;i++)
            for(int j=0;j<noOfVertices;j++)
                   Matrix[i][j]=0;

}

void AdjMatrix::addEdge(int r,int c)
{
    //Initializing the Matrix[c][r] and Matrix[c][r] to 1 which indicates that an edge exists between r and c.
    Matrix[r][c]=1;
    Matrix[c][r]=1;
}

void AdjMatrix::BFS(int vertexId)
{
    queue<int> Q;
    int path[noOfVertices];
    bool flag[noOfVertices];

    //Initializing the visited table entries to false and recording the path.
    for(int i=0;i<noOfVertices;i++)
    {
        flag[i]=false;
        path[i]=-1;
    }

    //Declaring that we've visited the source node.
    flag[vertexId]=true;
    Q.push(vertexId);
    while(!Q.empty())
    {
        //Dequeueing the element to find its adjacent vertices.
        vertexId=Q.front();
        Q.pop();
        cout<<"|"<<NameOfVertices[vertexId]<<"|"<<" -> ";

        //Finding all adjacent vertices for vertice specified with "vertexId".
        for(int i=0;i<noOfVertices;i++)
        {
            //Checking adjacent vertices has been visited or not?
            if(i!=vertexId && Matrix[vertexId][i]==1 && flag[i]!=true)
            {
                flag[i]=true;

                //Storing the path.
                path[i]=vertexId;

                //Pushing the vertice on queue.
                Q.push(i);
            }
        }
    }
    cout<<endl;
}

void AdjMatrix::PrintVertices()
{
    cout<<"\n"<<setw(90)<<"============================\n";
    cout<<setw(90)<<"Vertices Of The Graph Are.\n";
    cout<<setw(90)<<"============================\n";
    cout<<"\n";
    for(int i=0;i<noOfVertices;i++)
    {
        cout<<"|"<<NameOfVertices[i]<<"|"<<" ";
    }
    cout<<endl;
}

AdjMatrix::~AdjMatrix()
{
    //Nothing is required here.
}
