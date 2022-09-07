https://leetcode.com/problems/combination-sum-ii/


class Solution {
public:
    vector<vector<int>> res;
    
    void solve(vector<int>& nums,vector<int>& subset,int i,int n,int target)
    {
        if(target==0)
        {
            res.push_back(subset);
            return;
        }
        
        if(i>=n) return;
        
        int k=1;
        while(i+k<n && nums[i]==nums[i+k])
        {
            k++;
        }
        
        solve(nums,subset,i+k,n,target);
        if(target-nums[i]>=0)
        {
            subset.push_back(nums[i]);
            solve(nums,subset,i+1,n,target-nums[i]);
            subset.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> subset;
        solve(candidates,subset,0,candidates.size(),target);
        return res;
    }
};
