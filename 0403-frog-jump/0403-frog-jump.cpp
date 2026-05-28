#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    // position -> index mapping
    unordered_map<long long, int> positionIndex;
    
    // DP memoization: for each stone index and last jump
    vector<unordered_map<int, bool>> memo;
    
    vector<int> stones;
    int n;

    bool dfs(int index, int lastJump) {
        // If we reached the last stone, return true
        if (index == n - 1) {
            return true;
        }

        // If this state (index, lastJump) is already computed, reuse it
        if (memo[index].count(lastJump)) {
            return memo[index][lastJump];
        }

        // Try jumps: lastJump - 1, lastJump, lastJump + 1
        for (int nextJump = lastJump - 1; nextJump <= lastJump + 1; nextJump++) {
            // Jump must be positive
            if (nextJump <= 0) {
                continue;
            }

            // Calculate next stone position
            long long nextPosition = (long long)stones[index] + nextJump;

            // If that position has a stone
            if (positionIndex.count(nextPosition)) {
                int nextIndex = positionIndex[nextPosition];

                // Recursive DFS on next stone and next jump
                if (dfs(nextIndex, nextJump)) {
                    return memo[index][lastJump] = true;
                }
            }
        }

        return memo[index][lastJump] = false;
    }

    bool canCross(vector<int>& inputStones) {
        stones = inputStones;
        n = stones.size();

        // If the second stone is not at position 1, frog can't start
        if (stones[1] != 1) {
            return false;
        }

        // Resize memo to store results for each stone
        memo.resize(n);

        // Build the position-to-index map
        for (int i = 0; i < n; i++) {
            positionIndex[stones[i]] = i;
        }

        // Start the recursive DFS from the second stone with the first jump being 1
        return dfs(1, 1);
    }
};