#include<bits/stdc++.h>
using namespace std;

int dp[50][250];
int n,num;
vector<int> coins;

int solve(int pos,int n)
{
	int &res = dp[pos][n];
	if(res!=-1)
		return res;
	if(n==0)
		return 1;
	if(pos==num)
		if(n) return 0;
		else return 1;
	//not inc pos
	res = 0;
	res = solve(pos+1,n);
	if(n>=coins[pos])
	{
		res += solve(pos,n-coins[pos]);
	}
	return res;
}

int main() {
	cin>>n>>num;
	for(int i=0;i<num;i++)
	{
		int data;
		cin>>data;
		coins.push_back(data);
	}
	for(int i=0;i<100;i++)
		for(int j=0;j<500;j++)
			dp[i][j] = -1;
	cout<<solve(0,n)<<endl;
	return 0;
}
