//merger sort technique

#include <bits/stdc++.h> 

long long int res=0;
void merge(long long *arr,long long low,long long mid,long long high)
{
    long long n=mid-low+1;
    long long m=high-mid;
    
    long long left[n],right[m];
    for(long long i=0;i<n;i++)
    {
        left[i]=arr[low+i];
    }
    
    for(long long i=0;i<m;i++)
    {
        right[i]=arr[mid+i+1];
    }
    int k=low;
    int i=0,j=0;
    while(i<n && j<m)
    {
        if(left[i]>right[j])
        {
            arr[k++]=right[j++];
            res +=(n-i);
        }
        else
        {
            arr[k++]=left[i++];
        }
    }
    
    while(i<n)
    {
        arr[k++]=left[i++];
    }
    while(j<m)
    {
        arr[k++]=right[j++];
    }
}
void divide(long long *arr,long long low,long long high)
{
    if(low>=high)    //only one element
        return;
    
    long long mid=low+(high-low)/2;
    divide(arr,low,mid);
    divide(arr,mid+1,high);
    
   merge(arr,low,mid,high);
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    divide(arr,0,n-1);
    return res;
