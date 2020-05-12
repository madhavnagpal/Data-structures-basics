#include<bits/stdc++.h>
using namespace std;

int board[1001]={0},dice[1001]={0};
vector<int> primes;

bool isPrime(int num)
{
    int i=2;
	for(;i<num;i++)
    {
        if(num%i==0)
			return false;
    }
	if(i==num)
		return true;
}

void formPrimeList(int n)
{
	for(int i=2;i<=n;i++)
    {
        if(isPrime(i))
        {
            primes.push_back(i);
        }
    }
}

void setBoard(int i,int j,int counter)
{
    if(i>=j)
        return;
    //recursive
    if(counter%2==0)
    {
        board[primes[i]]=primes[j];
        setBoard(i+1,j-1,counter+1);
    }else
    {
        board[primes[j]]=primes[i];
        setBoard(i+1,j-1,counter+1);
    }
    return;
}
bool boardCrossed(int i,int n,int diceMove,int m)
{
    //base
    if(i>=n)
        return true;
    if(i<0)
        return false;
    if(board[i]!=0)
        return boardCrossed(board[i],n,diceMove,m);
    if(diceMove<=m)
        return boardCrossed(i+dice[diceMove]-1,n,diceMove+1,m);

    return false;

}


int main() {
    int n;
    cin>>n;
    int m;
    cin>>m;
    for(int i=1;i<=m;i++)
        cin>>dice[i];
	formPrimeList(n);
	setBoard(0,primes.size()-1,0);

    if(boardCrossed(0,n,1,m))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

	return 0;
}

