//https://leetcode.com/problems/letter-combinations-of-a-phone-number/


class Solution {
public:
    vector<string> res;
    void solve(int i,string digits,unordered_map<int,string>& mp,string str)
    {
        if(i==digits.size())
        {
            res.push_back(str);
            return;
        }
        
        int key=digits[i]-'0';
        string value=mp[key];
        
        for(int k=0;k<value.size();k++)
        {
            str+=value[k];
            solve(i+1,digits,mp,str);
            str.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        unordered_map<int,string> mp;
        mp[2]="abc";
        mp[3]="def";
        mp[5]="jkl";
        mp[6]="mno";
        mp[4]="ghi";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        
        solve(0,digits,mp,"");
        return res;
    }
};
