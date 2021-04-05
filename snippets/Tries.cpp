#include<bits/stdc++.h>
using namespace std;

// A Trie node
struct Trie
{
	bool isLeaf=false;
	unordered_map<char, Trie*> map;
};

// Function that returns a new Trie node
Trie* getNewTrieNode()
{
	Trie* node = new Trie;

	return node;
}

// Iterative function to insert a string in Trie.
void insert(Trie*& head, char* str)
{
	if (head == nullptr)
		head = getNewTrieNode();

	// start from root node
	Trie* curr = head;
	while (*str)
	{
		// create a new node if path doesn't exists
		if (curr->map.find(*str) == curr->map.end())
			curr->map[*str] = getNewTrieNode();

		// go to next node
		curr = curr->map[*str];

		// move to next character
		str++;
	}

	// mark current node as leaf
	curr->isLeaf = true;
}

// returns true if given node has any children
bool haveChildren(Trie const* curr)
{
	// don't use (curr->map).size() to check for children

	for (auto it : curr->map)
		if (it.second != nullptr)
			return true;

	return false;
}

// Recursive function to delete a string in Trie.
bool deletion(Trie*& curr, char* str)
{
	// return if Trie is empty
	if (curr == nullptr)
		return false;

	// if we have not reached the end of the string
	if (*str)
	{
		// recur for the node corresponding to next character in
		// the string and if it returns true, delete current node
		// (if it is non-leaf)
		if (curr != nullptr &&  curr->map.find(*str) != curr->map.end() &&
			deletion(curr->map[*str], str + 1) && curr->isLeaf == false)
		{
			if (!haveChildren(curr))
			{
				delete curr;;
				curr = nullptr;
				return true;
			}
			else {
				return false;
			}
		}
	}

	// if we have reached the end of the string
	if (*str == '\0' && curr->isLeaf)
	{
		// if current node is a leaf node and don't have any children
		if (!haveChildren(curr))
		{
			delete curr;; // delete current node
			curr = nullptr;
			return true; // delete non-leaf parent nodes
		}

		// if current node is a leaf node and have children
		else
		{
			// mark current node as non-leaf node (DON'T DELETE IT)
			curr->isLeaf = false;
			return false;	   // don't delete its parent nodes
		}
	}

	return false;
}

// Iterative function to search a string in Trie. It returns true
// if the string is found in the Trie, else it returns false
bool search(Trie* head, char* str)
{
	// return false if Trie is empty
	if (head == nullptr)
		return false;

	Trie* curr = head;
	while (*str)
	{
		// go to next node
		curr = curr->map[*str];

		// if string is invalid (reached end of path in Trie)
		if (curr == nullptr)
			return false;

		// move to next character
		str++;
	}

	// if current node is a leaf and we have reached the
	// end of the string, return true
	return curr->isLeaf;
}

// Memory efficient Trie Implementation in C++ using Map
int main()
{
	Trie* head = nullptr;

	insert(head, "hello");
	cout << search(head, "hello") << " ";   	// print 1

	insert(head, "helloworld");
	cout << search(head, "helloworld") << " ";  // print 1

	cout << search(head, "helll") << " ";   	// print 0 (Not present)

	insert(head, "hell");
	cout << search(head, "hell") << " ";		// print 1

	insert(head, "h");
	cout << search(head, "h") << endl;  		// print 1 + newline

	deletion(head, "hello");
	cout << search(head, "hello") << " ";   	// print 0 (hello deleted)
	cout << search(head, "helloworld") << " ";  // print 1
	cout << search(head, "hell") << endl;   	// print 1 + newline

	deletion(head, "h");
	cout << search(head, "h") << " ";   		// print 0 (h deleted)
	cout << search(head, "hell") << " ";		// print 1
	cout << search(head, "helloworld") << endl; // print 1 + newline

	deletion(head, "helloworld");
	cout << search(head, "helloworld") << " ";  // print 0
	cout << search(head, "hell") << " ";		// print 1

	deletion(head, "hell");
	cout << search(head, "hell") << endl;   	// print 0 + newline

	if (head == nullptr)
		cout << "Trie empty!!\n";   			// Trie is empty now

	cout << search(head, "hell");   			// print 0

	return 0;
}




//faster version of tries
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int count;
    struct node *index[26];
    int end;
};
struct node *create()
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    for(int i=0;i<26;i++)
    {
        temp->index[i]=NULL;
    }
    temp->count=0;
    temp->end=0;
    return temp;
}
void insert(struct node *root, string s)
{
    struct node *temp=root;
    for(int i=0;i<s.length();i++)
    {
        if(temp->index[s[i]-'a']==NULL)
            temp->index[s[i]-'a']=create();
        
        temp=temp->index[s[i]-'a'];
        (temp->count)+=1;
    }
    temp->end=1;
}
int countIt(struct node *root,string s)
{
    int i=0;
    struct node *temp=root;
    while(i<s.length())
    {
        if(temp->index[s[i]-'a']==NULL)
            return 0;
        temp=temp->index[s[i]-'a'];
        i++;
    }
    return(temp->count);
}
int main()
{
    struct node *root=create();
    int i,n;
    cin>>n;
    string op,str;
    while(n--)
    {
        cin>>op>>str;
        if(op=="add")
        {
            insert(root,str);
        }
        else
        {
            cout<<(countIt(root,str))<<endl;
        }
    }
    
    return 0;
}