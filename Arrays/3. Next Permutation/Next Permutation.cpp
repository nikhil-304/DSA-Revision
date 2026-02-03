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
     *    Reverse the entire array to get the smallest permutation.
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

/*
Time Complexity: O(3N)
Space Complexity: O(1)
*/

//Problem Link: https://leetcode.com/problems/next-permutation/

/*
The algorithm follows 4 logical steps:

1. Find a “breakpoint”
Traverse from right to left and find the first index i such that:

`nums[i] < nums[i + 1]`

This means the array stops being non-increasing here.

2. If no breakpoint exists
The array is in descending order -> it’s the largest permutation.
Just reverse it to get the smallest permutation.

3. Find the next bigger element
From the right side, find the smallest number that is greater than nums[ind] and swap.

4. Reverse the suffix
Reverse everything to the right of ind to get the smallest next permutation.
*/
