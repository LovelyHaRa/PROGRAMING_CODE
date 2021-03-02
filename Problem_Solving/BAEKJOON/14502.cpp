#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> map; // ������ ����
vector<pair<int, int>> virus; // �ʱ� ���̷��� ��ġ
int n, m, maxArea;

// ���̷��� Ȯ�� �ùķ��̼�
int diffusion()
{
	vector<vector<int>> nextMap = map;
	vector<vector<bool>> checked(n, vector<bool>(m));
	// �ʱ� ť ����
	queue<pair<int, int>> q;
	int dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 };
	for (int i = 0; i < virus.size(); i++)
	{
		q.push(virus[i]);
		checked[virus[i].first][virus[i].second] = 1;
	}
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
			// ���� ��, �̹� �湮, ���� �ǳʶٱ�
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || checked[nx][ny] || nextMap[nx][ny] == 1) continue;
			checked[nx][ny] = 1; // üũ
			nextMap[nx][ny] = 2; // ���̷��� Ȯ��
			// ť�� �߰�
			q.push(make_pair(nx, ny));
		}
	}
	// ���� ���� ���
	int safeArea = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			safeArea += !nextMap[i][j];
	return safeArea;
}

// ������ ��� �� ��ġ
void buildWail(int cnt)
{
	// �� ��ġ �Ϸ�
	if (cnt == 3)
	{
		int area = diffusion(); // ���̷��� Ȯ��
		if (maxArea < area) maxArea = area; // �������� �ִ� ����
		return;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!map[i][j])
			{
				map[i][j] = 1;
				buildWail(cnt + 1); // DFS Ž��
				map[i][j] = 0;
			}
}

int main(void)
{
	cin >> n >> m;
	map.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2) virus.push_back(make_pair(i, j));
		}
	buildWail(0);
	cout << maxArea << '\n';
}