#include<bits/stdc++.h>
using namespace std;

class Queue
{
    private:
        int *a,cs,f,r,ms;
    public:
        Queue(int k=5)
        {
            a=new int[k];
            ms=k;
            cs=0;
            f=0;
            r=k-1;
        }
        int Front()
        {
            if(cs==0)
                return -1;
            return a[f];
        }
        int Rear()
        {
            if(cs==0)
                return -1;
            return a[r];
        }
        bool enQueue(int data)
        {
            if(cs==ms)
                return false;
            r = (r+1)%ms;
            a[r]=data;
            cs++;
            return true;
        }
        bool deQueue()
        {
            if(cs==0)
                return false;
            f = (f+1)%ms;
            cs--;
            return true;
        }
        bool isEmpty()
            {
                return cs==0;
            }
        bool isFull()
        {
            return cs==ms;
        }
};
int main()
{
    int n;
    cin>>n;
    Queue q(n);

    int data;
    while(cin>>data)
    {
        if(data<1 || data>6)
            break;
        switch(data)
        {
            case 1:
                    int tmp;
                    cin>>tmp;
                    if(q.enQueue(tmp))
                        cout<<"true"<<endl;
                    else
                        cout<<"false"<<endl;
                    break;
            case 2:
                    if(q.deQueue())
                        cout<<"true"<<endl;
                    else
                        cout<<"false"<<endl;
                    break;
            case 3:
                cout<<q.Front()<<endl;
                break;
            case 4:
                cout<<q.Rear()<<endl;
                break;
            case 5:
                    if(q.isEmpty())
                        cout<<"true"<<endl;
                    else
                        cout<<"false"<<endl;
                    break;
            case 6:
                    if(q.isFull())
                        cout<<"true"<<endl;
                    else
                        cout<<"false"<<endl;
                    break;
            default:
                break;
        }
    }

return 0;
}
