#include <bits/stdc++.h>
class Solution {
public:
    /*
     * Function: nextPermutation
     * -------------------------
     * Rearranges the given array into the next lexicographically greater permutation.
     * If no such permutation exists, it rearranges the array into the lowest possible order.
     *
     * Algorithm:
     * 1. Find the first index (from right) where nums[i] < nums[i+1].
     *    This index marks the point where the permutation can be increased.
     *
     * 2. If such an index does not exist, the array is in descending order.
     *    Reverse the entire array to get the smallest next permutation.
     *
     * 3. Otherwise, find the smallest element (from the right side) that is greater
     *    than nums[ind] and swap them.
     *
     * 4. Reverse the portion of the array after index ind to get the next smallest permutation.
     */
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();

        // Step 1: Find the breakpoint
        for(int i=n-2 ; i>=0 ; i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }

        // Step 2: If no breakpoint found, reverse entire array
        if(ind == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find the element just larger than nums[ind]
        for(int i=n-1 ; i>ind ; i--){
            if(nums[i] > nums[ind]){
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // Step 4: Reverse the suffix
        reverse(nums.begin() + ind+1, nums.end());
    }
};

//Problem Link: https://leetcode.com/problems/next-permutation/

/*
Time Complexity: O(3N)
Space Complexity: O(1)
*/

/*
The algorithm follows 4 logical steps:

1. Find a “breakpoint”
Traverse from right to left and find the first index i such that:

`nums[i] < nums[i + 1]`

This means the array stops being non-increasing here.

2. If no breakpoint exists
The array is in descending order -> it’s the largest permutation.
Just reverse it to get the smallest permutation (the first permutation).

3. Find the next bigger element
From the right side, find the smallest number that is greater than nums[ind] and swap.

4. Reverse the suffix
Reverse everything to the right of ind to get the smallest next permutation.
*/

/*
========================================
DRY RUN EXAMPLE
========================================

Input:
nums = [1, 3, 5, 4, 2]

--------------------------------------------------
STEP 1: Find the Breakpoint
--------------------------------------------------

We move from RIGHT -> LEFT
and find first index where:

nums[i] < nums[i+1]

Checking:

i = 3
4 < 2 ? NO

i = 2
5 < 4 ? NO

i = 1
3 < 5 ? YES

So,
ind = 1

Breakpoint element:
nums[ind] = 3

Current array:

1 3 5 4 2
  ^

This means:
We can make the permutation bigger from here.

--------------------------------------------------
STEP 2: Find element just greater than nums[ind]
--------------------------------------------------

Now search from RIGHT side
for element > 3

Checking:

2 > 3 ? NO
4 > 3 ? YES

Swap 3 and 4

After swap:

1 4 5 3 2

--------------------------------------------------
STEP 3: Reverse the right part
--------------------------------------------------

Reverse everything after index ind

Current right part:
5 3 2

After reversing:
2 3 5

Final array:

1 4 2 3 5

--------------------------------------------------
FINAL ANSWER
--------------------------------------------------

Next permutation of:

1 3 5 4 2

is:

1 4 2 3 5

========================================
*/

//Revision done on: 26/05/2026
