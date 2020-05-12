#include<bits/stdc++.h>
using namespace std;

int denom[100]={0};
int dp[1000]={0};

int n,m;

int ways(int n)
{
	if(n<0)
		return 0;
	//already calculated
	if(dp[n]!=-1)
		return dp[n];
	// rec
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		sum += ways(n-denom[i]);
	}
	dp[n]=sum;
	return sum;
}

int main() {
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>denom[i];
    dp[0]=1;
    for(int i=1;i<1000;i++)
	    dp[i]=-1;


	cout<<ways(n)<<endl;
	return 0;
}
