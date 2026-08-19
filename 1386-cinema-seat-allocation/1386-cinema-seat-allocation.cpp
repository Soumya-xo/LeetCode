class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        for (auto &x : reservedSeats) {
            int row = x[0];
            int seat = x[1];

            if (seat == 1 || seat == 10)
                continue;

            mp[row] |= (1 << seat);
        }

        int ans = (n - mp.size()) * 2;

        int left   = 0b0000111100;   
        int middle = 0b0011110000;   
        int right  = 0b1111000000;   

        for (auto &[row, mask] : mp) {
            bool L = (mask & left) == 0;
            bool M = (mask & middle) == 0;
            bool R = (mask & right) == 0;

            if (L && R)
                ans += 2;
            else if (L || M || R)
                ans++;
        }

        return ans;
    }
};