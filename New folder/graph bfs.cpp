#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,m;
cin>>n>>m;
vector<int>a[n+1];
for(int i=0;i<m;i++)
{
    int u,v;
cin>>u>>v;
a[u].push_back(v);
a[v].push_back(u);
}

vector<int>bfs;
vector<int>vis(n+1,0);
for(int i=1;i<=n;i++)
{
if(vis[i]==0)
{
queue<int>q;
q.push(i);
vis[i]=1;
while(!q.empty())
{
int node=q.front();
q.pop();
bfs.push_back(node);
for(auto i:a[node])
{
if(vis[i]==0)
{
q.push(i);
vis[i]=1;
}
}
}
}
}
for(int i=0;i<bfs.size();i++)
{
cout<<bfs[i]<<" ";
}
}
