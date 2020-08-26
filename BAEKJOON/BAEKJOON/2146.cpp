#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> adj; // ���� ���
vector<vector<int>> visited; // �湮 ����
// ��ǥ �̵� ������
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };
int n;

// dfs Ž���� �̿��� ���� ��ȣ�� ����
void dfs(int x, int y, int num)
{
	visited[x][y] = 1; // �湮 üũ
	adj[x][y] = num; // ��ȣ �ο�
	// �����¿� �̵�
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		// dfs Ž��
		if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && adj[nx][ny])
			dfs(nx, ny, num);
	}
}

// bfs Ž���� �̿��� Ư�� ������ �ٸ� �������� �ּ� �Ÿ��� ����
int bfs(int num)
{
	// �ʱ� ť ����
	queue<pair<int, int>> q;
	// Ư�� ���� ��ǥ�� ��� ť�� ����
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if (adj[i][j] == num)
			{
				visited[i][j] = 1; // �湮 üũ
				q.push(make_pair(i, j)); // ť�� ����
			}
	int dist = 0; // �ٸ� �������� �ּ� �Ÿ�
	while (!q.empty())
	{
		int curSize = q.size(); // �̹� ���������� ť ������
		// ť ����� 0�� �ɶ� ���� �ݺ�
		while (curSize-- > 0)
		{
			// ť���� ����
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			// �����¿� �̵�
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i], ny = y + dy[i];
				// ������ �����ϸ�
				if (nx >= 0 && nx < n && ny >= 0 && ny < n)
				{
					int k = adj[nx][ny];
					// �ٸ� ���� ���
					if (k && k != num)
						return dist; // �Ÿ� ����
					// �ٴ��� ���
					else if (!k && !visited[nx][ny])
					{
						visited[nx][ny] = 1; // �湮 üũ
						q.push(make_pair(nx, ny)); // ť�� �߰�
					}
				}
			}
		}
		dist++; //�Ÿ� 1 ����
	}
}

int min(int a, int b) { return a < b ? a : b; }

int main(void)
{	
	// �Է�
	cin >> n;
	adj.resize(n, vector<int>(n));
	visited.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> adj[i][j];
	// �� ��ȣ
	int num = 1;
	// ���� ��ȣ �ο�
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!visited[i][j] && adj[i][j])
				dfs(i, j, num++);

	int res = 198765; // �Ÿ��� �ּڰ�
	// ��� ���� ���Ͽ� bfs Ž��
	for (int i = 1; i < num; i++)
	{
		// �湮 ���� �迭 �ʱ�ȭ
		visited.clear();
		visited.resize(n, vector<int>(n));
		// bfs Ž�� �� �ּڰ� ����
		res = min(res, bfs(i));
	}

	cout << res << '\n';
}