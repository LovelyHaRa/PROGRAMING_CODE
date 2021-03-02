#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// �׷��� ǥ��
vector<vector<int>> adj;
// �־��� �ܾ��κ��� ���ĺ� ���� ���İ��� �׷����� �����Ѵ�
void makeGraph(const vector<string>& words)
{
	adj = vector<vector<int>>(26, vector<int>(26, 0));
	for (int j = 1; j < words.size(); j++)
	{
		int i = j - 1, len = min(words[i].size(), words[j].size());
		for (int k = 0; k < len; k++)
			// word[i]�� word[j]�� �ѱ��ھ� ���Ѵ�
			// �ٸ��� �ش� ���ĺ��� ����׷����� ǥ���Ѵ�
			if (words[i][k] != words[j][k])
			{
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				adj[a][b] = 1;
				break;
			}
	}
}

vector<int> seen, order;
void dfs(int here)
{
	seen[here] = 1;
	for (int there = 0; there < adj.size(); there++)
		if (adj[here][there] && !seen[there])
			dfs(there);
	order.push_back(here); // ���� ������ ���� üũ
}
// �־��� �׷����� ���� ������ ����� ���T����.
// �׷����� DAG�� �ƴ϶�� �� ���͸� ��ȯ�Ѵ�
vector<int> topologicalSort()
{
	int n = adj.size();
	seen = vector<int>(n, 0);
	order.clear();
	// ��� ���ĺ��� ���� DFS Ž��
	for (int i = 0; i < n; i++) if (!seen[i]) dfs(i);
	// Ž�� ��� ������(���� ���� ���)
	reverse(order.begin(), order.end());
	// DAG�� �ƴ϶�� ���� ����� ������ ������ �ִ�.
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (adj[order[j]][order[i]])
				return vector<int>();
	// ���� ����� ���� ���� ��� ��ȯ
	return order;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		vector<string> words(n);
		for (int i = 0; i < n; i++)
			cin >> words[i];
		makeGraph(words);
		vector<int> res = topologicalSort();
		if (res.empty()) cout << "INVALID HYPOTHESIS\n";
		else
		{
			for (int i = 0; i < res.size(); i++)
				cout << (char)(res[i] + 'a');
			cout << '\n';
		}
	}
}