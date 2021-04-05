/*String processing and mattern matching algorithms*/

#include<bits/stdc++.h>
using namespace std;

//string hashing  [polynomial rolling hash function] --base for rabin karp  
//NOTE : return value must be long long as prime + previous hash value may cross int limit
long long prhf(string s){
   long long hash=0; //as summation
   const int prime = 31; //for A-Z and a-z use prime = 53
   int m = 1e9+7;     //can also use 1e9+9
   long long prime_power=1;  //0th power is 1;

   for(int i=0;i<s.length();i++){
	   hash = hash + (  (s[i]-'a' + 1) *prime_power  ) % m;    /*as cant use 0 for avoiding hash collision*/
	   prime_power = (prime_power * prime) % m;
   }
   return hash;
}



//rabin karp
vector<int> rabinKarp(string text,string patt){
	vector<int > occ;
	//text hash array is made
	vector<long long > text_hash(text.length()+1,0);  //1 based indexing for [initial case senario]

	const int prime = 31;
	long long  prime_power=1;
    const int m = 1e9+7;
	
	//making the hash array for the text
	for(int i=0;i<text.length();i++){
		text_hash[i+1] = ( text_hash[i] +  (text[i]-'a' +1 ) * prime_power  ) % m;
		
		prime_power = ( prime_power * prime ) % m;
	}

	//prhf value for pattern;
	long long patt_hash =  prhf(patt);
	int p_len = patt.length();
    
	//reinitialize
    prime_power=1;
	for(int i=0;i+p_len <= text.length();i++ ){
	   long long curr_window = (text_hash[i+p_len] + m /*fucking m is very necessary*/- text_hash[i] ) % m;
       
	   //condition for occurance
	   if(curr_window == patt_hash * prime_power % m)    //left to right precidence
	   	        occ.push_back(i+1);
       prime_power = ( prime_power * prime ) % m;
	}
	return occ;  //return occurnace index 1 bases [standerd]
} 


//prefix function   -- base for KMP [Knuth -Morris-Pratt]
vector<int> prefixArray(string s){
	vector<int > prefix (s.length(),0);  // prefix[0] sets pointer for start==0
    
	for(int i=1;i<s.length();i++){
		int j = prefix[i-1];  //previous match of the prefix

		while(j>0 && s[j]!=s[i]){ //prefix mismatch
			j=prefix[j-1];
		}
		if(s[j]==s[i]) j++;

		prefix[i]=j;
	}
	return prefix;
}
//KMP
vector<int> KMP(string text,string patt){
	vector<int> occ;
	vector<int> prefix = prefixArray(patt);
    
	// cout<<"prefix: ";
	// for(auto i :prefix) cout<<i<<" ";
	// cout<<"\n";		
	int i=0,j=0;
	while(i<text.length()){
		if(text[i]==patt[j]){
			j++;i++;
		}
		if(patt.length()==j)  {
			occ.push_back(i-j +1);
			j = prefix[j - 1];   //jump backword after finding string
		}
		else if(i<text.length() && patt[j]!=text[i]){
			if(j!=0) j=prefix[j-1];  //jump backward
			else i+=1;  //skip current and try next letter
		}
		
	}
	return occ;
}
//Z function
vector<int> zfunction(string s){
   vector<int > z(s.length());

   for(int i=1,l=0,r=0;i<s.length();i++){
	   if(i <= r) z[i]=min(r-i+1,z[i-l/*no the l not 1*/]);    //inside the right bound => find the min partition

	   while(i+ z[i]< s.length() && s[z[i]]==s[z[i]+i]){   //trivial method for incrementing the z value
          z[i]++;
	   }

	   if(i+z[i]-1 > r) l=i,r=i+z[i]-1;
   }
   return z;
}

//Lyndon factoriziation
vector<string> duval(string s) {
    int n = s.size();
    int i = 0;
    vector<string> factorization;
    while (i < n) {
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j]) {
            if (s[k] < s[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k) {
            factorization.push_back(s.substr(i, j - k));
            i += j - k;
        }
    }
    return factorization;
}

//Manchester Algorithms for Longest palindromic substring  //not done

	
int main(){
    cout<<prhf("hello")<<"\n";
   cout<<prhf("deva")<<"\n";


   vector<int > one = rabinKarp("mynameisdevashish","devashish");
   vector<int > two = rabinKarp("mynameisdevashish","h");
   for(auto i:one) cout<<"devashsish "<<i<<" ";
   cout<<"\n";
   for(auto i:two) cout<<"h "<<i<<" ";
   cout<<"\n---------------\n";

    one = KMP("mynameisdevashish","devashish");
    two = KMP("mynameisdevashish","h");
   for(auto i:one) cout<<"devashsish "<<i<<" ";
   cout<<"\n";
   for(auto i:two) cout<<"h "<<i<<" ";


   cout<<"\nZ-Function : \n";
   vector<int>  v = zfunction("abacaba");
  
   for(auto i:v) cout<<i<<" ";     //O/P : [0,0,1,0,3,0,1]

   cout<<"\n";
   vector<string> f =duval("abacabab");
   for(auto i:f) cout<<i<<" ";

}