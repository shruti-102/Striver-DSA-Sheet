class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    vector<pair<int,int>> v;
    static bool cmp(pair<int,int> a,pair<int,int> b)
    {
        return a.second<b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        int c=1;
        for(int i=0;i<n;i++)
        {
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),cmp);
        
        int s=v[0].first;
        int e=v[0].second;
        
        for(int i=1;i<v.size();i++)
        {
            if(v[i].first>e)
            {
                c++;
                e=v[i].second;
            }
        }
        return c;
    }
    
};
