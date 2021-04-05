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

int n=100;
vector<int> seg(4*n+1);
vector<int> lazy(4*n+1,0);

//lb and ub are major bounds  of input array
void build(vector<int> a,int v,int lb,int ub){
    if(lb==ub) 
      seg[v]=a[lb];
     else{
       int mid= (lb+ub)/2;
       build(a,v*2,lb,mid);
       build(a,v*2+1,mid+1,ub);
       seg[v]= seg[v*2] + seg[v*2+1];
     } 
}

int sum(int v,int lb,int ub,int l,int r){
     if(l>r) return 0; //if out of upper or lower bound
     if(r==ub and l==lb)  return seg[v];   //found value the return seg
     
     int mid =  (ub + lb)/2;
     int p1 = sum(2*v, lb, mid, l, min(r,mid));
     int p2 = sum(2*v+1, mid+1, ub, max(l,mid+1), r);
    return (p1 + p2);
}

//NOTE : SIMPLE UPDATE HAS IF ELSE CONSTRUCT RANGE DOSENT HAVE IT
void update(int v,int lb,int ub,int pos ,int val){  //position for vertex "v"
     
     if(/*r==ub and l==lb*/lb==ub)  {
        seg[v]+= val;   //adding update
        //return;
        }
      else{    
        int mid =  (ub + lb)/2;
        if(pos <= mid )
        update(2*v, lb, mid, pos,val);
        else
        update(2*v+1, mid+1, ub, pos ,val);
        seg[v] = seg[v*2] + seg[v*2+1];  
      }
}

void lazyupdate(int v,int lb,int ub,int l,int r,int add){

    if(lazy[v] != 0)
    {  // This node needs to be updated
        seg[v] += (ub - lb + 1) * lazy[v];    // Update it
        if(lb != ub)
        { 
            lazy[v*2] += lazy[v];                  // Mark child as lazy
            lazy[v*2+1] += lazy[v];                // Mark child as lazy
        }
        lazy[v] = 0;                                  // Reset it
    }
 
     if(l>r) 
     return ; //if out of upper or lower bound

     if(ub>=r and l>=lb)  {
         // Segment is fully within range
        seg[v] += (ub - lb + 1) * add;
        if(lb != ub)
        {
            // Not leaf node
            lazy[v*2] += add;
            lazy[v*2+1] += add;
        }
        return;
        }
    
        int mid =  (ub + lb)/2;
        lazyupdate(2*v, lb, mid, l, min(r,mid),add);
        lazyupdate(2*v+1, mid+1, ub, max(l,mid+1), r,add);
        
        seg[v] = seg[v*2] +seg[v*2+1];
   
}

void rangeupdate(int v,int lb,int ub,int l,int r,int add){
        if(l>r) return ; //if out of upper or lower bound
     if(/*r==ub and l==lb*/lb==ub)  {
        seg[v]= seg[v]+add;   //adding update
        return;
        }
    
        int mid =  (ub + lb)/2;
        rangeupdate(2*v, lb, mid, l, min(r,mid),add);
        rangeupdate(2*v+1, mid+1, ub, max(l,mid+1), r,add);
        
        seg[v] = seg[v*2] +seg[v*2+1];
}

//update function is remaining

int main(){
    
   
   vector<int > a ={1,2,3,4,5,6,7,8,9};
   for(int i: a) cout<<i<<" ";
   cout<<"\n";
   build(a,1,0,8);
   for(int i=0;i<16;i++){
     cout<<seg[i]<<" ";
   }
   cout<<"\nMaking query\n";
   cout<<sum(1,0,8,0,4)<<"\n";    //vertex index is default 1
     lazyupdate(1,0,8,0,4,10);
   cout<<sum(1,0,8,0,4);    //vertex index is default 1
  return 0;
}



