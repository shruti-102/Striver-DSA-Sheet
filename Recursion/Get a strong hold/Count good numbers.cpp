https://leetcode.com/problems/count-good-numbers/

class Solution {
public:
    int mod = 1000000007;
    long long solve(long long val,long long pow){ // calculatin pow in log(n) time
        if(pow==0) return 1;
        
        if(pow%2==0){
            return solve((val*val)%mod,pow/2)%mod;
        }
        else
            return (val*solve((val*val)%mod,pow/2))%mod;
        
    }
    int countGoodNumbers(long long n) {
        // even means 5 options 
        // odd means 4 option 
        
        long long pow = n/2; // calculate no of times 5*4 means 20 occurs
        
        long long ans = solve(20,pow); // calculate power(20,pow)
        
        if(n%2==0){ // if n is even then 5 and 4 occur same no of time n/2 
            return ans;
        }
        return ((5*ans) % mod);  // if n is odd then 5 occurs n/2+1 times means one extra times so return ans*5 and don't forgot to mod
    }
};
