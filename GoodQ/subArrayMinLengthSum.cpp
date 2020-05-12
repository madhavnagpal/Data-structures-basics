// I am Nothing , You Are Nothing
// Jai Shree Krishna

#include<bits/stdc++.h>
using namespace std;
#define int long long
void letsStart();

int minLength(int *a,int n,int k){

	int num=0;
	int *sum = new int[n];
	for(int i=0;i<n;i++)
	{
		num += a[i];
		sum[i] = num;
	}
	int ans = INT_MAX;

	deque<pair<int,int>> q;
	q.push_back({-1,0});

	for(int i=0;i<n;i++)
	{
		while(!q.empty() && sum[i]-q.front().second>=k)
		{
			ans = min(ans,i-q.front().first);
			q.pop_front();
		}
		while(!q.empty() && sum[i]<= q.back().second)
		{
			q.pop_back();
		}
		q.push_back({i,sum[i]});

	}
	if(ans==INT_MAX) return -1;
	return ans;

}

int32_t main()
{
	letsStart();
	int n;
	cin>>n;
	int *a = new int[n];
	for(int i=0;i<n;i++) 
		cin>>a[i];
	int k;
	cin>>k;

	cout<<minLength(a,n,k)<<endl;

	return 0;
}

void letsStart()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("out2.txt","w",stdout);
	#endif
}
