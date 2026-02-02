class Solution {
public:
    vector<int> generateRows(int nRow){
        vector<int> pascalAns;
        long long ans = 1;
        pascalAns.push_back(ans);
        
        for(int i=1 ; i<nRow ; i++){
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
