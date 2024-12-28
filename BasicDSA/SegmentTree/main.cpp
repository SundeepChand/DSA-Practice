#include <bits/stdc++.h>
using namespace std;

// A segment tree to find answer min range query.
class SegmentTree {
private:
	vector<int> tree;
	vector<int> v;

	void buildTree(int, int, int);
	int queryUtil(int, int, int, int, int);
	void updateUtil(int, int, int, int, int);

public:
	SegmentTree(const vector<int> &v);
	int query(int, int);
	void update(int, int);
};

SegmentTree::SegmentTree(const vector<int> &v) {
	int n = v.size();
	this->v = v;
	// The size of the tree should be 2 * (2 ^ (ceil(log2(N)))) - 1
	// https://www.geeksforgeeks.org/segment-tree-sum-of-given-range/
	tree = vector<int>(3 * n);
	buildTree(0, 0, n - 1);
}

void SegmentTree::buildTree(int idx, int l, int r) {
	if (l > r) {
		return;
	}
	if (l == r) {
		tree[idx] = v[l];
		return;
	}

	int mid = l + (r - l) / 2;
	buildTree(2 * idx + 1, l, mid);
	buildTree(2 * idx + 2, mid + 1, r);

	tree[idx] = min(tree[2 * idx + 1], tree[2 * idx + 2]);
}

int SegmentTree::queryUtil(int idx, int s, int e, int l, int r) {
	if (r < s || l > e) {
		return INT_MAX;
	}
	if (l <= s && r >= e) {
		return tree[idx];
	}

	int mid = s + (e - s) / 2;
	int left = queryUtil(2 * idx + 1, s, mid, l, r);
	int right = queryUtil(2 * idx + 2, mid + 1, e, l, r);
	return min(left, right);
}

int SegmentTree::query(int l, int r) {
	return queryUtil(0, 0, v.size() - 1, l, r);
}

void SegmentTree::updateUtil(int idx, int s, int e, int pos, int val) {
	if (s > e) {
		return;
	}
	if (s == e && s == pos) {
		tree[idx] = val;
		return;
	}
	int mid = s + (e - s) / 2;
	if (pos <= mid) {
		updateUtil(2 * idx + 1, s, mid, pos, val);
	} else {
		updateUtil(2 * idx + 2, mid + 1, e, pos, val);
	}
	tree[idx] = min(tree[2 * idx + 1], tree[2 * idx + 2]);
}

void SegmentTree::update(int pos, int val) {
	updateUtil(0, 0, v.size() - 1, pos, val);
}

int main() {
	int n, q;
	cin>>n>>q;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin>>v[i];
	}

	SegmentTree s(v);

	for (int i = 0; i < q; i++) {
		char op;
		int l, r;
		cin>>op>>l>>r;

		if (op == 'q') {
			cout<<s.query(l - 1, r - 1)<<endl;
		} else {
			s.update(l - 1, r);
		}
	}

	return 0;
}
