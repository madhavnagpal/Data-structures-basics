#include<bits/stdc++.h>
using namespace std;

char maze[1001][1001];
int path[1001][1001]={0};

bool isSafe(int i,int j)
{
	if(maze[i][j]=='O')
		return true;
    return false;
}

bool rat(int i,int j,int n,int m)
{
	//base
	if(i<1 || j<1)
        return false;
	if(i==n && j==m)
	{
	    if(isSafe(i,j))
            path[i][j]=1;
        else
            return false;

		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout<<path[i][j]<<" ";
			}
			cout<<endl;
		}

		return true;
	}
	if(j>m || i>n)
		return false;
	//recursive
	if(isSafe(i,j))
	{
		path[i][j]=1;
		bool nextRight = rat(i,j+1,n,m);
		if(nextRight)
			return true;
		bool nextDown= rat(i+1,j,n,m);
		if(nextDown)
			return true;
		path[i][j]=0;

	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>maze[i][j];
		}
	}
	bool pathFound = rat(1,1,n,m);
	if(!pathFound)
		cout<<"-1"<<endl;
	return 0;
}
