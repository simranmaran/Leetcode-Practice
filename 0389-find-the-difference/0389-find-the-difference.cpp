class Solution {
public:
    char findTheDifference(string s, string t) {
        int total = 0;

        
        for(int i = 0; i < t.size(); i++) {
            total = total + t[i];
        }

        
        for(int i = 0; i < s.size(); i++) {
            total = total - s[i];
        }

       
        return total;
    }
};