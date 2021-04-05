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
#define vvpi                   vector<vpii>      //weighted graph     [Adj list]
#define mat(r,c)              vector<vi> mat((r),vector<int> ((c)));

#define all(p)                p.begin(),p.end()
#define mid(s,e)              (s+(e-s)/2)

#define tcs()            int t; scanf("%d",&t); while(t--)

 struct Fenwick{
   vector<int>  bit;
   Fenwick(vector<int> a){
       bit.assign( (int) a.size(),0);
       for(int i=1;i<=a.size();i++ ) 
       update(i,a[i-1]);
   }

   void update(int index,int val){
     for(  index++ ; index<(int)bit.size() ; index +=(index & -index) )
        bit[index]+=val;
   }

   int sum(int i){
     //from 1 to i
     int sum=0;
     for( i++  ; i>0 ;  i-=( i & -i ))
        sum+=bit[i];
     return sum;
   }

   int rsq(int l,int r){
     return sum(r)-sum(l-1);
   }
   
    void rangeupdate(int l, int r, int val) {   // [point query range updates] used for adding values and then finding the values at the index 
        update(l, val);
        update(r + 1, -val);
    }

 };//finishing struct Fenwick


//2D fenwick tree for queries 
struct FenwickTree2D {
    vector<vector<int>> bit;
    int n, m;

    // init(...) { ... }

    int sum(int x, int y) {
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

    void add(int x, int y, int delta) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
    }
};

int main(){
  vector<int> a={1,2,3,4,5,6,7,8,9};
  Fenwick fwk = Fenwick(a);
  cout<<fwk.sum(4)<<"\n";
  fwk.rangeupdate(1,3,3);
  cout<<fwk.sum(4)<<"\n";
return 0;
}



