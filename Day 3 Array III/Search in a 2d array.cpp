//linear search
//time o(n)+o(m)
//space o(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        int targetrow=n-1;
        for(int i=0;i<n;i++)
        {
            if(target==matrix[i][0]) return true;
            
            if(target<matrix[i][0]){
                targetrow=i-1;
                break;
            }
        }
        
        if(targetrow==-1) return false;
        
        for(int j=0;j<m;j++)
        {
            if(matrix[targetrow][j]==target) return true;
        }
        return false;
    }
};

//binary search
//time O(log n)+O(log m)
//space o(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        int m=matrix[0].size();
    
        int targetrow=n-1;
        bool found=false;
        int l=0,h=n-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;

            if(matrix[mid][0]==target)
            {
                found=true;
                targetrow=mid;
                break;
            }
            else if(matrix[mid][0]<target && matrix[mid][m-1]>=target)
            {
                found=true;
                targetrow=mid;
                break;
            }
            if(matrix[mid][0]>target)
            {
                h=mid-1;
            }
            
            else if(matrix[mid][0]<target)
            {
                l=mid+1;
            }
        }
        
        if(!found) return false;
        
        l=0,h=m-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(matrix[targetrow][mid]==target) return true;
            else if(matrix[targetrow][mid]>target)
            {
                h=mid-1;
            }
            else if(matrix[targetrow][mid]<target)
            {
                l=mid+1;
            }
        }
        return false;
    }
};
