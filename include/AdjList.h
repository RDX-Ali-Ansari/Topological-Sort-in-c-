#ifndef ADJLIST_H
#define ADJLIST_H
#include <string>
using namespace std;

struct List
{
    int vertex;
    int degree=0;
    List* next;
};

class AdjList
{
    public:
        AdjList();
        AdjList(int VerA);
        void addEdge(int src, int des);
        void TopologicalSort();
        void InDegree(void);
        void PrintVertices();
        virtual ~AdjList();

    private:
      string NameOfVertices[15]={"PIEAS","Chirah","Thanda Paani","Mohara","Ali Pur","Pindi Begwal","Taramari","Jagiot","Athal","Chatta Bakhtawar","Malot","Bhara Kahu","Kuri","Chak Shahazad","Bani Gala"};
      int InDegreeOfVertices[15]={0},noOfVertices;
      List** adj;
};
#endif // ADJLIST_H
