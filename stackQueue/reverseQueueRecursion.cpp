#include<bits/stdc++.h>
using namespace std;

void reverseQ(queue<int> &q)
{
    if(q.empty())
        return;
    int fronty=q.front();
    q.pop();
    reverseQ(q);
    q.push(fronty);
}

void printQueue(queue<int> q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<"END"<<endl;
}

int main()
{
    queue<int> q;
	int n,data;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>data;
		q.push(data);
	}
    reverseQ(q);
    printQueue(q);
    return 0;
}
