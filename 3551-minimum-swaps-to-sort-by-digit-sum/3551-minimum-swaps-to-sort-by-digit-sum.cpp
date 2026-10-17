class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr;

        for (int x : nums) {
            int sum = 0, temp = x;
            while (temp) {
                sum += temp % 10;
                temp /= 10;
            }
            arr.push_back({sum, x});
        }

        sort(arr.begin(), arr.end());

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++)
            pos[arr[i].second] = i;

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            int j = i, cycle = 0;
            while (!visited[j]) {
                visited[j] = true;
                j = pos[nums[j]];
                cycle++;
            }

            if (cycle > 1)
                swaps += cycle - 1;
        }

        return swaps;
    }
};