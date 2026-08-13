class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size())
            return false;

        vector<int> freq(26, 0);

        for (auto ch : s) {
            freq[ch - 'a']++;
        }
        for (auto ch : t) {
            freq[ch - 'a']--;
        }
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] != 0) {
                return false;
            }
        }
        return true;
    }
};