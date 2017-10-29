class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.size();
		int charactor[256];
		for (int i = 0; i < 256; i++) {
			charactor[i] = -1;
		}
		int i = 0, j = 0, lols = 0;
		while (i < n&&j < n) {
			if (charactor[s[j]] < i) {
				charactor[s[j]] = j;
				lols = lols > (j - i + 1) ? lols : (j - i + 1);
			}
			else {
				i = charactor[s[j]] + 1;
				charactor[s[j]] = j;
			}
			j++;
		}
		return lols;
	}
};