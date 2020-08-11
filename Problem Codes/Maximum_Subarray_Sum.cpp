// Problem: https://cses.fi/problemset/task/1643
// First solution with Prefix Sums, keeping minimum Prefix Sum Index.
#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ll long long 

void fast(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
}


int main() {
   fast();
   
   int n;
   cin>>n;
   long long a[n+1];
   a[0]=0;
   for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=a[i-1];
   }
   
   long long ans=a[1]-a[0];
   int c=0;
   for(int i=1;i<=n;i++){
       if(a[i]>a[c]){
        ans=max(a[i]-a[c],ans);

       }else{
        ans=max(a[i]-a[c],ans);
        c=i;

       }
   }
   cout<<ans<<"\n";


}
// Another Solution Using Kadane's algo
