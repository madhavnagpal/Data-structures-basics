// I am Nothing , You Are Nothing
// Jai Shree Krishna

// Learning Trie

#include<bits/stdc++.h>
using namespace std;
#define int long long
void letsStart();

class node
{
public:
	char data;
	bool isTerminal;
	unordered_map<char,node*> h;
	node(char d)
	{
		data=d;
		isTerminal=false;
	}
};

class trie
{
public:
	node *root;
	trie()
	{
		root = new node('\0');
	}
	void addWord(string inp)
	{
		node *temp = root;
		for(int i=0;inp[i]!='\0';i++)
		{
			if(!temp->h.count(inp[i]))
			{
				temp->h[inp[i]] = new node(inp[i]);
			}
			temp = temp->h[inp[i]];
		}
		temp->isTerminal = true;
	}

	bool searchWord(string inp)
	{
		node *temp = root;
		for(int i=0;inp[i]!='\0';i++)
		{
			if(!temp->h.count(inp[i]))
			{
				return false;
			}
			temp = temp->h[inp[i]];
		}
		if(temp->isTerminal)
			return true;
		else
			return false;
	}

};

int32_t main()
{
	letsStart();
	trie t;
	t.addWord("hello");
	t.addWord("code");
	t.addWord("welcome");
	t.addWord("world");
	int n;
	cin>>n;
	string check;
	while(n--)
	{
		cin>>check;
		if(t.searchWord(check))
			cout<<"Found"<<endl;
		else
			cout<<"Not found"<<endl;
	}
	return 0;
}

void letsStart()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
