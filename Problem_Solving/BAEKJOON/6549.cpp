#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// �ּҰ��� ��ġ�� �����ϴ� ���׸�Ʈ Ʈ�� �ʱ�ȭ
void init(vector<int> &a, vector<int> &tree, int node, int start, int end)
{
	// ���� ����� ���
	if (start == end)
		tree[node] = start;
	else
	{
		// ��,�츦 ���� �ʱ�ȭ
		init(a, tree, node * 2, start, (start + end) / 2);
		init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
		// �ּڰ��� ��ġ ����
		if (a[tree[node * 2]] <= a[tree[node * 2 + 1]])
			tree[node] = tree[node * 2];
		else
			tree[node] = tree[node * 2 + 1];
	}
}

// ���� ���̰� ���� �簢���� ã�� �Լ�
int query(vector<int> &a, vector<int> &tree, int node, int start, int end, int i, int j)
{
	// [i, j]�� [start, end]�� ��ġ�� �ʴ� ���
	if (i > end || j < start)
		return -1; // Ž���� �̾�� �ʿ䰡 ����
	// [i, j]�� [start, end]�� ������ �����ϴ� ���
	if (i <= start && j >= end)
		return tree[node];
	// �� ��찡 �ƴ� ��� ���� ������ ������ �ٽ� Ž��
	int m1 = query(a, tree, 2 * node, start, (start + end) / 2, i, j);
	int m2 = query(a, tree, 2 * node + 1, (start + end) / 2 + 1, end, i, j);
	// ��ġ�� �ʴ� ��� ����
	if (m1 == -1)
		return m2;
	else if (m2 == -1)
		return m1;
	// Ž�� ��� �� ���̰� ���� �ε��� ��ȯ
	else
		return a[m1] <= a[m2] ? m1 : m2;
}

// �ִ� ���̸� ���ϴ� �Լ�
long long largest(vector<int> &a, vector<int> &tree, int start, int end)
{
	int n = a.size();
	// ���� �� �ּ� �簢�� ���̸� ã��
	int m = query(a, tree, 1, 0, n - 1, start, end);
	// ���� = �簢�� ���� * ����
	long long area = (long long)(end - start + 1)*(long long)a[m];
	// �ش� �簢�� ���� �κ� Ž���� ������ ��
	if (start <= m - 1)
	{
		long long temp = largest(a, tree, start, m - 1);
		// �ִ� ����
		if (temp > area)
			area = temp;
	}
	// �ش� �簢�� ������ �κ� Ž���� ������ ��
	if (end >= m + 1)
	{
		long long temp = largest(a, tree, m + 1, end);
		// �ִ� ����
		if (temp > area)
			area = temp;
	}
	return area;
}

int main()
{
	while (1)
	{
		int n;
		cin >> n;
		if (!n)break;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		// Ʈ�� ���� ���
		int h = (int)(ceil(log2(n)) + 1e-9);
		int tree_size = (1 << (h + 1));
		// Ʈ�� �迭 ����
		vector<int> tree(tree_size);
		init(a, tree, 1, 0, n - 1);
		cout << largest(a, tree, 0, n - 1) << '\n';
	}
}