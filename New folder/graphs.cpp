#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>&vis,vector<int>a[],vector<int>&storedfs)
{
    storedfs.push_back(node);
    vis[node]=1;
    for(auto i : a[node])
    {
        if(vis[i]==0)
        {
            dfs(i,vis,a,storedfs);
        }
    }
}
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
//--------printing the list------------
//for(int i=0;i<n;i++)
//{
//for(auto x: a[i])
//{
//cout<<x<<" ";
//}
//cout<<"\n";
//}
  vector<int>storedfs;
  vector<int>vis(n+1,0);
  for(int i=0;i<n;i++)
  {
      if(vis[i]==0)
      {
          dfs(i,vis,a,storedfs);
      }
  }
for(int i=1;i<storedfs.size();i++)
{
    cout<<storedfs[i]<<" ";
}
return 0;
}
