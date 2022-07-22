//time o(nlogn)+o(n)
//space o(1)

//we will sort all arrival and departure time so that we can find out which train is arriving eraly and which train is leaving(departing) platform
//if the arival time of the train is greater than the departure time of specific train means platform will get empty 
//and then same platform can be used for the arrival of the tain so we will not increment the number of platform requires
//decrement the platform required
//similarly if the arrival time is early than the departure time then we will be required a new plaform so we will increment the platform required

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    vector<pair<int,int>> v;
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int platform=1,maxplat=INT_MIN;
    	int arrival=1,departure=0;
    	while(arrival<n && departure<n)
    	{
    	    if(arr[arrival]<=dep[departure])
    	    {
    	        platform++;
    	        arrival++;
    	    }
    	    else if(arr[arrival]>dep[departure])
    	    {
    	        platform--;
    	        departure++;
    	    }
    	    maxplat=max(maxplat,platform);
    	}
    	return maxplat;
    }
};
