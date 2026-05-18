class Solution {
public:
    int findLucky(vector<int>& arr) {
        
        // Step 1: Frequency count 
        unordered_map<int, int> hm;
        
        for (int i = 0; i < arr.size(); i++) {
            int ele = arr[i];
            
            if (hm.count(ele)) {
                hm[ele]++;        // pehle se hai toh +1
            } else {
                hm[ele] = 1;      // pehle baar aaya toh 1
            }
        }
        
        // Step 2: check lucky 
        int ans = -1;
        
        for (auto key : hm) {
            if (key.first == key.second) {      // value == frequency?
                ans = max(ans, key.first);       // sabse bada rakho
            }
        }
        
        return ans;
    }
};