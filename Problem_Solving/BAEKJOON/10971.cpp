#include<iostream>
#include<vector>

using namespace std;

int n;
vector<vector<int>> dist;

int min(int a, int b) { return a < b ? a : b; }

// ���ݱ����� ��� path�� �湮���ΰ� �־����� ��, �ּҺ���� ��ȯ�Ѵ�
int shortestPath(vector<int>& path, vector<bool>& visited, int currentLength)
{
	// ���� ���: ��� ��θ� Ž�� ���� ��
	if (path.size() == n)
	{
		// �������� ����Ǿ��ִ��� Ȯ��
		if (dist[path.back()][path[0]] > 0)
			return currentLength + dist[path.back()][path[0]];
		return 1987654321; // ���� �ȵ������� ��ȸ �Ұ����̹Ƿ� ū �� ����
	}
	int ret = 1987654321;
	// ��� ���� Ž��
	for (int i = 0; i < n; i++)
	{
		int here = path.back();
		// �湮 �߰ų� ����Ǿ����� ���� ��� �ǳʶٱ�
		if (visited[i] || dist[here][i] == 0) continue;
		visited[i] = true; // �湮 üũ
		path.push_back(i); // ��� �߰�
		// ���� ��� Ž��
		int cand = shortestPath(path, visited, currentLength + dist[here][i]);
		// �ּ� ��� ����
		ret = min(cand, ret);
		// ���� ����
		visited[i] = false;
		path.pop_back();
	}
	return ret;
}

int main(void)
{
	cin >> n;
	dist.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> dist[i][j];
	int res = 1987654321;
	// ��� ��ġ���� ����
	for (int i = 0; i < n; i++)
	{
		// ������ path �߰� �� �湮 üũ
		vector<int> path(1, i);
		vector<bool> visited(n);
		visited[i] = true;
		// �ּ� ��� ����
		res = min(shortestPath(path, visited, 0), res);
	}
	cout << res << '\n';
}