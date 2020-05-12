#include<bits/stdc++.h>
using namespace std;

void mergeA(int a[],int l,int m,int r)
{
    int i=l,j=m+1;
    int tmp[10000]={0};
    int k=0;
    while(i<=m && j<=r)
    {
        if(a[i]<a[j])
        {
            tmp[k]=a[i];
            i++;k++;
        }else
        {
            tmp[k]=a[j];
            j++;k++;
        }
    }
    while(i<=m)
    {
        tmp[k]=a[i];
        i++;k++;
    }
    while(j<=r)
    {
        tmp[k]=a[j];
        j++;k++;
    }
     j=l;
    for(int i=0;i<k;i++)
    {
        a[j]=tmp[i];
        j++;
    }
}

void mergeSort(int a[],int start,int last)
{
    //base
    if(start>=last)
        return;
    //recursive
    int mid =start + ((last-start)/2);
    mergeSort(a,start,mid);
    mergeSort(a,mid+1,last);

    mergeA(a,start,mid,last);
}

int main()
{
    int n;
    cout<<"Enter number of elements to sort  ";
    cin>>n;
    cout<<"Please Enter list to be Sorted"<<endl;
    int a[100000]={0};
    for(int i=0;i<n;i++)
        cin>>a[i];
    mergeSort(a,0,n-1);
    cout<<"After Sorting List becomes"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

}
