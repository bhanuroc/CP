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
stack<int> path;
vector<int> ans;
const int mx=100005;
vector<int> adj[mx];
bool vis[mx];
bool dfs(int cn,int p){
  if(vis[cn]){
    ans.pb(cn);
    while(path.top()!=cn){
      ans.pb(path.top());path.pop();
    }
    ans.pb(cn);
    return true;
  }
  vis[cn]=true;
  path.push(cn);
  for(auto nn:adj[cn]){
    if(nn!=p){
      if(dfs(nn,cn)){
        return true;
      }
    }
  }
  path.pop();
  return false;
}
 
int main() {
   fast();
   int n,m;
   cin>>n>>m;
   for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    --u;--v;
    adj[u].pb(v);
    adj[v].pb(u);
   }
   for(int i=0;i<n;i++){
      if(!vis[i]){
        if(dfs(i,-1)){
          cout<<sz(ans)<<"\n";
          for(int j=0;j<sz(ans);j++){
            cout<<ans[j]+1<<" ";
          }
          return 0;
        }
      }
   }
   cout<<"IMPOSSIBLE"<<"\n";
}
