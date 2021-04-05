#include<bits/stdc++.h>
using namespace std;

//debugging functions
#define db(x)               cout<<"\nvar "<<#x<<" : "<<x<<"\n";
#define lg                  cout<<"\niterated through\n";


 //iterators macros //try to avoid such macros
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
#define EPS                   1e-9
#define ll                    long long 
#define pll                   pair<ll,ll>
#define pii                   pair<int,int>   
#define v_i                    vector<int>
#define v_pii                  vector<pii>

#define v_v_i                   vector<v_i>      //unweighted graph    [Adj list]
#define v_v_pii                   vector<v_pii>      //weighted graph     [Adj list]
#define mat(r,c)              vector<v_i> mat((r),vector<int> ((c)));

#define all(p)                p.begin(),p.end()
#define mid(s,e)              (s+(e-s)/2)


//unsigned large numbers

#define u128                  __uint128_t     // 1e38
#define  bignum               vector<int>    //take input as string and then run convertion functions for bignum
const int base = 1000*1000*1000;       // Used in AP arithmatics

//tuple 
#define f(tuple)                        get<1>(tuple)
#define s(tuple)                        get<2>(tuple)
#define t(tuple)                        get<3>(tuple)
//NOTE : tie(a,b,c) =tuple works + only one way to input tuple is make_tuple


/* -------------------  start ----------------------*/
 
#if DEBUG && !ONLINE_JUDGE

    #define debug(args...)     (Debugger()) , args
 
    class Debugger
    {
        public:
        Debugger(const std::string& _separator = ", ") :
        first(true), separator(_separator){}
        
        template<typename ObjectType>
        Debugger& operator , (const ObjectType& v)
        {
            if(!first)
                std::cerr << separator;
            std::cerr << v;
            first = false;
            return *this;
        }
        ~Debugger() {  std::cerr << endl;}
        
        private:
        bool first;
        std::string separator;
    };
 
    template <typename T1, typename T2>
    inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
    {
        return os << "(" << p.first << ", " << p.second << ")";
    }
 
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
    {
    	
        bool first = true;
        os << "[";
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if(!first)
                os << ", ";
            os << v[i];
            first = false;
        }
        return os << "]";
    }
 
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::set<T>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
        {
            if(!first)
                os << ", ";
            os << *ii;
            first = false;
        }
        return os << "]";
    }
 
    template<typename T1, typename T2>
    inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
        {
            if(!first)
                os << ", ";
            os << *ii ;
            first = false;
        }
        return os << "]";
    }
    
#else

    #define debug(args...)                  // Just strip off all debug tokens
    
#endif

#define dbg(name) printer(#name, (name))  //name is in c style string

void printer(string name, auto value) {
    cout<<name<<" : ";
    debug(value);
}
 
/*-------------------------------Stop ---------------------------------*/

int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0); 
//    cout.tie(0);
    
    freopen("input1.txt", "r", stdin); 
//    freopen("output1.txt", "w", stdout);  
    
//    freopen("input2.txt", "r", stdin); 
//    freopen("output2.txt", "w", stdout);  
    
    
	string s;
	cin>>s;
	vector<int > v={1,34,5,6,7};
	map<int ,vector<int> > h;
	h[1].push_back(23);
	h[1].push_back(233);
	h[1].push_back(2344);
		cout<<s<<"\n";
	dbg(h);
	

	return 0;
    
}
