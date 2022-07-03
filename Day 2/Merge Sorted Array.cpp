//time o(m*n)+o(n)
//soace o(1)
class Solution {
public:
    //insertion sort intution
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int ptr1=0;
        int ptr2=0;
        while(ptr1<m && ptr2<n)
        {
            if(nums1[ptr1]>nums2[0])
            {
                swap(nums1[ptr1],nums2[0]);
                
                //find correct pos
                int val=nums2[0],i;
                
                for(i=1;i<n && nums2[i]<val;i++)
                {
                    nums2[i-1]=nums2[i];
                }
                nums2[i-1]=val;
            }
            ptr1++;
        }
        
        for(int i=m,j=0;i<m+n;i++,j++)
        {
            nums1[i]=nums2[j];
        }
    }
};

//two pointer approach
//time o(m+n)
//space o(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int x=m+n-1;
        int i=m-1;
        int j=n-1;
        while(i>=0 && j>=0)
        {
            if(nums1[i]>=nums2[j])
            {
                nums1[x]=nums1[i];
                i--;
            }
            else 
            {
                nums1[x]=nums2[j];
                j--;
            }
            x--;
        }
        while(i >= 0)
            nums1[x--] = nums1[i--];
        while(j >= 0)
            nums1[x--] = nums2[j--];
    return;
        
    }
};
