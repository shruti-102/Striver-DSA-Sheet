//time o(n)
//space o(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int ptr1=-1,ptr2;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                ptr1=i;
                break;
            }
        }
        if(ptr1==-1) 
        {
            sort(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]>nums[ptr1])
            {
                ptr2=i;
                break;
            }
        }
        
        swap(nums[ptr1],nums[ptr2]);
      //we can also use sort function instead of reverse
        reverse(nums.begin()+ptr1+1,nums.end());
    }
};
