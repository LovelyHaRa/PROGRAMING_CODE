#include<iostream>
#include<vector>

using namespace std;
int n, k;
vector<int> l, m, g;

int min(int a, int b) { return a < b ? a : b; }

// ���� ����: 0~dist������ �Ÿ��� �޸��鼭 ǥ������ k�� �̻� �� �� �ִ� ���θ� ��ȯ
bool decision(int dist)
{
	int ret = 0; // �߰��� ǥ���� ����
	// ���� Ž��
	for (int i = 0; i < n; i++)
	{
		// �Ÿ��� �ش� ���� ǥ���Ǻ��� ũ�� ���� ���� �������� �ǹ�
		if (dist >= l[i] - m[i])
			ret += (min(dist, l[i]) - (l[i] - m[i])) / g[i] + 1; // �ش� ����(0����)���� ǥ������ �����Ƿ� +1
	}
	return ret >= k; // ǥ������ k�� �̻��̸� true
}

// ����ȭ ����: k ǥ������ �߰��� �� �ִ� �ּ� �Ÿ��� ���Ѵ�(�̺� Ž��)
int optimize()
{
	int lo = -1, hi = 8030001; // �ִ� �Ÿ�
	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;
		// ǥ������ k�� �̻� �߰��� �� ������
		if (decision(mid))
			hi = mid; // �� ���� ���� ã�´�
		// �׷��� ������
		else
			lo = mid; // �� ū ���� ã�´�
	}
	return hi;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		l.resize(n);
		m.resize(n);
		g.resize(n);
		for (int i = 0; i < n; i++)
			cin >> l[i] >> m[i] >> g[i];
		cout << optimize() << '\n';
	}
}