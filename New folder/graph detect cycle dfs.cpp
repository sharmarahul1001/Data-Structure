#include<bits/stdc++.h>
using namespace std;
bool checkcycle(int node,int parent,vector<int>&vis,vector<int>a[])
{
vis[node]=1;
for(auto i:a[node])
{
if(vis[i]==0)
{
if(checkcycle(i,node,vis,a))
{
return true;
}

}
else if(i!=parent)
{
    return true;
}
}
return false;
}
bool iscycle(vector<int>a[],int n)
{
vector<int>vis(n+1,0);
for(int i=0;i<n;i++)
{
if(vis[i]==0)
{
if(checkcycle(i,-1,vis,a))
{
return true;
}
}
}
return false;
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
if(iscycle(a,n))
{
    cout<<"present";
}
else
{
    cout<<"Not present";
}
}
