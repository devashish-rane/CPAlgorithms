//convert string to C style array
string s;
cin>>s;
char str = new char[s.size()+1]; //for "\n"
strcpy(str,s.c_str());

//making modulo for -ive and +ive
(x % N + N) %N;

//diff between double and long double 
long double is more accurate than only double [consist of 80 bytes vs 64 bytes]


//floating compare
//In practice, the numbers can be compared as follows (ε = 10−9 ):
if (abs(a-b) < 1e-9) {
// a and b are equal
}


//fast array scan
 int n;
   vi v(n,0);

   loop(i,0,n)
      cin>>v[i];
   
     

//to lower whole strign
     #include<bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    // su is the string which is converted to uppercase 
    string su = "Jatin Goyal"; 
  
    // using transform() function and ::toupper in STL 
    transform(su.begin(), su.end(), su.begin(), ::toupper); 
    cout << su << endl; 
  
    // sl is the string which is converted to lowercase 
    string sl = "Jatin Goyal"; 
  
    // using transform() function and ::tolower in STL 
    transform(sl.begin(), sl.end(), sl.begin(), ::tolower); 
    cout << sl << endl; 
  
    return 0; 
}


arr.erase(unique(arr.begin(),arr.end()),arr.end()) – This erases the duplicate occurrences in sorted vector in a single line.


//stringstream
for cin 


//debug for bitmagic
 cout<<std::bitset<32>(n).to_string()<<"\n";
                cout<<std::bitset<32>(fl).to_string()<<"\n";