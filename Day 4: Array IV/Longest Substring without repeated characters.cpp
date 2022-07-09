//in this approach
//we take two pinter left and right
//we fix left at begin and move right until we didn't find any previous matching character 
//and simultaneously we insert that in our set
//when we find that this character exist in the set already then we move left pointer
//till it reach to the repeated character and simultaneously remove it from set
//we r removing bcz we want continuous string(substring) so have to remove till the repeated character

//time o(2n)
//space o(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n=s.size();
        unordered_set<int> hashset;
        int left=0;
        int maxlen=0;
        for(int right=0;right<n;right++)
        {
            if(hashset.count(s[right]))
            {
                while(left<right && hashset.find(s[right])!=hashset.end()) //jb tk wo repeated character remove n ho jata
                {
                    hashset.erase(s[left]);
                    left++;
                }
            }
            hashset.insert(s[right]);
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};

//instead of removing elements from set i had stored their index
//if any repeat occur which is inside the range then
//left will be the repeat char indx bcz from there we will start our new substring

//time o(n)
//space o(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector < int > mpp(256, -1);

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) { 
        if (mpp[s[right]] != -1)  //means repeat character had occured
          left = max(mpp[s[right]] + 1, left);  //left will be max of left and one index ahead of repeat char in the current selected substring

        mpp[s[right]] = right;  

        len = max(len, right - left + 1);
        right++;
      }
      return len;
    }
};
