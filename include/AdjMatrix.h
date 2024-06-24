#ifndef ADJMATRIX_H
#define ADJMATRIX_H
#include <string>
using namespace std;
class AdjMatrix
{
    public:
        AdjMatrix();
        //Initializing the matrix to zero
        AdjMatrix(int noOfVertices);
        void addEdge(int r,int c);
        virtual ~AdjMatrix();
        void BFS(int vertexId);
        void Path(int path[]);
        void PrintVertices();

    private:
        string NameOfVertices[15]={"PIEAS","Chirah","Thanda Paani","Mohara","Ali Pur","Pindi Begwal","Taramari","Jagiot","Athal","Chatta Bakhtawar","Malot","Bhara Kahu","Kuri","Chak Shahazad","Bani Gala"};
        int** Matrix;
        int noOfVertices=10;
};
#endif // ADJMATRIX_H
