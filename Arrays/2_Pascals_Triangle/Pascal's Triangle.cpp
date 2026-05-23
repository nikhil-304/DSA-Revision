class Solution {
public:
    vector<int> generateRows(int nRow){
        // eg: 4th Row
        vector<int> pascalAns;
        long long ans = 1;
        // in 4th row, push the 0th index value
        // eg: [1, ...] 
        //    0th element
        pascalAns.push_back(ans);
        
        // loop for populating values after 0th index
        // eg: [1, 3, 3, 1]
           // 0th, 1st, 2nd, 3rd
        for(int i=1 ; i<nRow ; i++){
            // ans = ans * (nRow - i) / i;
            ans = ans * (nRow-i);
            ans = ans / i;
            pascalAns.push_back(ans);
        }
        return pascalAns;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> finalAns;
        
        for(int i=1 ; i<=numRows ; i++){
            finalAns.push_back(generateRows(i));
        }
        return finalAns;
    }
};

/*
Time Complexity: O(numRows^2)
Space Complexity: O(numRows^2)
*/
