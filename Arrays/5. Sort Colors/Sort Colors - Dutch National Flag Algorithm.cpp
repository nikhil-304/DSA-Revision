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

Hypothetical Array Indexes
Conditions:-
[0....low-1] - 0 {Extreme Left}
[low....mid-1] - 1
[high+1.....n-1] - 2 {Extreme Right}

0      low-1  low    mid-1   mid     high     high+1     n-1
^        ^     ^       ^      ^        ^        ^         ^
|        |     |       |      |        |        |         |
0........0     1.......1      0, 1, 2, 1        2.........0
                               unsorted

Time Complexity: O(n) ----> Increasing or Decreasing count in one iteration
Space Complexity: O(1)
*/

/*
The Three Rules:

    1. 0 to low - 1: Contains all 0s.
    2. low to mid - 1: Contains all 1s.
    3. high + 1 to n - 1: Contains all 2s.

    mid to high: The unsorted section (0s, 1s, and 2s).

Diagrammatic Dry Run

Imagine an unsorted array: [2, 0, 2, 1, 1, 0]
Initial state: low = 0, mid = 0, high = 5

    Step 1 (arr[mid] is 2): Swap arr[mid] (2) with arr[high] (0).
        [0, 0, 2, 1, 1, 2]
        high moves to 4. mid stays 0.

low = 0, mid = 0, high = 4

    Step 2 (arr[mid] is 0): Swap arr[mid] (0) with arr[low] (0).
        [0, 0, 2, 1, 1, 2]
        low moves to 1, mid moves to 1.

low = 1, mid = 1, high = 4
    Step 3 (arr[mid] is 0): Swap arr[mid] (0) with arr[low] (0).
        [0, 0, 2, 1, 1, 2]
        low moves to 2, mid moves to 2.

low = 2, mid = 2, high = 4
    Step 4 (arr[mid] is 2): Swap arr[mid] (2) with arr[high] (1).
        [0, 0, 1, 1, 2, 2]
        high moves to 3. mid stays 2.

low = 2, mid = 3, high = 3
    Step 5 (arr[mid] is 1): mid moves to 3.

low = 2, mid = 3, high = 3
    Step 6 (arr[mid] is 1): mid moves to 4.

At this point, mid > high, the loop terminates, and the array
[0, 0, 1, 1, 2, 2] is perfectly sorted
*/

//Revision done on 29/05/2026
