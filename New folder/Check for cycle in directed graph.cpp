#include<bits/stdc++.h>
using namespace std;

bool checkcycle(int node,vector<int> adj[], int vis[],int dfvis[]){
    vis[node]=1;
    dfvis[node]=1;
    for(auto it :adj[node]){
        if(!vis[it]){
            if(checkcycle(it,adj,vis,dfvis)){
                return true;
            }
        }else if(dfvis[it]==1){
            return true;
        }
    }
    dfvis[node]=0;
    return false;
}

bool isCycle(vector<int> adj[],int n){
    int vis [n];
    int dfvis[n];
    memset(vis,0,sizeof vis);
    memset(dfvis,0,sizeof dfvis);
    for(int i=0;i<n;i++){
        if(!vis[i]){
        if(!checkcycle(i,adj,vis,dfvis)){
            return false;
        }
        }
    }
   return true;
}

int main(){

    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++){
    int u,v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    }

    if(isCycle(adj,n)){
        cout<<"yes";
    }
    else{
        cout<<"NO";
    }
    return 0;

}
