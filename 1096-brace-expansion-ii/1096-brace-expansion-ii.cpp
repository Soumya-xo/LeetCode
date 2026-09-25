class Solution {
public:
    set<string> st;
    string s;
    int i = 0;
    set<string> parseUnion() {
        set<string> res = parseConcat();

        while (i < s.size() && s[i] == ',') {
            i++;
            set<string> next = parseConcat();

            res.insert(next.begin(), next.end());
        }

        return res;
    }
    set<string> parseConcat() {
        set<string> res = {""};

        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> cur;

            if (s[i] == '{') {
                i++; 
                cur = parseUnion();
                i++; 
            } 
            else {
                cur.insert(string(1, s[i]));
                i++;
            }

            set<string> temp;

            for (string a : res) {
                for (string b : cur) {
                    temp.insert(a + b);
                }
            }

            res = temp;
        }

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;

        set<string> ans = parseUnion();

        return vector<string>(ans.begin(), ans.end());
    }
};