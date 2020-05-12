#include<bits/stdc++.h>
using namespace std;

int getWays(int coins[],int n,int m)
{
	if(n<0)
		return 0;
	if(n==0)
		return 1;

    int num=0;
	for(int i=0;i<m;i++)
	{
		num+=getWays(coins,n-coins[i],m);
	}
	return num;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,coins[50]={0};
	cin>>n>>m;

	for(int i=0;i<m;i++)
	{
		cin>>coins[i];
	}
	int num = getWays(coins,n,m);
	cout<<num<<endl;
	return 0;
}

