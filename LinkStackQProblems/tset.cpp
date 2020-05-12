#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void pushq1(queue<int> q, queue<int> &q1){
    while(!q.empty()){
        int x = q.front();
        q.pop();
        q1.push(x);
    }
}
bool isSort(queue <int> q){
    int ele = q.front();
    q.pop();
    while(!q.empty()){
        if(ele <= q.front()){
            ele = q.front();
            q.pop();
        }
        else{
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        queue <int> q;
        int n, tmp;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>tmp;
            q.push(tmp);
        }
        stack<int> s;
        int sele = q.front();
        q.pop();
        queue<int> q1;
        pushq1(q,q1);
        q1.push(sele);
        if(isSort(q1)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
