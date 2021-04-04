//Problem link:https://cses.fi/problemset/task/1140/
#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ll long long 
#define mod 1000000007 
#define mod2 998244353
void fast(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
}
struct point {
  ll int a,b,p;
};
const int mx=2e5+5;
vector<point> v;
ll dp[mx+1];
ll memo[mx+1];
vector<int> endi;
ll recurse(int c){
  if(memo[c]){
    return dp[c];
  }
  int d=lower_bound(endi.begin(),endi.end(),v[c].a)-endi.begin()-1;
  memo[c]=1;
  dp[c]=max(recurse(c-1),v[c].p+recurse(d));
  //cout<<dp[c]<<" "<<c<<"\n";
  return dp[c];
}

int main() {
   fast();
   int n;
   cin>>n;
   memo[0]=1;
   dp[0]=0;
   v.pb({(ll)0,(ll)0,(ll)0});
  
   endi.pb(0);
   for(int i=0;i<n;i++){
      ll int x,y,z;
      cin>>x>>y>>z;
      v.pb({x,y,z});
      endi.pb(y);
   }
   sort(v.begin(),v.end(),[](const point& x,const point& y){return x.b<y.b;});
   sort(endi.begin(),endi.end());
   cout<<recurse(n)<<"\n";
}
