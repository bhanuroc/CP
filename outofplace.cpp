
// Out of place USACO Sorting greedy

#include<bits/stdc++.h>
using namespace std;
using ll =long long;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define fi first
#define sc second
#define mp make_pair

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin); // see Input & Output
        freopen((name+".out").c_str(), "w", stdout);
    }
}


int main() {
    setIO("outofplace");
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
      cin>>a[i];
    }
    int f=0;
    int g=-1;
    int h;
    if(a[0]>a[1]){
      f=1;
      g=0;
      h=1;
    }
    
    for(int i=1;i<n;i++){
      if( i!=n-1 && a[i]>a[i+1]){
        f=1;
        g=i;
        h=1;
        break;
      }
      if(a[i]<a[i-1]){
        f=1;
        g=i;
        h=0;
        break;
      }
    }
    
    if(f){
      int l=0;
      vector<int> v;
      v.push_back(a[0]);
      for(int i=1;i<n;i++){
        if(a[i]!=a[i-1] && i!=g){
          v.push_back(a[i]);
        }
      }
      if(h==0){
      for(int i=0;i<v.size();i++){
        if(v[i]>a[g]){
          l++;
        }
      }
      }else{
        for(int i=0;i<v.size();i++){
        if(v[i]<a[g]){
          l++;
        }
      }
      }
      cout<<l;
    }else{
      cout<<0;
    }
    


  
  
  
  
  
}
