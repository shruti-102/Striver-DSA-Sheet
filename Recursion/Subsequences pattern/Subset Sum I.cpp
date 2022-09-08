//https://practice.geeksforgeeks.org/problems/subset-sums2234/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=subset-sums

// Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> res;
    
    void generate(vector<int> arr,int n,int i,vector<int>& subset,int sum)
    {
        if(i==n)
        {
            res.push_back(sum);
            return;
        }
        
        //nottake
        generate(arr,n,i+1,subset,sum);
        
        //take
        subset.push_back(arr[i]);
        generate(arr,n,i+1,subset,sum+arr[i]);
        subset.pop_back();
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> subset;
        generate(arr,N,0,subset,0);
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
