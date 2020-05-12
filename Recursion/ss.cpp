// RatInMaze
#include<iostream>
using namespace std;
int count = 0;
bool RatInMaze(char maze[][10],int sol[][10],int i,int j,int n,int m){
	// Base case
	if(i == n-1 && j==m-1){
        count++;
		sol[i][j] = 1;
        int oi=0 , oj=0;
		// Print the path
		for(int k=0;k<n;k++){
			for(int l=0;l<m;l++){
                if(sol[k][l] == 1){
                    if(oi == k && oj != l){
                        cout<<'H';
                        oj=l;
                    }
                    else if(oj == l && oi != k){
                        cout<<'V';
                        oi=k;
                    }
                }
				// cout<<sol[k][l]<<' ';
			}
			// cout<<endl;
		}
		cout<<" ";
		return false;
	}

	// Recursive Case
	// Assume that current cell we are standing on is part of solution
	sol[i][j] = 1;
	// Check Downwards
	if(i+1<n){
		bool KyaNeecheSeRaastaMilla = RatInMaze(maze,sol,i+1,j,n,m);
		if(KyaNeecheSeRaastaMilla == true){
			return true;
		}
	}
	// First check Rightwards
	if(j+1<m){
		bool KyaRightSeRaastaMilla = RatInMaze(maze,sol,i,j+1,n,m);
		if(KyaRightSeRaastaMilla == true){
			return true;
		}
	}

	sol[i][j] = 0;
	return false;
}

int main(){
    int n, m;
    cin>>n>>m;
	char maze[10][10];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            maze[i][j] = 'O';
        }
    }
	int sol[10][10]={0};
    bool ans = RatInMaze(maze,sol,0,0,n,m);
    cout<<endl<<count;
	return 0;
}
