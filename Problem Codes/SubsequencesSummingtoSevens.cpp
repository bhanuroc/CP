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
    setIO("div7");
    int n;
    cin>>n;
    long long a[n+1];
    a[0]=0;
    for(int i=1;i<=n;i++){
      cin>>a[i];
      a[i]+=a[i-1];
    }
    long long b[n+1];
    for(int i=0;i<=n;i++){
      b[i]=a[i]%7;
    }
    int ans=0;
    int c[7]={-1,-1,-1,-1,-1,-1,-1};
    int d[7]={-1,-1,-1,-1,-1,-1,-1};

    for(int i=0;i<7;i++){
      for(int j=0;j<=n;j++){
        if(b[j]==i){
          c[i]=j;
          break;
        }
      }
      for(int j=n;j>=0;j--){
        if(b[j]==i){
          d[i]=j;
          break;
        }
      }
    }
    for(int i=0;i<7;i++){
      if(d[i]!=-1 && c[i]!=-1){
         ans=max(ans,d[i]-c[i]);
      }
    }
    cout<<ans;


}
// http://www.usaco.org/index.php?page=viewproblem2&cpid=595
/* Problem Explanation: We have an array and we need to think of the longest contiguous subarray having the sum of elements divisible by 7. Suppose we have a subarray {l,r},
   (a[r]-a[l-1])%7 should be equal to 0, where array a is converted to its sum of prefixs array. So , we need to just check this for 7 remainders, i.e. 0,1,2,3,4,5,6.
   */


