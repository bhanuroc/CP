#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    long long a[n+1];
    a[0]=0;
    for(int i=1;i<=n;i++){
      cin>>a[i];
      a[i]+=a[i-1];
    } 
    long long cnt[n];
    for(int i=0;i<n;i++){
      cnt[i]=0;
    }
    for(int i=1;i<=n;i++){
      a[i]=(a[i]%n+n)%n;  // for negatives fixing modulo
    }
    for(int i=0;i<=n;i++){
      cnt[a[i]]++;
    }
    long long sum=0;
    for(int i=0;i<n;i++){
      sum+=(cnt[i]*(cnt[i]-1))/2;
    }
    cout<<sum<<endl;

    
}
// Just some modulo operation, prefix sum and combinations.
//  Problem Link : https://cses.fi/problemset/task/1662/


