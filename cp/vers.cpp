#include<bits/stdc++.h>
using namespace std;

int n;
int mat[100][100]={0};
int trace,col,row;

bool checkRow(int i)
{
    int a[100]={0};
    for(int j=0;j<n;j++)
    {
        if(a[mat[i][j]])
            return true;
        else
            a[mat[i][j]]++;
    }
    return false;
}
bool checkCol(int j)
{
    int a[100]={0};
    for(int i=0;i<n;i++)
    {
        if(a[mat[i][j]])
            return true;
        else
            a[mat[i][j]]++;
    }
    return false;
}

int main()
{
    int t;
    cin>>t;

    for(int test=1;test<=t;test++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        //inputs done
        trace=0;
        col=0;
        row=0;

        int i=0,j=0;
        while(i<n && j<n)
        {
            bool rowDup = checkRow(i);
            if(rowDup)
                row++;
            bool colDup= checkCol(j);
            if(colDup)
                col++;
            trace+=mat[i][j];
            i++,j++;
        }
        cout<<"Case #"<<test<<": "<<trace<<" "<<row<<" "<<col<<endl;
    }//test case end;
    return 0;
}
