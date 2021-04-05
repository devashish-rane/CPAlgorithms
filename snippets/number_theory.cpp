  #include<bits/stdc++.h>
  using namespace std;

  //debugging functions
  #define show(x)               cout<<"\n"<<"showing... :"<<x<<"\n";
  #define _log                  cout<<"\niterated through\n";


  //iterators macros
  #define loop(i,a,b)           for(int i=(int)a;i<(int)b;++i)
  #define loopeq(i,a,b)          for(int i=(int)a;i<=(int)b;++i)
  #define loopll(i,a,b)          for(ll i=(ll)a;i<(ll)b;++i)
  #define loopr(i,a,b)          for(int i=(int)a;i>=(int)b;--i)


  //utilities macros
  #define pb                    push_back
  #define F                     first
  #define S                     second
  #define mp                    make_pair
  #define M                   1000000007
  #define MAX                   INT_MAX
  #define MIN                   INT_MIN

  //data structures macros
  #define ll                    long long int
  #define pll                   pair<ll,ll>
  #define pii                   pair<int,int>   
  #define vi                    vector<int>
  #define vpii                  vector<pii>
  #define vvi                   vector<vi>      //unweighted graph    [Adj list]
  #define vvi                   vector<vpii>      //weighted graph     [Adj list]
  #define mat(r,c)              vector<vi> mat((r),vector<int> ((c)));

  #define all(p)                p.begin(),p.end()
  #define mid(s,e)              (s+(e-s)/2)

  #define tcs()            int t; scanf("%d",&t); while(t--)


// int main(){
  
// }








//eulars totient function [square root n]   standalone
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}


//eulars totient function [phi]  upto n    [complexity= n.log logn ]
void phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

//fibonacii matrix based  returns {Fn , Fn+1}  using fast doubling method  [alternative binary matrix exponentation ]
pair<int, int> fib (int n) {
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    int c = p.first * (2 * p.second - p.first);
    int d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}




//when only mod is prime   [Fermat's little theorem] [log m]
int modInverse(int A,int mod=M)
{
    return powmod(A,mod-2,mod);
}



// When A and mod are coprimes  [log n]   [which is usually possible for 10^9 +7 ]
int d,x,y;
int modInverse(int A, int mod=M)
{
    extendedEuclid(A,mod);
    return (x%mod+mod)%mod;    //x may be negative
}



//recursive algorithm
/*extended euclids for coprimes A and B  [x is multiplicative modulo inverse for A modulo B,
                                          y is multiplicative modulo inverse for B modulo A]
                                          d is GCD  */
int d, x, y;   //[log n]
void extendedEuclid(int A, int B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}






//get GCD
int gcd(int a,int b){
    if(b==0)   //2nd param is taken modulo of   [swapping of param
      return a;
    return gcd(b ,a % b);
}





//non recursive 
int gcdnonrc(int a,int b){
  while(b){
    a=a% b;
    swap(a,b);
  }
  return a;
}






//lcm = a*b  /gcd()
int lcm (int a, int b) {
    return a / gcdnonrc(a, b) * b;
}





//function for modulo bases binary exponentation
ll powmod(ll a,ll n,ll mod = M){
  a=a % mod;  //consdering integer limits
  ll res = 1;
  while(n>0){
    if(n & 1) res = res*a   % mod;
    a=a*a  % mod;
    n>>=1;
  }
   return res;
}
