class Solution {
	public:
	bool isValid(string& s) {
		int count = 0;
		for (char ch : s) {
			if (ch == '(')
				count++;
			else if (ch == ')')
				count--;
			if (count < 0)
				return false;
		}
		return count == 0;
	}
	vector<string> validParenthesis(string &s) {
		unordered_set<string> visited;
		queue<string> q;
		vector<string> ans;
		q.push(s);
		visited.insert(s);
		bool found = false;
		while (!q.empty()) {
			string curr = q.front();
			q.pop();
			if (isValid(curr)) {
				ans.push_back(curr);
				found = true;
			}
			if (found)continue;
			for (int i = 0; i<curr.length(); i++) {
				if (curr[i] != '(' && curr[i] != ')')
					continue;
				string next = curr.substr(0, i) + curr.substr(i + 1);
				if (!visited.count(next)) {
					visited.insert(next);
					q.push(next);
				}
			}
		}
		sort(begin(ans), end(ans));
		return ans;
	}
};
