/* Structure of Binary Tree Node
class Node {
	public:
	int data;
	Node *left;
	Node *right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
}; */
class Solution {
	public:
	int bends(vector<Node*>& vec, int i, int prev) {
		if (i == vec.size() - 1)
			return 0;
		
		if (vec[i]->left && vec[i]->left->data == vec[i + 1]->data)
			return bends(vec, i + 1, 0) + (prev == 1);
		return bends(vec, i + 1, 1) + (prev == 0);
	}
	
	int solve(vector<Node*>& vp, int i, vector<Node*>& vq, int j) {
		if (i == vp.size() - 1) {
			int dir = 0;
			if (vq[j]->right && vq[j]->right->data == vq[j + 1]->data)
				dir = 1;
			return bends(vq, j + 1, dir);
		} else if (j == vq.size() - 1) {
			int dir = 0;
			if (vp[i]->right && vp[i]->right->data == vp[i + 1]->data)
				dir = 1;
			return bends(vp, i + 1, dir);
		}
		
		int res = 1;
		int dir = 0;
		if (vq[j]->right && vq[j]->right->data == vq[j + 1]->data)
			dir = 1;
		res += bends(vq, j + 1, dir);
		dir = 0;
		if (vp[i]->right && vp[i]->right->data == vp[i + 1]->data)
			dir = 1;
		res += bends(vp, i + 1, dir);
		return res;
	}
	
	void findPath(Node* root, int num, stack<Node*>& st) {
		if (!root)
			return;
		
		if (!st.empty() && st.top()->data == num)
			return;
		
		st.push(root);
		if (!st.empty() && st.top()->data == num)
			return;
		
		findPath(root->left, num, st);
		if (!st.empty() && st.top()->data == num)
			return;
		
		findPath(root->right, num, st);
		if (!st.empty() && st.top()->data == num)
			return;
		
		st.pop();
	}
	
	vector<int> findCommonAncestor(vector<Node*>& v1, vector<Node*>& v2) {
		int i = 0, j = 0;
		int n1 = v1.size(), n2 = v2.size();
		while (i < n1 && j < n2) {
			if (v1[i]->data == v2[i]->data) {
				i++;
				j++;
			} else
			break;
		}
		return {i - 1, j - 1};
	}
	
	int numberOfTurns(Node* root, int p, int q) {
		
		if (p == q)
			return - 1;
		
		stack<Node*> ps;
		findPath(root, p, ps);
		vector<Node*> vp;
		while (!ps.empty()) {
			vp.push_back(ps.top());
			ps.pop();
		}
		reverse(vp.begin(), vp.end());
		
		stack<Node*> qs;
		findPath(root, q, qs);
		vector<Node*> vq;
		while (!qs.empty()) {
			vq.push_back(qs.top());
			qs.pop();
		}
		reverse(vq.begin(), vq.end());
		
		vector<int> common = findCommonAncestor(vp, vq);
		
		int res = solve(vp, common[0], vq, common[1]);
		return res ? res : -1;
	}
};
