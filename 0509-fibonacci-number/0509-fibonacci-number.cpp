class Solution {
public:
    int fib(int n) {
        if(n<=1)return n;

        int prev = 1;
        int secondprev =0;
        int ans =0;

        for(int i=1;i<n;i++){
            ans = prev + secondprev;
            secondprev =prev;
            prev = ans;
        } 
        return ans;
    }
};