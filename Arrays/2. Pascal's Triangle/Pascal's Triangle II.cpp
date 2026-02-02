class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> finalAns;
        long long ans = 1;
        finalAns.push_back(ans);

        for(int i=0 ; i<rowIndex ; i++){
            ans = ans * (rowIndex - i);
            ans = ans / (i+1);
            finalAns.push_back(ans);
        }
        return finalAns;
    }
};

/*
Time Complexity: O(rowIndex)
Space Complexity: O(rowIndex)
*/

//Problem Link: https://leetcode.com/problems/pascals-triangle-ii/

//Revision done on: 2/2/2026
