//https://bit.ly/3Ka7xYU


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int> currency{1,2,5,10,20,50,100,200,500,2000};
        vector<int> ans;
        
        for(int i=currency.size()-1;i>=0;i--)
        {
            if(N>=currency[i])
            {
                int d=N/currency[i];
                while(d--){
                    ans.push_back(currency[i]);
                }
                N=N%currency[i];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
