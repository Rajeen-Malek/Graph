#include<bits/stdc++.h>
using namespace std;

bool isCyclic_helper(vector <int> adj[] , vector <bool> visited , int curr )
{
    if(visited[curr] == true)
    {
        return true;
    }
    visited[curr] = true;
    bool flag = false;
    for(int nbr : adj [curr])
    {
        flag = isCyclic_helper(adj , visited , nbr);
        if(flag==true)
        {
            return true;
        }
    }
    return false;
}

bool isCyclic(int V , vector <int> adj[])
{
    vector <bool> visited(V,false);     //inittialised the visited array of v size with false 
    bool flag =false;
    for(int i=0 ; i<V ; i++)
    {
        visited[i] = true;
        for(int nbr : adj[i])
        {
            flag = isCyclic_helper(adj , visited , nbr);
            if(flag == true)
            {
                return true;
            }
        }
        visited[i] = false;
    } 
    return false;
}

int main()
{
    int e,v;    // e:number of the edges  and v:the number of vertices
    cin>>e>>v;
    vector <int> adj[v] ;

    for(int i=0 ; i<e ;i++)
    {
        int u,w;
        cin>>u >>w;
        adj[u].push_back(w);
    } 
    if(isCyclic(v,adj))
    {
        cout<<"THE CYCLE IS  PRESENT IN THE GRAPH\n";
    }
    else{
        cout<<"NO CYCLE IS PRESENT IN THE GRAPH\n";
    }
    return 0;
}