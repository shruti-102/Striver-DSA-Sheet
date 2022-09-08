//https://leetcode.com/problems/subsets-ii/


class Solution {
public:
    vector<vector<int>> res;
    
    void generate(vector<int> &nums,int n,int i,vector<int>& subset)
    {
        if(i==n)
        {
            res.push_back(subset);
            return;
        }
        int k=1;
        while(i+k<n && nums[i]==nums[i+k])
        {
            k++;
        }
        generate(nums,n,i+k,subset);
        subset.push_back(nums[i]);
        generate(nums,n,i+1,subset);
        subset.pop_back();
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> subset;
        generate(nums,nums.size(),0,subset);
        return res;
    }
};
