#include<bits/stdc++.h>
using namespace std;

template<typename T>                  //defined as generic class type
class Graph {
    map<int,list<int>> l;             //created the adjecency list

public:
    void addEdge(int x, int y) {
        l[x].push_back(y);           //bidirected graph edges
        l[y].push_back(x);
    }
    void bfs (int src) {
        map<int ,int> visited;      //map to mark visited element
        queue<int> q;               //queue to store visited elements

        q.push(src);                //pushing the source node inside queue to initialize it
        visited[src] = true;        //marking the visited node as true

        while(!q.empty())           //iterate till the queue is not empty
        {
            int node = q.front();
            q.pop();
            cout<<node<<"-";

            for(int nbr : l[node]){
                if(!visited[nbr])   //if the node is node visited !
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.bfs(0);
}