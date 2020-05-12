#include<bits/stdc++.h>
using namespace std;

const int N = 10, M = 10;
int n, m;
int p1_r, p1_c, p2_r, p2_c, p3_r, p3_c;
int cnt;

void func(int i, int j, int cell, int mat[N][M]){
	if(i >= n || i < 0)	return;
	if(j >= m || j < 0)	return;
	if(mat[i][j] == 1)	return;
	cell++;
	mat[i][j] = 1;
	if(i == 0 && j == 1){
		if(cell == n*m)
			cnt++;
		mat[i][j] = 0;
		return;
	}
	if(i == p1_r && j == p1_c && cell != (n*m)/4){
		mat[i][j] = 0;
		return;
	}
	if(i == p2_r && j == p2_c && cell != (n*m)/2){
		mat[i][j] = 0;
		return;
	}
	if(i == p3_r && j == p3_c && cell != (3*n*m)/4){

		mat[i][j] = 0;
		return;
	}
	func(i+1, j, cell, mat);
	func(i-1, j, cell, mat);
	func(i, j+1, cell, mat);
	func(i, j-1, cell, mat);
	mat[i][j] = 0;
}

int main(){
	int t;	cin >> t;
	for(int test = 1; test <= t; test++){
		cnt = 0;
		cin >> n >> m;
		cin >> p1_r >> p1_c >> p2_r >> p2_c >> p3_r >> p3_c;
		int mat[N][M] = {0};
		func(0, 0, 0, mat);
		cout << "Case " << test << ": " << cnt << endl;
	}
}
