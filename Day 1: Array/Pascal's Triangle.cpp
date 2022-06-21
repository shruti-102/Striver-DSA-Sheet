//pascal I
//time: o(n^2)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        int n=numRows;
        for(int i=0;i<n;i++)
        {
            ans[i].resize(i+1);
            ans[i][0]=1;
            ans[i][i]=1;
            
            for(int j=1;j<i;j++)
            {
                ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
            }
        }
        return ans;
    }
};

//pascal II
//time: O(n)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1);
        
        ans[0]=1;
        if(rowIndex==0) return ans;
        ans[1]=rowIndex;
        int prev=rowIndex;
        long n=rowIndex;
        for(int i=2,up=rowIndex-1;i<rowIndex+1;i++,up--)
        {
            n=(n*up)/i;;
            ans[i]=n;
        }
        return ans;
    }
};
