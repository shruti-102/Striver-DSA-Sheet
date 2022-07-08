class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      
          vector<int> v;
            int maje1=-1,maje2=-1;
            int count1=0,count2=0;

            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==maje1) count1++;
                else if(nums[i]==maje2) count2++;
                
                else if(count1==0)
                {
                    maje1=nums[i];
                    count1=1;
                }
                
                else if(count2==0)
                {
                    maje2=nums[i];
                    count2=1;
                }
                else
                {
                    count1--;
                    count2--;
                }
            }
        count1=0,count2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==maje1) count1++;
            else if(nums[i]==maje2) count2++;
        }
        
        if(count1>(nums.size()/3))
            v.push_back(maje1);
        if(count2>(nums.size()/3))
            v.push_back(maje2);
          
          return v;
    }
};
