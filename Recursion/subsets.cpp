#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > allSubsets;

bool comp(vector<int> a, vector<int> b)
{
    return a.size()<b.size();
}

void findAllSubsets(int a[],int n,int target,vector<int> subset)
{
	//base
	if(n==0)
    {
        int sum=0;
        for(int i=0;i<subset.size();i++)
            sum+=subset[i];
        if(sum==target)
            allSubsets.push_back(subset);
        return;
    }
    //recursive case

    //include
    subset.push_back(a[n-1]);
    findAllSubsets(a,n-1,target,subset);
    //exclude
    subset.pop_back();
    findAllSubsets(a,n-1,target,subset);

}

int main()
 {
	//inputs
	int n,target,a[20]={0};
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>target;

	//processing

	vector<int> subset;

	findAllSubsets(a,n,target,subset);

	sort(allSubsets.begin(),allSubsets.end(),comp);

	//printOutputs
	for (int i=0; i<allSubsets.size(); i++)
    {
        for (int j=0; j<allSubsets[i].size();j++)
            cout << allSubsets[i][j] << " ";
        cout << endl;
    }

	return 0;
}
