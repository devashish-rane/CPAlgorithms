#include<bits/stdc++.h>
using namespace std;



struct item {
    int key, prior;
    item * l, * r;
    
   item (int key, int prior) : key(key), prior(prior), l(NULL), r(NULL) { }
};
typedef item * pitem;

void split (pitem t, int key, pitem & l, pitem & r) {
    if (!t)
        l = r = NULL;
    else if (key < t->key)
        split (t->l, key, l, t->l),  r = t;
    else
        split (t->r, key, t->r, r),  l = t;
}

void insert (pitem & t, pitem it) {
    if (!t)
        t = it;
    else if (it->prior > t->prior)
        split (t, it->key, it->l, it->r),  t = it;
    else
        insert (it->key < t->key ? t->l : t->r, it);
}

void merge (pitem & t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
}

void erase (pitem & t, int key) {
    if (t->key == key)
        merge (t, t->l, t->r);
    else
        erase (key < t->key ? t->l : t->r, key);
}

pitem unite (pitem l, pitem r) {
    if (!l || !r)  return l ? l : r;
    if (l->prior < r->prior)  swap (l, r);
    pitem lt, rt;
    split (r, l->key, lt, rt);
    l->l = unite (l->l, lt);
    l->r = unite (l->r, rt);
    return l;
}

//return priority for number 
int search(pitem t,int key){
    if(!t ) return -1;
    if(t->key ==key) return t->prior;
    else{
        if(t->key  <= key)
          return search(t->r,key);
        else
          return search(t->l,key);  
    }
    
}

void inorder(pitem t){
    if(!t) return;
   inorder(t->l);
   cout<<t->key<<"  "<<t->prior<<"\n";
   inorder(t->r); 
}



int main(){
   //not sure about change in tree structure
    pitem root = new item(5,67);
    pitem n1 = new item(6,99);
    pitem n2 = new item(27,88);
    insert(root, n1);
    insert(root, n2);
    inorder(root);
    cout<<"finding 6 : "<<search(root,6);
    cout<<
    return 0;
}

