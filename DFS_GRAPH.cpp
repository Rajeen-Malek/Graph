#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
    map<int,list<int>> l;
    public :
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void dfs_helper(int src , map<int,bool> &visited)
    {
        //recursive function that will traverse the graph
        cout<< src <<" ";
        visited[src] = true;
        //go to all nbr of that is not visited
        for(T nbr : l[src])
        {
            if(!visited[nbr]){
                dfs_helper(nbr , visited);
            }
        }
    }
    void dfs(int src)
    {
        //queue <T> q;
        map <int,bool> visited;
        //mark all the nodes as not visited in begg
        for(auto p:l)
        {
            int node = p.first;
            visited[node] = false;
        }
        // call the helper fuction 
        dfs_helper(src,visited);
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(0,1);  // 1 2 3 4 5 6 output
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.dfs(0);
}