 //finding distinct elements standerd Mo's algorithm
 #include<bits/stdc++.h>
 using namespace std;
 int n=10000000; 
vector<int> space(n,0);
vector<int > h(1000000); //upto limit of integers
//block size 
int block  = (int ) sqrt(n);


 struct Q{
     int l,r,id=0;
    //  Q(int l,int r){
    //      this->l = l;
    //      this->r = r;
    //  }

     bool operator< (const Q a){
         if(l != a.l)
             return l/block  < a.l/block;
         return r/block < a.r/block;    
     }
 };


int q_n=10000;
vector<Q> queries(n);

 

//adding and removing function changes for different problems
int del(int pos)
{
	h[space[pos]]--;
	if(h[space[pos]]==0)
		return -1;
	return 0;
}
 
int add(int pos)
{
	h[space[pos]]++;
	if(h[space[pos]]==1)
		return 1;
	return 0;
}



vector<int> mo_s(vector<Q> queries) {
    //for storing answers for queries
    vector<int> answers(queries.size());
    
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure
    int sum=0;

    int cur_l = 0;      //indicate 0-based indexing
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Q q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            //perform add operation and assing result to sum variable for final answers
            add(cur_r);
        }
        while (cur_l < q.l) {
            del(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            //perform remove operation and assing result to sum variable for final answers
            del(cur_r);
            cur_r--;
        }
        answers[q.id] = sum; 
    }
    return answers;
}
 int main(){

     return 0;
 }