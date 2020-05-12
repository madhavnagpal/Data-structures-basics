#include<bits/stdc++.h>
using namespace std;
int counter=0;

void cross(int i,int j,int n,char board[][1000])
{
    //base
    if(n<=0)
        return;
    if(i==n && j==n)
    {
        //print
        for(int row=0;row<=n;row++)
        {
            for(int col=0;col<=n;col++)
                if(board[row][col]!='O')
                    cout<<"{"<<row<<"-"<<col<<"}"<<board[row][col];
        }
        cout<<"{"<<n<<"-"<<n<<"} ";
        counter++;
        return ;
    }
    // out of chess
    if(i<0 || j<0 || i>n || j>n)
        return;

    //move on knight
    board[i][j]='K';
    cross(i+2,j+1,n,board);
    cross(i+1,j+2,n,board);

    //on wall
    if(i==0 || j==0 || i==n ||j==n)
    {
        board[i][j]='R';
        //horizontal
        for(int a=i,b=j+1;b<=n;b++)
        {
            cross(a,b,n,board);
        }
        //vertucal
        for(int a=i+1,b=j;a<=n;a++)
        {
            cross(a,b,n,board);
        }
    }
    //on diagonal
    if(i==j)
    {
        board[i][j]='B';
        for(int a=i+1,b=j+1; a<=n && b<=n ;a++,b++)
        {
            cross(a,b,n,board);
        }
    }
    board[i][j]='O';
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char board[1000][1000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            board[i][j]='O';
        }
    }
    cross(0,0,n-1,board);
    cout<<endl<<counter<<endl;
    return 0;
}
