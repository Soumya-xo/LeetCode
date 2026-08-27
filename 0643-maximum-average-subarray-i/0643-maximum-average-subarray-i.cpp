class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum = 0;
        for(int i =0;i<k;i++){
            sum += nums[i];
        }
        long long maximum = sum;

        for(int i=k;i<nums.size();i++){
            sum+=nums[i];
            sum-=nums[i-k];

            maximum = max(sum,maximum);
        }

        return (double)maximum/k;
    }
};