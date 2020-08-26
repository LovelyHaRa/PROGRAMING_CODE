#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> adj; // ���� ���
vector<vector<int>> visited; // �� ������ ���� �湮 ����
int w, h;

void dfs(int x, int y)
{
	visited[x][y] = 1;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			// ���� ���� ������, �̹湮��������, ������ �Ǵ��ϰ� dfsŽ��
			if ((x + i) >= 0 && (x + i) < h && (y + j) >= 0 && (y + j) < w && !visited[x + i][y + j] && adj[x + i][y + j])
				dfs(x + i, y + j);
		}
	}
}

int main(void)
{
	while (1)
	{
		cin >> w >> h;
		if (!w && !h)
			break;
		adj.resize(h, vector<int>(w));
		visited.resize(h, vector<int>(w));
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> adj[i][j];
		int cnt = 0;
		// ��� ���� Ž��
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				// �湮���� ���� ���� dfs Ž��
				if (!visited[i][j] && adj[i][j])
				{
					dfs(i, j);
					cnt++; // dfs�� ȣ��� Ƚ���� ������Ʈ�� ����
				}

			}
		}
		cout << cnt << '\n';
		adj.clear();
		visited.clear();
	}
}