class Solution {
public:
    bool solve(vector<int>& arr, int i, vector<int>& visited) {
        int n = arr.size();

        if(i < 0 || i >= n) {
            return false;
        }

        if(visited[i]) {
            return false;
        }

        if(arr[i] == 0) {
            return true;
        }

        visited[i] = 1;

        return solve(arr, i + arr[i], visited) ||
               solve(arr, i - arr[i], visited);
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> visited(n, 0);

        return solve(arr, start, visited);
    }
};