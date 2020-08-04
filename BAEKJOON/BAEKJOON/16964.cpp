#include<iostream>
#include<vector>

using namespace std;

int n;
vector<vector<int>> adj; // ���� ����Ʈ ����
vector<int> check; // �湮 ����
vector<int> ans; // ���� ��ǲ
int idx = 1; // ���� �迭 ���� ���� ��ġ (1���� ����)

// dfs Ž��
void dfs(int x)
{
	// �̹� Ž���Ǿ��ų� ���� �迭�� ��� ���� �Ǿ��� ���
	if (check[x] || idx==n)
		return;
	// Ž�� üũ
	check[x] = 1;
	// ���� �������κ��� ����� �������� ��� �湮
	while (idx < n)
	{
		int y;
		// ����� ���� ��� Ž��
		for (y = 0; y < adj[x].size(); y++)
		{
			// ���� �迭�� ���� ��ġ�� ���� ������ ������
			if (ans[idx] == adj[x][y])
			{
				idx++; // ���� �迭 ������ġ ����
				dfs(adj[x][y]);  // dfs ��� Ž��
				break; // ������ ã�����Ƿ� ����
			}
		}
		// ������ ��ã�� ��� ����
		if (y == adj[x].size()) break;
	}
}

int main(void)
{
	// �Է�
	cin >> n;
	adj.resize(n + 1);
	check.resize(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ans.resize(n);
	for (int i = 0; i < n; i++)
		cin >> ans[i];
	// 1���� dfs Ž��
	dfs(1);
	// ����迭�� ��� Ž���Ǿ����� 1 �ƴϸ� 0
	cout << (idx == n) << '\n';
}