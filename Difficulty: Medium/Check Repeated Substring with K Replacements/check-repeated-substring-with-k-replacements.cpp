class Solution {
	public:
	bool matchString(string &s1, string s2)
	{
		int m = 0;
		if (s1.size() == 0)
			s1 = s2;
		while (m != s1.size()) {
			if (s1[m] != s2[m])
				return false;
			m = m + 1;
		}
		return true;
	}
	bool kSubstr(string &s, int k) {
		int len = s.size();
		if ((len % k))
			return false;
		string s1, s2;
		int c1, c2;
		int m;
		s1 = "";
		s2 = "";
		c1 = 0;
		c2 = 0;
		m = 0;
		while (m != len) {
			if (matchString(s1, s.substr(m, k)) == true)
				c1 = c1 + 1;
			else if (matchString(s2, s.substr(m, k)) == true)
				c2 = c2 + 1;
			else
				return false;
			if (c1 > 1 && c2 > 1)
				return false;
			m = m + k;
		}
		return true;
		
	}
};
