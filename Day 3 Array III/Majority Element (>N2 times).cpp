//Moore's Algorithm
//time o(n)
//space o(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maje=0;
        int count=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(count==0)
            {
                maje=nums[i];
            }
            if(nums[i]==maje)
            {
                count++;
            }
            else if(maje!=nums[i])
            {
                count--;
            }
        }
        return maje;
    }
};
