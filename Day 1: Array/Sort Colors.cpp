//counting sort technique
//time o(n)
//space o(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0=0,count1=0,count2=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0) count0++;
            else if(nums[i]==1) count1++;
            else count2++;
        }
        
        for(int i=0;i<count0;i++)
        {
            nums[i]=0;
        }
        for(int i=count0;i<count0+count1;i++)
        {
            nums[i]=1;
        }
        for(int i=count0+count1;i<n;i++)
        {
            nums[i]=2;
        }
    }
};

//swaping approach
//time o(n)
//space o(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start=0,end=nums.size()-1;
        int i=0;
        while(i<=end)
        {
            if(nums[i]==0)
            {
              //increment the new pos of zero
              //increment i 
                swap(nums[i],nums[start]);
                start++;
                i++;
            }
            else if(nums[i]==2)
            {
              //not incrementing i because it may be possible that it will have zero after swaping  
              swap(nums[end],nums[i]);
                end--;
            }
            else // for 1 just increment the counter
                i++;
        }
    }
};
