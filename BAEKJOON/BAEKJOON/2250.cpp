#include<iostream>
#include<vector>

using namespace std;

// Ʈ�� ��� ����(��Ʈ, ����, ������, �θ� ���)
struct TreeNode {
	int root, left, right, parent;
};
vector<TreeNode> T; // Ʈ�� �迭

// �� ��ȣ, Ʈ�� ����
int colCount = 1, depth = 1;
vector<int> minLev, maxLev; // (min/max)Lev[x]: x ���� �� ��, ���� �ּ�/�ִ�

int min(int a, int b) { return a < b ? a : b; }

// ���� ��ȸ
void inorder(int node, int level)
{
	TreeNode t = T[node];
	if (depth < level) depth = level; // Ʈ�� ���� ����
	// ���� ����Ʈ�� Ž��
	if(t.left>0)
		inorder(t.left, level + 1);
	// ������ ���� �ּ�/�ִ� ����
	minLev[level] = min(minLev[level], colCount);
	maxLev[level] = colCount++;
	// ������ ����Ʈ�� Ž��
	if (t.right > 0)
		inorder(t.right, level + 1);
}

int main(void)
{
	int n;
	cin >> n;
	T.resize(n + 1);
	// �ʱ� ����
	for (int i = 1; i <= n; i++)
		T[i] = { i,-1,-1,-1 }; // root�� i�� �Ͽ� ����
	minLev.resize(n + 1, n + 1);
	maxLev.resize(n + 1);
	// Ʈ�� ��� �߰�
	for (int i = 0; i < n; i++)
	{
		int r, a, b;
		cin >> r >> a >> b;
		// ���� ��尡 ���� ��
		if (a > 0)
		{
			T[r].left = a; // ���� ��� ����
			T[a].parent = r; // �θ� ���� ����
		}
		// ������ ��尡 ���� ��
		if (b > 0)
		{
			T[r].right= b; // ������ ��� ����
			T[b].parent = r; // �θ� ���� ����
		}
	}
	int root = -1;
	// �ֻ�� ��Ʈ ��� ã��
	for (int i = 1; i <= n; i++)
	{
		// �θ� ���� ��尡 ��Ʈ ���
		if (T[i].parent == -1)
		{
			root = T[i].root;
			break;
		}
	}
	// ���� ��ȸ
	inorder(root, 1);
	// ��Ʈ ���� �׻� 1����, 1�� �ʺ� ������
	int lev = 1, width = 1;
	// 2���� ���� Ʈ�� �ִ� ���̱��� Ž���ϸ鼭 �ִ� �ʺ� ����
	for (int i = 2; i <= depth; i++)
	{
		int cur = maxLev[i] - minLev[i] + 1; // �ʺ� ���
		// �ִ� ����
		if (width < cur)
		{
			lev = i; // ���� ����
			width = cur;
		}
	}
	cout << lev << ' ' << width << '\n';
}