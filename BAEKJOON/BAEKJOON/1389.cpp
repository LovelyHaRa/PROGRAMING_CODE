#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	int INF = 101;
	vector<vector<int>> adj(n + 1, vector<int>(n + 1, INF));
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x][y] = adj[y][x] = 1; // ģ������ ǥ��
		// ģ���� ���� ����� �����Ƿ� �Է��� ���� �� �ڱ� �ڽ��� 0���� �ʱ�ȭ �� �� �ִ�
		adj[x][x] = adj[y][y] = 0;
	}
	// �÷��̵� �ͼ� �˰��� �̿�
	// �߰� ����
	for (int k = 1; k <= n; k++)
		// ���� ����
		for (int i = 1; i <= n; i++)
			// ���� ����
			for (int j = 1; j <= n; j++)
				// ����-�߰�+�߰�-���� ���� ����-���� �Ÿ��� ������ ����
				if (adj[i][j] > adj[i][k] + adj[k][j])
					adj[i][j] = adj[i][k] + adj[k][j];
	int min_val = INF, res = 0;
	// �ɺ� ������ ���ϱ�
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		// ���ϱ�
		for (int j = 1; j <= n; j++)
			sum += adj[i][j];
		// �ּڰ� ����
		if (min_val > sum)
		{
			res = i;
			min_val = sum;
		}
	}
	cout << res << '\n';
}