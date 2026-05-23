class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;   // final answer store karega

    for(int i = 0; i < numRows; i++) {

        vector<int> row(i + 1, 1); 
        // har row size i+1 hogi aur sabko 1 se fill kar diya

        for(int j = 1; j < i; j++) {
            row[j] = result[i-1][j-1] + result[i-1][j];
        }

        result.push_back(row); // addded rows
    }

    return result;
}
};