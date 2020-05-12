#include<bits/stdc++.h>
using namespace std;

bool isPoss(queue<int> q)
{
    stack<int> s;
    queue<int> q2;
    // last will store max value in our output Q
    int last=INT_MIN;

    while(!q.empty())
    {
        int first=q.front();
        q.pop();
        // if first element popped is smaller than max
        //  element inserted in q2 then now we can not
        //sort it as we can not pop from q2
        if(first < last)
            return false;
        // we will fill stack such that top element is minimum in stack
        // and bottom is max
        if(s.empty() || s.top()>=first)
            s.push(first);
        else if(s.top()<first)
        {
            // now we compare 3 elements first , stack top and
            // max stored in q2
            while(!s.empty() && s.top()<first)
            {
                if(q2.empty() || last <= s.top())
                {
                    q2.push(s.top());
                    last = s.top();
                    s.pop();
                }else
                {
                    // it means element we popped from q is smaller
                    // than max in q2 hence it cannot be sorted
                    return false;
                }
            }
            s.push(first);
        }
    }
    return true;
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
        if(isPoss(q))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
