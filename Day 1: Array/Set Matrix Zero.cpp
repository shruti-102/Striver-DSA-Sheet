//time: O(N^2)
//space: O(N)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> v;
        int m=matrix.size();
        int n=matrix[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    v.push_back({i,j});
                }
            }
        }
        
        for(int k=0;k<v.size();k++)
        {
            int r=v[k].first;
            int c=v[k].second;
            
            for(int i=0;i<n;i++)
            {
                matrix[r][i]=0;
            }
            for(int j=0;j<m;j++)
            {
                matrix[j][c]=0;
            }
        }
        
    }
};

//Time: O(N^2)
//Space: O(1)
class Solution {
public:
    
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int firstcol=0;
        
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]==0)
            {
                firstcol=1;
            }
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        
        
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[0][j]==0 || matrix[i][0]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        
        if(matrix[0][0]==0)
        {
            for(int j=0;j<n;j++)
            {
                matrix[0][j]=0;
            }
        }
        
        if(firstcol)
        {
             for(int j=0;j<m;j++)
            {
                matrix[j][0]=0;
            }
        }
    }
};

