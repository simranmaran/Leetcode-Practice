class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int smax = -1;
        int mx = -1;
        for(int i=0;i<nums.size();i++){

            if(mx<nums[i]){
                smax=mx;
                mx=nums[i];

            }
            else if(smax<nums[i]){
                smax=nums[i];
            }
        }

        int ans=(mx-1)*(smax-1);
        return ans;




        
    }
};