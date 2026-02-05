class Solution{
public:
	int maxSubArray(vector<int> &nums){
		int sum = 0;
		int maxi = INT_MIN;     //int maxi = nums[0];
		for(auto it : nums){    //We can consider the first element as maximum or
			sum += it;          //the lowest as maximum for JUST the initial time
			maxi = max(sum, maxi);
			if(sum < 0) sum = 0;
		}
		return maxi;
	}	
};

//Problem Link: leetcode.com/problems/maximum-subarray/

/*
Kadane's Algorithm - To find the Maximum Subarray Sum

Time Complexity: O(N)
Space Complexity: O(1)
*/
