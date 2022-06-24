//kadane's algotiyhm
//time o(n)
//space o(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int cursum=nums[0];
        int maxsum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            cursum=max(cursum+nums[i],nums[i]);
            if(cursum>maxsum)
            {
                maxsum=cursum;
            }
            if(cursum<0)
            {
                cursum=0;
            }
        }
        return maxsum;
    }
};


//Dynamic Programming
//time o(n)
//space o(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        dp[0]=nums[0];
        int maxsum=nums[0];
        for(int i=1;i<n;i++)
        {
          //figuring out that the current element will contribute in the ongoing subarray or make a new one with starting by him
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
            maxsum=max(maxsum,dp[i]);
        }
        return maxsum;
    }
};
