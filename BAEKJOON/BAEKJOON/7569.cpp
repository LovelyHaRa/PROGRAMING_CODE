#include<iostream>
#include<queue>

using namespace std;

int adj[100][100][100]; // ����, ����, ���� ���� ���
bool visited[100][100][100]; // ����, ����, ���� �湮����

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, h;
	cin >> m >> n >> h;
	queue<pair<int, pair<int, int>>> q; // ����, ����, ���� ��� ����
	int seq = 0, curSeq, day = 0; // ť�� ����� Ƚ��, ����� ��
	// �Է�
	for (int i = h - 1; i >= 0; i--)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
			{
				cin >> adj[i][j][k];
				// ���� �丶���� �� ť�� �ʱⰪ���� �߰�
				if (adj[i][j][k] == 1)
				{
					// ť�� ����
					q.push(make_pair(i, make_pair(j, k)));
					seq++; // ť�� ����� Ƚ�� ����
				}
			}
	// 6���� ������
	int dx[] = { -1,0,0,1,0,0 }, dy[] = { 0,-1,1,0,0,0 }, dz[] = { 0,0,0,0,-1,1 };
	// BFS Ž��
	while (!q.empty())
	{
		curSeq = 0; // ���� �Ͽ��� ť�� ����� Ƚ���� ī�����ϱ����� �ʱ�ȭ
		bool flag = 0; // �ϳ��� ������ �丶�並 �Ͱ��ߴ��� ����
		// ������ ť�� ����� Ƚ����ŭ ť���� ����(�Ϸ�)
		for (int i = 0; i < seq; i++)
		{
			// ť���� ����
			int x = q.front().second.first, y = q.front().second.second, z = q.front().first;
			q.pop();
			// 6���� Ž��
			for (int j = 0; j < 6; j++)
			{
				// ��ǥ ����
				int nx = x + dx[j], ny = y + dy[j], nz = z + dz[j];
				// �̵� ���� ���� �Ǵ�
				if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h || visited[nz][nx][ny] || adj[nz][nx][ny])
					continue;
				curSeq++; // ť�� ����� Ƚ�� ����
				flag = 1; // �丶�並 �Ͱ� �����Ƿ� true�� ����
				visited[nz][nx][ny] = 1; // �湮���� ����
				q.push(make_pair(nz, make_pair(nx, ny))); // ť�� ����
			}
		}
		if (flag) day++; // �丶�並 �Ͱ� ������ ��¥ ����
		seq = curSeq; // ť�� ����� Ƚ�� ����
	}
	// ���� ��� Ž��
	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for(int k = 0; k < m; k++)
				// �̹湮�ǰ� ������ �丶�� �߰� ��
				if (!visited[i][j][k] && !adj[i][j][k])
				{
					cout << "-1\n"; // ��� ���� ���ϴ� ��Ȳ
					return 0;
				}
	cout << day << '\n'; // ��� �;��ٸ� �ɸ� �� �� ���
}