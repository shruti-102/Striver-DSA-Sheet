https://www.codingninjas.com/codestudio/problems/binary-strings-with-no-consecutive-1s_893001?leftPanelTab=0

vector<string> res;
void solve(int prev,int k,string s)
{
    if(k==0){
        res.push_back(s);
        return;
    }
    if(prev==1) {
        solve(0,k-1,s+'0');  
    }
    else{
        solve(0,k-1,s+'0');
        solve(1,k-1,s+'1');
    }
    return;
}
vector<string> generateString(int k) {
    // Write your code here.
    res.clear();
    if(k<=0) return res;
    
    solve(0,k-1,"0");
    solve(1,k-1,"1");
    return res;
}
