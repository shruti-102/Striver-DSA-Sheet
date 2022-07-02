//time o(n*m)
//space o(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        //transpose
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<m;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        
        //mirror image
        cout<<endl;
        for(int j=0;j<m/2;j++)
        {
            for(int i=0;i<n;i++)
            {
                swap(matrix[i][j],matrix[i][m-j-1]);
            }
        }
        
    }
};
