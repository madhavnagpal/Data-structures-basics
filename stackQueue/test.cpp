#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define vi vector<int>
void c_p_c()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

int32_t main()
{
	c_p_c();
	int a[100000]={0};
	int n,n1,n2;
	cin>>n>>n1>>n2;
	//stack1
	for(int i=0;i<n1;i++)
		cin>>a[i];
	//stack2
	for(int i=n-1;i>=n-n2;i--)
		cin>>a[i];
	//pop 1 elements
	int top1=n1-1,top2=n-n2;

	cout<<a[top1]<<endl;
	top1--;
	cout<<a[top2]<<endl;
	top2++;
	cout<<"Elements in stack1 are"<<endl;
	for(int i=top1;i>=0;i--)
		cout<<a[i]<<" ";
	cout<<"\nElements in stack2 are"<<endl;
	for(int i=top2;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}



