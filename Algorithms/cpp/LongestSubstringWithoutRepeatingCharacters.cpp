const int MAX_SIZE = 256;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int d[MAX_SIZE], t = 0, ans = 0, c[MAX_SIZE];
        memset(d, 0, sizeof(d));

        for (int i = 0; i < len; i++) {
            int k = s[i];
            if (d[k]) {
                ans = max(ans, i - t);
                t = c[k] + 1;
                memset(d, 0, sizeof(d));
                for (int j = t; j < i; j++)
                    d[s[j]] = 1;
            }
            d[k] = 1;
            c[k] = i;
        }
        return max(ans, len - t);
    }
};
