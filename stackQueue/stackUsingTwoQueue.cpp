#include<iostream>
#include<queue>
using namespace std;

class Stack
{
    queue<int> q1,q2;
    public:
        void push(int data)
        {
            if(q1.empty() && q2.empty())
            {
                q1.push(data);
            }else if(q2.empty())
            {
                q1.push(data);
            }else
            {
                q2.push(data);
            }
        }
        void pop()
        {
            if(q1.empty() && q2.empty())
            {
                return;
            }else if(q2.empty())
            {
                while(q1.size()!=1)
                {
                    q2.push(q1.front());
                    q1.pop();
                }
                q1.pop();
                return;
            }else
            {
                while(q2.size()!=1)
                {
                    q1.push(q2.front());
                    q2.pop();
                }
                q2.pop();
                return;
            }

        }
        int top()
        {
            if(q1.empty() && q2.empty())
            {
                return -1;
            }else if(q2.empty())
            {
                while(q1.size()!=1)
                {
                    q2.push(q1.front());
                    q1.pop();
                }
                int topy=q1.front();
                q1.pop();
                q2.push(topy);
                return topy;
            }else
            {
                while(q2.size()!=1)
                {
                    q1.push(q2.front());
                    q2.pop();
                }
                int topy=q2.front();
                q2.pop();
                q1.push(topy);
                return topy;
            }
        }
        bool Empty()
        {
            return q1.empty() && q2.empty();
        }

};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    while(!s.Empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
