#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }

int main(void)
{
	int n, k;
	cin >> n >> k;
	queue<pair<int, int>> q; // ��ġ, �ش� ��ġ���� �ɸ� �ð��� ���� �����ϴ� ť
	vector<bool> visited(100001); // �湮 ����
	// �ʱ� ť ����
	q.push(make_pair(n, 0));
	visited[n] = n;
	int res=100001;
	// BFS Ž��
	while (!q.empty())
	{
		// ť���� ����
		int x = q.front().first; // ���� ��ġ
		int sec = q.front().second; // �ɸ� �ð�
		q.pop();
		// �ش� ��ġ���� �����ϴ� ��� ������ üũ�ϰ� �ɸ� �ð��� �ּڰ��� ��� ����
		// �湮 üũ�� ť���� ���� �� �Ѵ�
		visited[x] = 1;
		// ��ǥ ��ġ�� �����ϸ�
		if (x == k)
		{
			res = min(res, sec); // �ּڰ� ����
			continue;
		}
		// ����, ������ �̵�
		for (int next : {x - 1, x + 1})
		{
			// ���� ���̰� �湮���� �ʾҴٸ�
			if (next >= 0 && next <= 100000 && !visited[next])
				q.push(make_pair(next, sec + 1)); // ť�� ����
		}
		// �����̵�
		// ���� ���̰� �湮���� �ʾҴٸ�
		if (x * 2 <= 100000 && !visited[x * 2])
			q.push(make_pair(x * 2, sec)); // �����̵��� �ð� �ҿ� ����
	}
	cout << res << '\n';
}