#include<iostream>
#include<vector>
#include "fenwicktree.h"

using namespace std;

// �Ű��� Ƚ���� �������� ��ȯ�Ѵ�
long long countMoves(const vector<int>& a)
{
	// ���� ī�����ϴ� ����Ʈ��
	fenwick_tree<int> tree(1000000);
	long long ret = 0; // ������
	for (int i = 0; i < a.size(); i++)
	{
		// a[i]���� �� ū���� ������ �����Ѵ�
		ret += tree.sum(999999) - tree.sum(a[i]);
		tree.add(a[i], 1); // ���� ���� ����Ʈ���� ī�����Ѵ�
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << countMoves(a) << '\n';
	}
}