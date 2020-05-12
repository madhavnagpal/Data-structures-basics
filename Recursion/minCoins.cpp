#include<bits/stdc++.h>
using namespace std;

int getWays(int coins[],int n,int m,int dp[])
{
	if(n<0)
		return 0;
	if(n==0)
		return 1;
	if(dp[n]!=0)
		return dp[n];

	for(int i=0;i<m;i++)
	{
		dp[n]+=getWays(coins,n-coins[i],m,dp);
	}
	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,coins[50]={0};
	cin>>n>>m;
	int *dp = new int[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i]=0;
	}
	dp[0]=1;
	for(int i=0;i<m;i++)
	{
		cin>>coins[i];
	}
	int num = getWays(coins,n,m,dp);
	cout<<num<<endl;
	return 0;
}
