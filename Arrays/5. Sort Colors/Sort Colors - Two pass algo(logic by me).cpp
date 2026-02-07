class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Variables to keep a count of 0's, 1's and 2's
        int zeroCnt = 0, oneCnt = 0, twoCnt = 0;

        // 1. Iterate the array to keep count of 0's, 1's and 2's
        //O(n)
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] == 0) zeroCnt++;
            else if(nums[i] == 1) oneCnt++;
            else twoCnt++;
        }

        // 2. Based on vars vals replace the nums[j] until vars vals  
        //O(n)
        for(int j=0 ; j<nums.size() ; j++){
            if(zeroCnt > 0){
                nums[j] = 0;
                zeroCnt--;
            }
            else if(oneCnt > 0){
                nums[j] = 1;
                oneCnt--;
            }
            else{
                nums[j] = 2;
                twoCnt--;
            }
        }
    }
};

//Problem Link: https://leetcode.com/problems/sort-colors/description/

/*
Time Complexity: O(n) + O(n) = O(2n)
Space Complexity: O(1)
*/
