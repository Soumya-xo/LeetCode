class Solution {
public:
    int robb(vector<int>& nums,int start, int end){
        int prev =0;
        int prev2 =0;

        for(int i=start;i<=end;i++){
            int pick = nums[i]+prev2;
            int notpick = prev;

            int curr = max(pick,notpick);
            prev2 =prev;
            prev=curr;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1)return nums[0];

        int case1 = robb(nums,0,n-2);
        int case2 = robb(nums,1,n-1);

        return max(case1,case2);
    }
};