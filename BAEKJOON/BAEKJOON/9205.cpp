#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		n += 2; // ������ + �� + ��Ÿ��Ʈ
		// ��, ������, ��Ÿ��Ʈ ��ǥ ��� �迭
		vector<pair<int, int>> pos(n);
		// ��ǥ ��� �迭 �ε����� ������� �� ���� ���
		vector<vector<bool>> adj(n, vector<bool>(n));
		// ��ġ �Է� �ޱ�
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			pos[i] = { x,y };
			adj[i][i] = 1; // �ڱ� �ڽ��� ������ ����
		}
		// ��ǥ�� ������� ���� ��Ŀ� �����ϱ�
		for (int i = 0; i < n - 1; i++)
			for (int j = 1; j < n; j++)
			{
				// ����ư �Ÿ� ���ϱ�
				int dx = abs(pos[i].first - pos[j].first);
				int dy = abs(pos[i].second - pos[j].second);
				// 50*20 ���� ������ ���� �����ϴ�
				if (dx + dy <= 1000)
					adj[i][j] = adj[j][i] = 1;
			}
		// �÷��̵� �ͼ� �˰���
		// �߰�����
		for (int k = 0; k < n; k++)
			// ��������
			for (int i = 0; i < n; i++)
				// ��������
				for (int j = 0; j < n; j++)
					// ����-�߰� ������ �߰�-���� ������ ����Ǿ� �ִٸ� ����-���������� ����
					if (adj[i][k] && adj[k][j])
						adj[i][j] = 1;

		// ���� ��Ÿ��Ʈ �� �佺Ƽ�� ��Ұ� ����Ǿ� �ִٸ� happy, �׷��� �ʴٸ� sad ���
		cout << (adj[0][n - 1] ? "happy\n" : "sad\n");
	}
}