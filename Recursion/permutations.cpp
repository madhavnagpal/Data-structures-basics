#include<bits/stdc++.h>
using namespace std;

void permutations(string inp,string out,int i)
{
	//base
	if(i==inp.length())
	{
		cout<<out<<endl;
		return;
	}
	//recursive
	for(int j=i;inp[j]!='\0';j++)
	{
	    if(i!=j && inp[i]==inp[j])
            continue;
		swap(inp[i],inp[j]);
		permutations(inp,out+inp[i],i+1);
		swap(inp[i],inp[j]);
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string inp,out="";
	cin>>inp;
	//sort(inp.begin(),inp.end());
	permutations(inp,out,0);
	return 0;
}
