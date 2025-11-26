#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void addEdge(vector<pair<int,int>> graph[], int u, int v, int w, bool undirected=true){
    graph[u].push_back({v,w});
    if(undirected) graph[v].push_back({u,w});
}

void bfs(int start, vector<int> graph[], int n){
    vector<bool> visited(n,false);
    queue<int> q;
    visited[start]=true;
    q.push(start);

    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(int nb: graph[node]){
            if(!visited[nb]){
                visited[nb]=true;
                q.push(nb);
            }
        }
    }
}

void dfs(int node, vector<int> graph[], vector<bool> &visited){
    visited[node]=true;
    cout<<node<<" ";
    for(int nb: graph[node]){
        if(!visited[nb]){
            dfs(nb,graph,visited);
        }
    }
}

int findParent(int x, vector<int> &parent){
    if(parent[x]==x) return x;
    return parent[x]=findParent(parent[x],parent);
}

void unite(int a, int b, vector<int> &parent, vector<int> &rank){
    a=findParent(a,parent);
    b=findParent(b,parent);
    if(a!=b){
        if(rank[a]<rank[b]) swap(a,b);
        parent[b]=a;
        if(rank[a]==rank[b]) rank[a]++;
    }
}

void kruskal(int n, vector<pair<int,pair<int,int>>> &edges){
    sort(edges.begin(), edges.end());
    vector<int> parent(n), rank(n,0);
    for(int i=0;i<n;i++) parent[i]=i;

    for(auto e: edges){
        int w=e.first;
        int u=e.second.first;
        int v=e.second.second;

        if(findParent(u,parent)!=findParent(v,parent)){
            unite(u,v,parent,rank);
            cout<<u<<" "<<v<<" "<<w<<endl;
        }
    }
}

void prim(int start, vector<pair<int,int>> graph[], int n){
    vector<bool> visited(n,false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});

    while(!pq.empty()){
        auto x=pq.top();
        pq.pop();
        int w=x.first, node=x.second;
        if(visited[node]) continue;
        visited[node]=true;
        cout<<node<<" "<<w<<endl;

        for(auto nb: graph[node]){
            if(!visited[nb.first]){
                pq.push({nb.second, nb.first});
            }
        }
    }
}

void dijkstra(int start, vector<pair<int,int>> graph[], int n){
    vector<int> dist(n,1e9);
    dist[start]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});

    while(!pq.empty()){
        auto x=pq.top();
        pq.pop();
        int d=x.first, node=x.second;
        if(d!=dist[node]) continue;

        for(auto nb: graph[node]){
            int v=nb.first, w=nb.second;
            if(dist[node]+w < dist[v]){
                dist[v]=dist[node]+w;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<i<<": "<<dist[i]<<endl;
    }
}

int main(){
    int n,e;
    cin>>n>>e;

    vector<pair<int,int>> graphW[n];
    vector<int> graphU[n];

    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        addEdge(graphW,u,v,w,true);
        graphU[u].push_back(v);
        graphU[v].push_back(u);
    }

    return 0;
}
