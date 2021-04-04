#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ll long long 
#define mod 1000000007 
void fast(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
}
void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin); // see Input & Output
        freopen((name+".out").c_str(), "w", stdout);
    }
}
vector<int> adj[2001];
int dp[2001][2001];
int value[2001];
int used[2001];
int n,m,c;

int main() {
   //fast();
  setIO("time");
   cin>>n>>m>>c;
   for(int i=0;i<n;i++){
    cin>>value[i];
   }
   for(int i=0;i<m;i++){
     int u,v;
     cin>>u>>v;
     --u;--v;
     adj[u].pb(v);
   }
   for(int i=0;i<=1000;i++){
    for(int j=0;j<n;j++){
        if(j==0 || dp[j][i]!=0){
      for(int u:adj[j]){
        dp[u][i+1]=max(dp[u][i+1],dp[j][i]+value[u]);
      }
        }
    }
   }
   long long int ans=0;
   for(int i=0;i<=2000;i++){
      ans=max(dp[0][i]-(ll)c*((ll)i*i),ans);
      //cout<<i<<" "<<dp[0][i]<<"\n";
   }
   cout<<ans<<"\n";
}
// Problem link: http://www.usaco.org/index.php?page=viewproblem2&cpid=993
