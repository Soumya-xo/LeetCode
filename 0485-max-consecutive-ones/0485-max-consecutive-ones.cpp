class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;
        for (int num : nums) {
            if (num == 0) {
                count = 0;
            } else {
                count++;
                maxCount = max(count, maxCount);
            }
        }
        return maxCount;
    }
};