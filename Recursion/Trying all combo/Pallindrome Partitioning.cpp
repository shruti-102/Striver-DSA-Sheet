//https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    vector<vector<string>> res;
    
    bool ispallindrome(string s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int i,string s,vector<string>& part)
    {
        if(i==s.size())
        {
            res.push_back(part);
            return;
        }
        
        for(int k=i;k<s.size();k++)
        {
            
            if(ispallindrome(s,i,k)){
                //cout<<s.substr(i,k-i+1)<<" ";
                part.push_back(s.substr(i,k-i+1));
                solve(k+1,s,part);
                part.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<string> part;
        solve(0,s,part);
        return res;
    }
};
