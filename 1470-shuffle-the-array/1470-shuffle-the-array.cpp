class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans(2*n);
        int i =0;
        int j =0+n;
        for(int k =0;k<nums.size();k++){
           if(k%2==0){
            ans[k]=nums[i];
            i++;
           }else{
            ans[k]=nums[j];
            j++;
           }
        }
        return ans;
    }
};