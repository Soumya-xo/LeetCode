class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // suf[i] = earliest position in word2 that can be matched
        vector<int> suf(n + 1, m);

        int j = m - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (j >= 0 && word1[i] == word2[j]) {
                --j;
            }
            suf[i] = j + 1;
        }

        vector<int> ans;
        bool used = false;
        j = 0;

        for (int i = 0; i < n && j < m; ++i) {

            // Exact match
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                ++j;
            }

            // Use one mismatch
            else if (!used) {

                // Can remaining part still be matched?
                if (suf[i + 1] <= j + 1) {
                    ans.push_back(i);
                    used = true;
                    ++j;
                }
            }
        }

        if (j == m) return ans;
        return {};
    }
};