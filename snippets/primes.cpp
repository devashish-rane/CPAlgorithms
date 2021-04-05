#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

//segmented sieve without prime generation (returns boolean array for range  [useful for  ranges]  )
vector<bool> segmentedSieveNoPreGen(long long L, long long R) {
    vector<bool> isPrime(R - L + 1, true);
    long long lim = sqrt(R);
    for (long long i = 2; i <= lim; ++i)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}


//prime factorization wheels algorithm sqrt(v)  [root]
vector<long long> trial_division2(long long n) {
    vector<long long> factorization;
    while (n % 2 == 0) {
        factorization.push_back(2);
        n /= 2;
    }
    for (long long d = 3; d * d <= n; d += 2) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}




//seive extra space complexity linear time complexity  bound 10e8  [generate actual values in array ]
const int N = 10000000;
int lp[N+1];
vector<int> pr;
void spfSieve(){
  for (int i=2; i<=N; ++i) {
      if (lp[i] == 0) {
          lp[i] = i;
          pr.push_back (i);
      }
      for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
          lp[i * pr[j]] = pr[j];
  }
}


//space optimized sieve [n.loglogn]    bound 10e8
int n;
vector<bool> is_prime(n+1, true);
void sieve(){
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= n; i++) {
      if (is_prime[i]) {
          for (int j = i * i; j <= n; j += i)
              is_prime[j] = false;
      }
  }
}




//standalone primality check   [complexity sqrt(n)]
bool isPrime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

//----------------------------------------------------------------------------
//assist for rabin miller
using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

//rabin miller primality test    [k.log^3m  , k= constand => number of rounds]
bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}



//-----------------------------------------------------------------------
// gcd may use builtin __gcd
long long gcd(long long a,long long b){
  while(b){
    a=a% b;
    swap(a,b);
  }
  return a;
}
//multiplier
long long mult(long long a, long long b, long long mod) {
    return (__int128)a * b % mod;
}

//dont know function
long long f(long long x, long long c, long long mod) {
    return (mult(x, x, mod) + c) % mod;
}

//pollard's rho algorithms Brent implementation for single prime factorization
long long brent(long long n, long long x0=2, long long c=1) {
    long long x = x0;
    long long g = 1;
    long long q = 1;
    long long xs, y;

    int m = 128;
    int l = 1;
    while (g == 1) {
        y = x;
        for (int i = 1; i < l; i++)
            x = f(x, c, n);
        int k = 0;
        while (k < l && g == 1) {
            xs = x;
            for (int i = 0; i < m && i < l - k; i++) {
                x = f(x, c, n);
                q = mult(q, abs(y - x), n);
            }
            g = gcd(q, n);
            k += m;
        }
        l *= 2;
    }
    if (g == n) {
        do {
            xs = f(xs, c, n);
            g = gcd(abs(xs - y), n);
        } while (g == 1);
    }
    return g;
}


int main() {
    
    // vector<bool> a= segmentedSieveNoPreGen(11,48);
    
    // for(int i=0;i<a.size();i++){
    //     if(a[i]){
    //         cout<<i+11<<"\n";
    //     }
    // }
    cout<<MillerRabin(1000000007)<<"\n";
    cout<<MillerRabin(1000000005);
    return 0;
}
