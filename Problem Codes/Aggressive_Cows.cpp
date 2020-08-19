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
int n,c;
long long int a[100000];
long long search(){
     long long l=0; long long r=a[n-1];
     while(l<r){
      long long mid=(l+r)/2;
      int k=1;
      int f=1;
      int i=0;
      int j;
       while(f && k<c){
        if(a[n-1]>=a[i]+mid){
           k++;
           f=1;
           j=lower_bound(a,a+n,a[i]+mid)-a;
           i=j;
        }else{
          f=0;
          break;
        }
       }
       if(k>=c){
          l=mid+1;
       }else{
        r=mid;
       }
    }
    if(r>0){
    return r-1;
    }
    return 0;
}
int main() {
   fast();
   int t;
   cin>>t;
   while(t--){
    cin>>n>>c;
    for(int i=0;i<n;i++){
      cin>>a[i];
    }
    sort(a,a+n);
    cout<<search()<<"\n";
   }
}
//Problem Link : https://www.spoj.com/problems/AGGRCOW/
