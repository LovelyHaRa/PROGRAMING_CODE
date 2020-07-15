#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// �̵� ������
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };
vector<string> adj; // ���� ���
vector<vector<int>> visited; // �湮 ���� ���� ���
vector<int> res; // ������ ��ȣ ����
int n, cnt; // �簢�� ����, ������ ī���� ����

void dfs(int x, int y)
{
	visited[x][y] = 1; // �湮 üũ
	cnt++; // ���� ī����
	// 4���⳻�� ���� ������ dfs ȣ��
	for (int i = 0; i < 4; i++)
	{
		int nextx = x + dx[i], nexty = y + dy[i];
		if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < n && !visited[nextx][nexty] && adj[nextx][nexty] == '1')
			dfs(nextx, nexty);
	}
}

int main(void)
{
	cin >> n;
	adj.resize(n);
	visited.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		cin >> adj[i];
	// ��������� Ž���ϸ鼭 dfs ȣ��
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cnt = 0;
			if (!visited[i][j] && adj[i][j] == '1')
			{
				dfs(i, j);
				// dfs�� ������ ���� �ϳ��� ������
				res.push_back(cnt);
			}			
		}
	}
	sort(res.begin(), res.end()); // �������� ����
	cout << res.size() << '\n'; // ���� ���� ���
	// ������ ī��Ʈ ���
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << '\n';
}