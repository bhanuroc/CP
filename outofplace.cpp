//http://www.usaco.org/index.php?page=viewproblem2&cpid=785
// Sorting and greedy Problem 
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
    //setIO("outofplace");
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
      if( i!=n-1 && a[i]>a[i+1] && a[i-1]<a[i+1]){
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
      
      if(h==0){
          if(a[0]>a[g]){
              l++;
          }
      for(int i=1;i<g;i++){
        if(a[i]>a[g] && a[i]!=a[i-1]){
          l++;
        }
      }
      }else{
        for(int i=g+1;i<n;i++){
        if(a[i]<a[g] && a[i]!=a[i-1]){
          l++;
        }
      }
      }
      cout<<l;
    }else{
      cout<<0;
    }
    


  
  
  
  
  
}
  
    






  
  
  



