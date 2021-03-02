#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1, vector<int>()); // ���� ����Ʈ�� ǥ��(���� ����� �޸� �ʰ�)
	// �Է�
	for (int i = 0; i < n-1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> ans(n);
	for (int i = 0; i < n; i++)
		cin >> ans[i];
	vector<int> check(n + 1); // �湮 ����
	int pos = 1; // �湮 ���� �ε���
	// �ʱ� ť ����
	queue<int> q;
	q.push(1);
	check[1] = 1;
	// BFS Ž��
	while (!q.empty())
	{
		// ť���� ������
		int here = q.front();
		q.pop();
		// ���� ���: pos<n
		while (pos<n)
		{
			int there = ans[pos];
			int i;
			// �湮 ������ �����Ͽ� ����� ���� ��� ť�� �ֱ�
			for (i = 0; i < adj[here].size(); i++)
			{
				if (adj[here][i] == there && !check[there])
				{
					check[there] = 1;
					q.push(there);
					pos++; // �湮 ���� �ε��� ����
					break;
				}
			}
			// ����� ������ ��� ť�� �־����� �ݺ��� Ż��
			if (i == adj[here].size()) break;
		}
	}
	cout << (pos == n) << '\n'; // BFS Ž�� �߹湮 ���� �迭�� ��� �����ߴٸ� 1, �ƴϸ� 0
}