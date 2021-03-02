#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, longest; // longest=���� �� ���� �� ��� ����
vector<int> y, x, radius;

// Ʈ�� ����ü
struct TreeNode
{
	vector<TreeNode*> children;
};

// x�� ������ ��ȯ�Ѵ�
int pow(int x) { return x * x; }

// a, b�� �Ÿ��� ���Ѵ�
int dist(int a, int b) { return pow(y[a] - y[b]) + pow(x[a] - x[b]); }

// ���� a�� ���� b�� �����ϴ��� Ȯ���Ѵ�
bool encloses(int a, int b)
{
	return radius[a] > radius[b] && dist(a, b) < pow(radius[a] - radius[b]);
}

// ���� Ʈ������ parent�� child�� �θ����� Ȯ���Ѵ�
bool isChild(int parent, int child)
{
	if (!encloses(parent, child)) return false;
	for (int i = 0; i < n; i++)
		// parent�� child�� �� ���� �����ؾ� �Ѵ�
		if (i != parent && i != child && encloses(parent, i) && encloses(i, child))
			return false;
	return true;
}

// root ������ ��Ʈ�� �ϴ� Ʈ���� �����Ѵ�
TreeNode* getTree(int root)
{
	TreeNode* ret = new TreeNode();
	for (int ch = 0; ch < n; ch++)
	{
		// ch ������ root ������ ���������� ���ԵǾ� �ִٸ�
		// Ʈ���� ����� �ڼ� ��Ͽ� �߰��Ѵ�
		if (isChild(root, ch))
			ret->children.push_back(getTree(ch));
	}
	return ret;
}

// root�� ��Ʈ�� �ϴ� ����Ʈ���� ���̸� ���Ѵ�
int height(TreeNode* root)
{
	// �� �ڽ��� ��Ʈ�� �ϴ� ����Ʈ�� ���̸� ����Ѵ�
	vector<int> heights;
	for (int i = 0; i < root->children.size(); i++)
		heights.push_back(height(root->children[i]));
	// ���� �ڽ��� �ϳ��� ���ٸ� ���̴� 0
	if (heights.empty()) return 0;
	// ���� ����
	sort(heights.begin(), heights.end());
	int k = heights.size();
	// ������ ����� �ִ밪�� �����Ѵ�
	if (k >= 2)
		longest = max(longest, 2 + heights[k - 2] + heights[k - 1]);
	// Ʈ���� ���̴� ����Ʈ�� �������ִ�ġ�� 1�� ���� ����Ѵ�
	return heights.back() + 1;
}

// �� ��� ������ ���� �� ����� ���̸� ����Ѵ�
int solve(TreeNode* root)
{
	longest = 0;
	// Ʈ���� ���̿� ���� �� ��� ���� �� ū ���� �����Ѵ�.
	int h = height(root);
	return max(longest, h);
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n;
		y.resize(n);
		x.resize(n);
		radius.resize(n);
		for (int i = 0; i < n; i++) cin >> y[i] >> x[i] >> radius[i];
		// Ʈ�� ����
		TreeNode* root= getTree(0);
		cout << solve(root) << '\n';
		y.clear();
		x.clear();
		radius.clear();
	}
}