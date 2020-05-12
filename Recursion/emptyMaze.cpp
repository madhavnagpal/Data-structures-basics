#include<bits/stdc++.h>
using namespace std;

vector<string> moves ;

int counter(int row,int col)
{
	//base
	if(row<1 || col<1)
		return 0;
	if(row==1 && col==1)
		return 1;
	return counter(row,col-1)+counter(row-1,col);
}

void printWays(int row,int col,int row_final,int col_final,string out)
{
	//base
	if(row==row_final && col==col_final)
	{
		moves.push_back(out);
		return ;
	}
	if(col>col_final || row>row_final)
		return;
	//recursive case
	//send down
	printWays(row+1,col,row_final,col_final,out+"V");

	//send right
	printWays(row,col+1,row_final,col_final,out+"H");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int row,col,ways;
	cin>>row>>col;

	printWays(1,1,row,col,"");
    for(int i=0;i<moves.size();i++)
        cout<<moves[i]<<" ";
    cout<<endl;
	ways = counter(row,col);
	cout<<ways<<endl;
	return 0;
}
