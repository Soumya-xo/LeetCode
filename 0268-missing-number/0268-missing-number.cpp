class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expected = n * (n+1) /2;
        int actual = 0;
 
        for(int n:nums){
            actual+=n;
        }
        return expected - actual;
    }
};