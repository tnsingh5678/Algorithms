#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int parent[N];
int com_size[N];

void make(int v){
    parent[v] = v;
    com_size[v] = 1;
}

int find(int v){
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

void Union(int u,int v){
    int a = find(u);
    int b = find(v);

    if(a != b){
        if(com_size[a] < com_size[b]){
            swap(a,b);
        }
        parent[b] = a;
        com_size[a] += com_size[b];
    }
}

int main(){
    int n , m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> edges(n + 1);
    for(int i = 1; i <= n ; i++){
        make(i);
    }
    for(int i = 1;i <= m; i++){
        int u , v , w;
        cin >> u >> v >> w;
        edges[u].push_back({v , w});
        edges[v].push_back({u , w});
    }
    
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    for(int i = 1; i <= n ;i++){
        for(auto j : edges[i]){
           int v = j.first; 
           int w = j.second;
           pq.push({w , {i , v}});
        }
    }

    int total_wt = 0;
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int w = p.first;
        int u = p.second.first;
        int v = p.second.second;
        if(find(u) == find(v)) continue;
        Union(u , v);
        total_wt += w;
    }

    cout << "Total weight of Minimum spannin tree is : " << total_wt << endl;
}