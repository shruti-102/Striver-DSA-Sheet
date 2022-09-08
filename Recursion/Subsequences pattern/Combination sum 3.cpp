//https://leetcode.com/problems/combination-sum-iii/

class Solution {
public:
    vector<vector<int>> res;
    void solve(int k,int target,int i,vector<int>& subset)
    {
        if(k==0 && target!=0) return;
        
        if(k==0 && target==0)
        {
            res.push_back(subset);
            return;
        }
        
        if(i>9) return;
        if(target-i>=0){
            subset.push_back(i);
            solve(k-1,target-i,i+1,subset);
            subset.pop_back();
        }
        solve(k,target,i+1,subset);
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subset;
        //vector<int> nums{1,2,3,4,5,6,7,8,9};
        solve(k,n,1,subset);
        return res;
    }
};
