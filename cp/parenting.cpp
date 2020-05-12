#include<bits/stdc++.h>
using namespace std;

bool isFree(char a[],int starty,int endy)
{
    for(int i=starty;i<endy;i++)
        if(a[i]=='b')
            return false;
    return true;
}
void book(char a[],int starty,int endy)
{
    for(int i=starty;i<endy;i++)
        a[i]='b';
}

int main()
{
    int t;
    cin>>t;

    for(int test=1;test<=t;test++)
    {
        int n;
        cin>>n;
        char c[1440],j[1440];
        for(int i=0;i<1440;i++)
        {
            c[i]='f';
            j[i]='f';
        }
        int starty,endy;
        string s="";
        bool possible=true;
        while(n--)
        {
            cin>>starty>>endy;
            if(possible)
            {
               bool cFree = isFree(c,starty,endy);
               if(cFree)
               {
                   //book c
                   book(c,starty,endy);
                   s.push_back('C');
                   continue;
               }
               bool jFree = isFree(j,starty,endy);
               if(jFree)
               {
                   //book c
                   book(j,starty,endy);
                   s.push_back('J');
                   continue;
               }

               if(!cFree && !jFree)
               {
                   s="IMPOSSIBLE";
                   possible=false;
               }
            }
        }
        cout<<"Case #"<<test<<": "<<s<<endl;
    }//test case end;
    return 0;
}

