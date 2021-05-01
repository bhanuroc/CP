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
int main() {
   fast();
   int n;
   cin>>n;
   ll int a[n+1];
   ll int c[n+1];
   ll int d[n+1];
   a[0]=0;
   c[0]=0;
   d[0]=0;
   ll ans=n;
   for(int i=1;i<=n;i++){
    cin>>a[i];
    c[i]=a[i];
    c[i]+=c[i-1];
    d[i]=(d[i-1]^a[i]);
    //cout<<c[i]<<"\n";
   }
   vector<pair<int,int>> v;
   v.pb({0,0});
   for(int i=1;i<=n;i++){
   	 int l=i+1;
   	 int r=n;
   	 int final=i;
   	 while(l<=r){
   	 	int mid=(l+r)/2;
   	 	if(((d[mid]^d[i-1]))==c[mid]-c[i-1]){
   	 		final=mid;
   	 		l=mid+1;
   	 	}else{
   	 		r=mid-1;
   	 	}
   	 }
   	 v.pb({i,final});
   }
   
   for(int i=1;i<v.size();i++){
   	 int tocho=v[i].second-v[i].first+1; // to choose from
   	 int neg=max(v[i-1].second-v[i].first+1,0); // contributing to pairs which counted in last iteration
   	 ans+=((ll)(tocho)*(ll)(tocho-1))/2-((ll)(neg)*(ll)(neg-1))/2;
   	 //cout<<tocho<<" "<<neg<<" "<<"\n";
   }
   cout<<ans<<"\n";
}
// Problem: https://atcoder.jp/contests/arc098/tasks/arc098_b
/* Idea- The idea is to binary search for every index till where the bits are distinct for the segment. Store everything as segments and then see intersections and combinations 
you can make. */
