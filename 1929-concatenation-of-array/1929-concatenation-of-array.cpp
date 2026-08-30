class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>ans(nums.size()*2);
        int i =0;
        int j =0+nums.size();
        for(int num : nums){
            ans[i]=ans[j]=num;
            i++;
            j++;
        }
        return ans;
    }
};