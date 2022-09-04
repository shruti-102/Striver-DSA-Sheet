https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    vector<string> ans;
    void helper(string str,int n,int sum,int indx)
    {
       // if(sum>n || sum<=-1) return;
        
        if(indx==n*2)
        { 
          if(sum==0) ans.push_back(str);
            return;
        }
        
        helper(str+'(',n,sum+1,indx+1);
        if(sum>0) helper(str+')',n,sum-1,indx+1);
    }
    vector<string> generateParenthesis(int n) {
        int sum=0,indx=0;
        helper("",n,sum,indx);
        return ans;
    }
};
