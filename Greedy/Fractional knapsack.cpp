//https://bit.ly/3PsqOFL

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

static bool compare(Item it1,Item it2)
{
   return (double)it1.value/it1.weight > (double)it2.value/it2.weight;
}
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,compare);
        double profit=0;
        
        for(int i=0;i<n && W>0;i++)
        {
            int val=arr[i].value;
            int wt=arr[i].weight;
            
            if(W>=wt)
            {
                profit+=val;
                W-=wt;
            }
            else
            {
                profit+=((double)val/(double)wt)*W;
                W=0;
            }
        }
        return profit;
    }
    
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends
