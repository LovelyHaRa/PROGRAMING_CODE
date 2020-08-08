#include<iostream>
#include<queue>
#include<vector>
#include<string>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }

int main(void)
{
	int m, n;
	cin >> m >> n;
	vector<string> adj(n);
	for (int i = 0; i < n; i++)
		cin >> adj[i]; // string �Է�(�پ �Էµ�)
	queue<pair<int, int>> q;
	// broken[x][y] (x, y)���� ������ �� ���� �μ� ���� �ּ� ����
	vector<vector<int>> broken(n, vector<int>(m, 123456));
	// �����¿� �̵� ������
	int dx[] = { 1,0,-1,0 };
	int dy[] = { 0,1,0,-1 };
	// �ʱ� ť
	q.push(make_pair(0, 0));
	broken[0][0] = 0;
	// BFS Ž��
	while (!q.empty())
	{
		// ť���� ����
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		// �����¿� �̵�
		for (int i = 0; i < 4; i++)
		{
			// �̵� �� ��ġ��
			int nx = x + dx[i];
			int ny = y + dy[i];
			// ���� �ȿ� ���ϴ� �� Ȯ��
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				// �̵� �� ���� ���� ������
				if (adj[nx][ny] == '1')
				{
					// ���� ���� �μ� ���� �ּ� ���� ����(���ͽ�Ʈ��)
					// ���� �ֱ� ������ ���� ��ġ���� 1 ������ ���� ��
					if (broken[nx][ny] > broken[x][y] + 1)
					{
						broken[nx][ny] = broken[x][y] + 1;
						// ť�� �߰�(�ߺ����� �߰��� ���� ������ ���귮�� �����Ƿ� ����)
						q.push(make_pair(nx, ny));
					}
				}
				// ���� ������
				else
				{
					// ���� ���� �μ� ���� �ּ� ���� ����(���ͽ�Ʈ��)
					// ���� ���� ������ ���� ��ġ�� �״�� ��
					if (broken[nx][ny] > broken[x][y])
					{
						broken[nx][ny] = broken[x][y];
						// ť�� �߰�(�ߺ����� �߰��� ���� ������ ���귮�� �����Ƿ� ����)
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
	// Ž�� �� �μ� ���� �ּڰ� ���
	cout << broken[n - 1][m - 1] << '\n';
}