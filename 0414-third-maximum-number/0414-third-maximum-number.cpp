class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long m1=LLONG_MIN;
        long long m2 =LLONG_MIN;
        long long m3 = LLONG_MIN;

        for(int i =0;i<nums.size();i++){
            if(nums[i]==m1 || nums[i]==m2 || nums[i]==m3){
                continue;
            }

            if(nums[i]>m1){
                m3=m2;
                m2=m1;
                m1=nums[i];
            }else if(nums[i]>m2){
                m3=m2;
                m2=nums[i];
            }else if(nums[i]>m3){
                m3=nums[i];
            }
        }
        if(m3==LLONG_MIN)return m1;
        return m3;
    }
};