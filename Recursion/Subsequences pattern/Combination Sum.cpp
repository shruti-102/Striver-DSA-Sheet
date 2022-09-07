https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int>& subset,int i,int n,int target,vector<int>& nums)
    {
        if(target==0)
        {
            res.push_back(subset);
            return;
        }
        if(target<0) return;
        
        if(i>=n) return;
        
        subset.push_back(nums[i]);
        solve(subset,i,n,target-nums[i],nums);
        subset.pop_back();
        solve(subset,i+1,n,target,nums);
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> subset;
        solve(subset,0,candidates.size(),target,candidates);
        return res;
    }
};
