class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int range=nums.size();

        int actualsum=(range*(range+1))/2;

        int currSum=0;

        for(int i=0;i<nums.size();i++){
            currSum=currSum + nums[i] ;
        }

        int ans=actualsum - currSum;

        return ans;
        
    }
};