//Don't forget to call precompute in the main function
const int N=1e6;
long long fact[N], invfact[N];

long long pow(long long a,long long b,long long m)
{
  long long ans=1;
  while(b)
  {
    if(b&1)
      ans=(ans*a)%m;
    b/=2;
    a=(a*a)%m;
  }
  return ans;
}

long long modinv(long long k)
{
  return pow(k, mod-2, mod);
}

void precompute()
{
  fact[0]=fact[1]=1;
  for(long long i=2;i<N;i++)
  {
    fact[i]=fact[i-1]*i;
    fact[i]%=mod;
  }
  invfact[N-1]=modinv(fact[N-1]);
  for(long long i=N-2;i>=0;i--)
  {
    invfact[i]=invfact[i+1]*(i+1);
    invfact[i]%=mod;
  }
}

long long nCr(long long x,long long y)
{
  if(y>x)
    return 0;
  long long num=fact[x];
  num*=invfact[y];
  num%=mod;
  num*=invfact[x-y];
  num%=mod;
  return num;
}
