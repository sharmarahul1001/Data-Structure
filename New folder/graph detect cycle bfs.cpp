#include<bits/stdc++.h>
using namespace std;
bool checkcycle(int s,int n,vector<int>a[],vector<bool>&vis)
{
 queue<pair<int,int>>q;
 vis[s]=true;
 q.push({s,-1});
 while(!q.empty())
 {
int node=q.front().first;
int p=q.front().second;
q.pop();
for(auto i: a[node])
{
    if(vis[i]==0)
    {
        vis[i]=true;
        q.push({i,node});
    }
    else if(i!=p)
    {
        return true;
    }
}
 }
 return false;

}
bool iscycle(int n,vector<int>a[])
{
    vector<bool>vis(n+1,0);
for(int i=0;i<n;i++)
{
    if(vis[i]==0)
    {
        if(checkcycle(i,n,a,vis))
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
if(iscycle(n,a))
{
cout<<"present";
}
else{
cout<<"not present";
}
return 0;
}
