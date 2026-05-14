class Solution {
public:
    int tribonacci(int n) {
        if(n==0){
            return 0;
        }
        else if(n==1 || n==2){
            return 1;
        }
        else{
             long long firstN=0;
             long long SecondN=1;
             long long ThirdN=1;
        for(int i=1;i<=n;i++){
            long long fourthN=firstN +SecondN +ThirdN;

            firstN=SecondN;
            SecondN=ThirdN;
            ThirdN=fourthN;

        }
        return firstN;
        }
        
    }
};