#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin>>n;
    long long x;
    cin>>x;

    long long a[n+1];
    a[0]=0;
    for(int i=1;i<=n;i++){
       cin>>a[i];
       a[i]+=a[i-1];
       
    }
    
    map<long long int,long long int> m;
    long long int ans=0;
    
    
    for(int i=0;i<=n;i++){
       if(m[a[i]]){
           ans+=m[a[i]];
           m[x+a[i]]++;
           
       }else{
           m[x+a[i]]++;
          
           
       }
    }
    
    
    cout<<ans<<"\n";

    
}
//Problem Link: https://cses.fi/problemset/task/1661/

  
