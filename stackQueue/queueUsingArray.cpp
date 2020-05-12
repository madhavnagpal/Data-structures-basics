#include<iostream>
using namespace std;

class Queue
{
    int *a,cs,f,e,N;
    public:
        Queue(int n=5)
        {
            a=new int[n];
            N=n;
            cs=0;
            f=0;
            e=n-1;
        }
        void push(int data)
        {
            if(cs==N)
            {
                cout<<"Overflow"<<endl;
                return;
            }
            e=(e+1)%N;
            a[e]=data;
            cs++;

        }
        void pop()
        {
            if(cs==0)
            {
                cout<<"Underflow"<<endl;
                return;
            }
            f=(f+1)%N;
            cs--;
        }
        int Front()
        {
            return a[f];
        }
        bool Empty()
        {
            return cs==0;
        }

};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    while(!q.Empty())
    {
        cout<<q.Front()<<" ";
        q.pop();
    }
    return 0;
}

