//dynamic programming
//time o(n)
//space o(n)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(n);
        dp[0]=0;
        int minbuy=prices[0];
        int maxprofit=INT_MIN;
        
        for(int i=1;i<n;i++)
        {
            int profit=prices[i]-minbuy;
            if(profit<=dp[i-1])
            {
                dp[i]=dp[i-1];
            }
            else
            {
                dp[i]=profit;
            }
            minbuy=min(minbuy,prices[i]);
        }
        
        return dp[n-1];
    }
};


//dynamic programming with space optimization
//time o(n)
//space o(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        int minbuy=prices[0];
        int maxprofit=0;
        
        for(int i=1;i<n;i++)
        {
            int profit=prices[i]-minbuy;
            if(maxprofit<profit)
            {
                maxprofit=profit;
            }
            minbuy=min(minbuy,prices[i]);
        }
        
        return maxprofit;
    }
};
