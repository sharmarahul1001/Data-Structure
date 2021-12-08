#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int N = 1e3+2;
int dp[N][N];

int lcs(string &x ,string &y ,int n,int m){

    if(n ==0|| m==0){
        return 0;
    }

    if(dp[n][m] !=-1){
        return dp[n][m];
    }

    if(x[n-1] == y[m-1]){
        dp[n][m]= 1+ lcs(x,y,n-1,m-1);
    }
    else{
        dp[n][m] = max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
    }

   return dp[n][m];
}



int main(){

rep(i,0,N){
 rep(j,0,N)
  dp[i][j] =-1;
}


string x,y;
cin>>x>>y;

int n = x.size();
int m = y.size();

cout<<lcs(x,y,n,m)<<endl;
return 0;
}
