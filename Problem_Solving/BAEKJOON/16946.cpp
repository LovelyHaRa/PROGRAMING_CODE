#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int n, m;
vector<string> map; // �� ����
vector<vector<int>> moveableGroup; // �ʿ��� �̵������� �������� �׷�ȭ�� ����
vector<int> moveableCnt; // �׷캰 �̵������� ���� ����
vector<vector<bool>> visited; // BFS �湮 ����
int dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 }; // �����¿� ������

// BFS Ž�� �� �̵������� ���� ������ ��ȯ
int BFS(int startX, int startY, int groupIdx)
{
	int cnt = 1;
	// �ʱ� ť ����
	queue<pair<int, int>> q;
	visited[startX][startY] = 1;
	moveableGroup[startX][startY] = groupIdx;
	q.push(make_pair(startX, startY));
	// BFS Ž��
	while (!q.empty())
	{
		// ť���� ����
		int x = q.front().first, y = q.front().second;
		q.pop();
		// �����¿� �̵�
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i]; // ���� ��ǥ
			// ���� ��, �̹� �湮, ���̸� �ǳʶٱ�
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || map[nx][ny] == '1') continue;
			visited[nx][ny] = 1; // �湮 üũ
			moveableGroup[nx][ny] = groupIdx; // �׷� ��ȣ �ο�
			q.push(make_pair(nx, ny)); // ť�� �߰�
			cnt++; // �̵� ������ Ƚ�� ����
		}
	}
	return cnt;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	map.resize(n);
	moveableGroup.resize(n, vector<int>(m));
	visited.resize(n, vector<bool>(m));
	for (int i = 0; i < n; i++)
		cin >> map[i];
	int groupIdx = 1;
	// 1. �̵������� ���� �׷� ��ȣ �ο�
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!visited[i][j] && map[i][j] == '0')
				moveableCnt.push_back(BFS(i, j, groupIdx++));
	// 2. �� �μ��� �̵� ������ Ƚ�� ���
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// ���� ���
			if (map[i][j] == '1')
			{
				vector<bool> checked(moveableCnt.size()); // �׷� �ߺ� Ȯ�� �迭
				int cnt = 1; // ���� �����ϹǷ� �ʱ� ���´� 1
				// �����˿� Ž��
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k], ny = j + dy[k]; // ���� ��ǥ
					// ���� ���̸� �ǳʶٱ�
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					// �׷� ��ȣ ����
					groupIdx = moveableGroup[nx][ny];
					// ���̰ų� �̹� üũ�� �׷��̸� �ǳʶٱ�
					if (!groupIdx || checked[groupIdx - 1]) continue;
					checked[groupIdx - 1] = 1; // üũ
					cnt += moveableCnt[groupIdx - 1]; // ī����
				}
				cout << cnt % 10; // 10���� ���� ������ ���
			}
			else cout << 0; // �ƴϸ� 0 ���
		}
		cout << '\n';
	}
}