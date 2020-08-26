#include<iostream>
#include<queue>
#include<vector>
#include<stack>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	queue<int> q;
	vector<int> visited(100001, -1); // visited[x] = x��ġ�� ���� ��ġ�� ����
	int sec = 0; // �ɸ� �ð�
	// �ʱ� ť ����
	visited[n] = n;
	q.push(n);
	// BFS Ž��
	while (!q.empty())
	{
		// ���� ť �����ŭ ť���� ������, ��� ������ sec ����
		int curSize = q.size();
		while (curSize--)
		{
			// ť���� ����
			int x = q.front();
			q.pop();
			// ����� ���� ���������̸�
			if (x == k)
			{
				cout << sec << '\n'; // �ɸ� �ð� ���
				stack<int> route; // ��θ� �������� ����
				int r = k; // ���ŵ� ��θ� �����ϴ� ����
				while (r != n)
				{
					route.push(r); // ��θ� ���ÿ� ����
					r = visited[r]; // ��� ����
				}
				route.push(n); // ��� ���� ���ÿ� ����
				// ��θ� ���ÿ��� �̾� ���
				while (!route.empty())
				{
					cout << route.top() << ' ';
					route.pop();
				}
				cout << '\n';
				return 0; // ���α׷� ����
			}
			// �� �� �ִ� ��ġ�� ��� Ž��
			for (int next : {x - 1, x + 1, x * 2})
			{
				// ���� �ȿ� ��� �湮���� �ʾҴ����
				if (next >= 0 && next <= 100000 && visited[next] == -1)
				{
					visited[next] = x; // ��� ����
					q.push(next); // ť�� ����
				}
			}
		}
		sec++; // �ð� ����
	}
}