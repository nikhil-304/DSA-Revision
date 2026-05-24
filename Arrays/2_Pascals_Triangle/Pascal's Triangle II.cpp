class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // here rowIndex + 1 because the input is foll. 0th index analogy, which means, 4th row will have it's input here as rowIndex = 3, but we'll follow the rowNum analogy
        int rowNum = rowIndex + 1;

        // eg: 4th Row
        vector<int> finalAns;
        long long ans = 1;
        // in 4th row, push the 0th index value
        // eg: [1, ...]
        //    0th element
        finalAns.push_back(ans);

        // loop for populating values after 0th index
        // eg: [1, 3, 3, 1]
           // 0th, 1st, 2nd, 3rd
        for(int i=1 ; i<rowNum ; i++){
            ans = ans * (rowNum - i);
            ans = ans / (i);
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
//Revision done on: 14/05/2026
