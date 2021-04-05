//multiplication /division /Addition /Substraction
#include<bits/stdc++.h>
using namespace std;


#define  bignum              vector<int>
const int base = 1000*1000*1000;

int main(){
    // short value can be long long int
     string num1 = "123456789";
    bignum a;
    
    string num2 = "1234567867545456745";    
    bignum b;
    
    //input for base 10^9  num1
    for (int i=(int)num1.length(); i>0; i-=9)
    if (i < 9)
        a.push_back (atoi (num1.substr (0, i).c_str()));
    else
        a.push_back (atoi (num1.substr (i-9, 9).c_str()));
     //-------------------

     //input for base 10^9 num2
    for (int i=(int)num2.length(); i>0; i-=9)
    if (i < 9)
        b.push_back (atoi (num2.substr (0, i).c_str()));
    else
        b.push_back (atoi (num2.substr (i-9, 9).c_str()));
     //-------------------

    //  //Adding 2 bignum values
    //  int carry = 0;
    // for (size_t i=0; i<max(a.size(),b.size()) || carry; ++i) {
    //     if (i == a.size())
    //         a.push_back (0);
    //     a[i] += carry + (i < b.size() ? b[i] : 0);
    //     carry = a[i] >= base;
    //     if (carry)  a[i] -= base;
    // }
    // //--------------------------


    // //subtraction of 2 bignum 
    // /*int*/  carry = 0;
    // for (size_t i=0; i<b.size() || carry; ++i) {
    //     a[i] -= carry + (i < b.size() ? b[i] : 0);
    //     carry = a[i] < 0;
    //     if (carry)  a[i] += base;
    // }
    // while (a.size() > 1 && a.back() == 0)
    //     a.pop_back();
    // //-----------------------    


    // //multiply by long integer
    // bignum c (a.size()+b.size());  //assigned size
    // for (size_t i=0; i<a.size(); ++i)
    //     for (int j=0, carry=0; j<(int)b.size() || carry; ++j) {
    //         long long cur = c[i+j] + a[i] * plier /*or use constll [23ll]*/ * (j < (int)b.size() ? b[j] : 0) + carry;
    //         c[i+j] = int (cur % base);
    //         carry = int (cur / base);
    //     }
    // while (c.size() > 1 && c.back() == 0)
    //     c.pop_back();

    // //---------------------

    //multiply by short integer
    int carry = 0;
    int plier = 12;
    for (size_t i=0; i<a.size() || carry; ++i) {
        if (i == a.size())
            a.push_back (0);
        long long cur = carry + a[i] * 1ll * plier;   //NOTE : multiplier is managed over here not the base unlike division
        a[i] = int (cur % base);
        carry = int (cur / base);
    }
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
    //----------------------
    

    //division by short integer  [less than specified base]    NOTE : no long division is available
    int isor = 12;
    /*int*/ carry = 0;
    for (int i=(int)a.size()-1; i>=0; --i) {
        long long cur = a[i] + carry * 1ll * base;    //NOTE : similer steps for division operations
        a[i] = int (cur / isor);
        carry = int (cur % isor);
    }
    while (a.size() > 1 && a.back() == 0)       
        a.pop_back();
    //------------------------



     //outputting bignum value 
     printf ("%d", a.empty() ? 0 : a.back());
    for (int i=(int)a.size()-2; i>=0; --i)
        printf ("%09d", a[i]);
    cout<<"\n";    
     //-------------------   
    //   //outputting bignum value 
    //  printf ("%d", c.empty() ? 0 : c.back());
    // for (int i=(int)c.size()-2; i>=0; --i)
    //     printf ("%09d", c[i]);
    //  //-------------------   

    return 0;
}