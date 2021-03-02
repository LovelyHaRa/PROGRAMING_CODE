#include<iostream>
#include<vector>

using namespace std;

int n, d, p, q;
vector<vector<int>> connected;
vector<int> deg;
vector<vector<double>> cache;

// days�� °�� here�� ������ �����ִٰ� �����ϰ�
// ������ ���� q�� ������ �������� ���Ǻ� Ȯ���� ��ȯ
double search(int here, int days)
{
	// ���� ���: days�� d�� �������� ��
	if (days == d) return (here == q ? 1.0 : 0.0);
	// �޸������̼�
	double& ret = cache[here][days];
	if (ret > -0.5) return ret;
	ret = 0.0;
	// ���Ǻ� Ȯ�� ���ϱ�
	for (int there = 0; there < n; there++)
		if (connected[here][there])
			ret += search(there, days + 1) / deg[here];
	return ret;
}

// ������ ����: �ڿ��� ���� ���
double optSearch(int here, int days)
{
	// ���� ���: days�� 0�� �������� ��
	if (days == 0) return (here == p ? 1.0 : 0.0);
	// �޸������̼�
	double& ret = cache[here][days];
	if (ret > -0.5) return ret;
	ret = 0.0;
	// ���Ǻ� Ȯ�� ���ϱ�
	for (int there = 0; there < n; there++)
		if (connected[here][there])
			ret += optSearch(there, days - 1) / deg[here];
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n >> d >> p;
		connected.resize(n + 1, vector<int>(n + 1, 0));
		cache.resize(n + 1, vector<double>(d + 1, -1));
		deg.resize(n + 1, 0);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> connected[i][j];
				if (connected[i][j]) deg[i]++; // ���� ���ϱ�
			}
		}
		int t;
		cin >> t;
		vector<double> ans(t);
		// ������ ����
		for (int i = 0; i < t; i++)
		{
			cin >> q;
			//ans[i] = search(p, 0); // ������ ���� q�� �������� Ȯ���� ���Ѵ�.
			//// ĳ�� �ʱ�ȭ
			//cache.clear();
			//cache.resize(n + 1, vector<double>(d + 1, -1));
			ans[i] = optSearch(q, d);
		}
		cout.precision(10);
		for (int i = 0; i < t; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		connected.clear();
		cache.clear();
		deg.clear();
	}
}