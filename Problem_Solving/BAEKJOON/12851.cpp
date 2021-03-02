#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }

int main(void)
{
	int n, k;
	cin >> n >> k;
	queue<pair<int, int>> q; // ���� ����, �ɸ� �ð��� ���� ������ �� �ִ� ť
	vector<bool> visited(100001); // �湮 ���� üũ
	vector<int> cnt(100001);// cnt[sec] = sec���� ��, k������ ������ Ƚ��
	// �ʱ� ť
	q.push(make_pair(n, 0));
	int res = 100001; // �ɸ� �ð��� �ּڰ�(��� ���)
	// BFS Ž��
	while (!q.empty())
	{
		int x = q.front().first;
		int sec = q.front().second;
		q.pop();
		visited[x] = true; // ť���� ������ �� �湮 üũ
		// ��ǥ������ �������� ��
		if (x == k)
		{
			cnt[sec]++; // ī����
			res = min(res, sec); // �ɸ��ð� �ּڰ� ����
		}
		// 3���� �̵� �� �� �ִ� ��쿡 ����
		for (int next : {x - 1, x + 1, x * 2})
		{
			// ���� ���̰� �湮�� ���� ���ٸ�
			if (next >= 0 && next <= 100000 && !visited[next])
				q.push(make_pair(next, sec + 1)); // ť�� �̵� ���� ���� �ð��� �������� ����
		}
	}
	cout << res << '\n' << cnt[res] << '\n'; // �ð��� �ּڰ��� �׿� �ش��ϴ� ī���� ���� ���
}