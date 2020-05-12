#include<bits/stdc++.h>
using namespace std;

int sudoku[100][100]={0};

bool isSafe(int i,int j,int number,int n)
{
	for(int k=0;k<n;k++)
        if(sudoku[i][k]==number || sudoku[k][j]==number)
			return false;

    n=sqrt(n);
    int start_row=(i/n)*n;
    int start_col=(j/n)*n;

	for(int i=start_row;i<start_row+n;i++)
		for(int j=start_col;j<start_col+n;j++)
			if(sudoku[i][j]==number)
				return false;
	return true;
}

bool solveSudoku(int i,int j,int n)
{
	//base
	if(i==n)
	{
		for(int p=0;p<n;p++)
		{
			for(int k=0;k<n;k++)
                cout<<sudoku[p][k]<<" ";
			cout<<endl;
		}
		return true;
	}
	if(j==n)
		return 	solveSudoku(i+1,0,n);

	if(sudoku[i][j]!=0)
        return solveSudoku(i,j+1,n);

	//recursive case

	for(int k=1;k<=n;k++)
	{
		if(isSafe(i,j,k,n))
		{
			sudoku[i][j]=k;
			bool nextSudokuSolved = solveSudoku(i,j+1,n);
			if(nextSudokuSolved)
				return true;
            else
                sudoku[i][j]=0;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>sudoku[i][j];
    cout<<endl;
	solveSudoku(0,0,n);
	return 0;
}
