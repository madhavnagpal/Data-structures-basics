#include<bits/stdc++.h>
using namespace std;

void subsequences(string inp,int i,string out)
{
    //base
	if(i==inp.size())
	{
		cout<<out<<" ";
		return;
	}
	//recursive
	//exclude
	subsequences(inp,i+1,out);
	//include
	subsequences(inp,i+1,out+inp[i]);

	return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string inp;
    cin>>inp;
    subsequences(inp,0,"");
	cout<<endl;
	cout<<pow(2,inp.size())<<endl;
    return 0;
}
