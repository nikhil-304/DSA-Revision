class Solution {
public:
    void sortColors(vector<int>& nums) {
       int n = nums.size();
       int low = 0,  mid = 0, high = n-1;

       while(mid <= high)
       {
        if(nums[mid] == 0){
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid] == 1){
            mid++;
        }
        else{
            swap(nums[mid], nums[high]);
            high--;
        }
       }
    }
};

/*
Dutch National Flag Algorithm
Conditions:-
[0....low-1] - 0 {Extreme Left}
[low....mid-1] - 1
[high+1.....n-1] - 2 {Extreme Right}

0      low-1  low    mid-1   mid     high     high+1     n-1
^        ^     ^       ^      ^        ^        ^         ^
|        |     |       |      |        |        |         |
0........0     1.......1      0, 1, 2, 1        2.........0
                               unsorted

For the first time, we consider our whole array as unsorted, so start mid as 0, then start to shrink
Time Complexity: O(n) ----> Increasing or Decreasing count in one iteration
Space Complexity: O(1)
*/
