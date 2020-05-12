#include<bits/stdc++.h>
using namespace std;

queue<int> sortQ(queue<int> q,int n)
{
    int first = q.front();
    q.pop();
    //base
    if(q.empty())
    {
        q.push(first);
        return q;
    }
    // for n-1
    q = sortQ(q,n-1);
    int counter=0;
    while(first>=q.front() && counter<n-1)
    {
        q.push(q.front());
        q.pop();
        counter++;
    }
    q.push(first);
    counter++;
    for(int i=0;i<n-counter;i++)
    {
        q.push(q.front());
        q.pop();
    }
    return q;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,data;
        cin>>n;
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            cin>>data;
            q.push(data);
        }
        //inp done
        q = sortQ(q,n);

        while(!q.empty())
        {
            cout<<q.front()<<" ";
            q.pop();
        }
        cout<<endl;

    }   //test case end
    return 0;
}
