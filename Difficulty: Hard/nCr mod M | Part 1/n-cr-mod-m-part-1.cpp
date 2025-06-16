class Solution {
long long mod = 1000003;

long long bin_expo(long long a, long long b){
   long long ans = 1;
   while (b>0){
       if (b & 1)
           ans = (ans *a)%mod;
       a = (a*a)%mod ;
       b = b / 2;
   }
   return ans;
}

long long mod_inverse(long long a){
   return bin_expo(a,mod-2);
}

long long fermat(long long n, long long r){
       
   if (n < r)
       return 0;
       
   if(r==0 || n==r)
       return 1;
   
   if(r==n-1 || r==1)
       return n;
   
   
   long long fact[n + 1];
   fact[0] = 1;
   for (long long i = 1; i <= n; i++)
       fact[i] = (fact[i - 1] * i) % mod;
   
   
   long long a = fact[n];
   long long b = mod_inverse(fact[r]);
   long long c = mod_inverse(fact[n-r]);
   
   return ((a*b)%mod * c%mod)%mod;
   
}

long long lucas(long long n, long long r){
  if (r==0)
     return 1;
     
  long long ni = n%mod, ri = r%mod;
  
  return (lucas(n/mod, r/mod) * 
          fermat(ni, ri)) % mod;  
}
public:
   long long nCr(long long n, long long r) {
       return lucas(n,r);
   }
};