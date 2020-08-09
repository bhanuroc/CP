#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define ll long long 
 
bool sortbysec(pair<int,int> a,pair<int,int> b){
    return a.f<b.f;
}
void fast(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
}
 
int main() {
   fast();
   int n;
   cin>>n;
   vector<pair<int,int>> v;
   for(int i=0;i<n;i++){
    int l,r;
    cin>>l>>r;
    v.pb({l,r});
   }
   sort(v.begin(),v.end(),sortbysec);
   priority_queue<int,vector<int>,greater<int>> pq;  // Use of Reverse Priority queue
   int ans=1;
   for(int i=0;i<n;i++){
         
       while(!pq.empty() && pq.top()<v[i].f){
          
        pq.pop();
       }
       pq.push(v[i].s);
       
       ans=max(ans,(int)pq.size());
       
 
   } 
   cout<<ans<<"\n"; 
 
}
