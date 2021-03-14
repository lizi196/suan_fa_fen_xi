#include<iostream>
#include<cmath>
#include <iomanip>
#include<cstring>
#include<string>
#include<vector>
 
using namespace std;
 
#define MAX_INT 999999

pair<int,int> GetShortestEdge(const vector<vector<int> >& Graph, const vector<bool>& isIncluded )
{
    int minID = -1;
    int minDist = MAX_INT;
    pair<int,int> minEdge;
    for(int i = 0; i < Graph.size(); i++)
    {
        if(!isIncluded[i]) continue;
        for(int j = 0; j < Graph.size(); j++) 
            if(!isIncluded[j] && Graph[i][j] < minDist){
                minID = j;
                minDist = Graph[i][j];
                minEdge = make_pair(i,j);
            }
    }
    return minEdge;
}
vector<pair<int,int> > Prim(const vector<vector<int> >& Graph, vector<bool>& isIncluded){
    vector<pair<int,int> > MST;
    isIncluded[0] = true;

    for(int i = 1; i < Graph.size(); i++){
        pair<int,int> minEdge = GetShortestEdge(Graph, isIncluded); 
        MST.push_back(minEdge); 
        isIncluded[minEdge.second] = true; 
    }
    return MST;
}
 
void addEdge( const int& startP, const int& endP, const int& weight ,vector<vector<int> >& Graph)
{
    Graph[startP][endP] = weight;
    Graph[endP][startP] = weight;
}
 
int main()
{
    int vertex_num = 6;
    vector<vector<int> > Graph(vertex_num, vector<int>(vertex_num, MAX_INT));
    addEdge(0,1,1 ,Graph);
    addEdge(0,2,2 ,Graph);
    addEdge(0,3,3 ,Graph);
    addEdge(1,2,4 ,Graph);
    addEdge(1,4,5 ,Graph);
    addEdge(2,3,6 ,Graph);
    addEdge(2,4,7 ,Graph);
    addEdge(2,5,8,Graph);
    addEdge(3,5,9,Graph);
    addEdge(4,5,9,Graph);
    vector<bool> isIncluded(vertex_num, false);
    vector<pair<int,int> >  MST = Prim(Graph, isIncluded);
    for(int i = 0; i < MST.size(); i++) 
        cout << MST[i].first << "->" << MST[i].second << endl;
    return 0;
}

