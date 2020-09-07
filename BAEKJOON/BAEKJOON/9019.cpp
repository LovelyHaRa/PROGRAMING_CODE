#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		bool visited[10000] = { false, }; // �湮 ����
		queue<pair<int, string>> q; // ����, ���ݱ��� �Էµ� ��ɾ ���� �ϴ� ť ����
		// �ʱ� ť ����
		q.push(make_pair(a, ""));
		visited[a] = 1;
		// BFS Ž��
		while (!q.empty())
		{
			// ť���� ����
			int curNum = q.front().first;
			string curCmd = q.front().second;
			q.pop();
			// ��ǥ ���ڿ� �����ϸ�
			if (curNum == b) {
				//��� �� Ž�� ����
				cout << curCmd << '\n';
				break;
			}
			// ���� ��ȣ ���
			int next = curNum * 2 % 10000;
			if (!visited[next])
			{
				visited[next] = 1;
				q.push(make_pair(next, curCmd + 'D'));
			}
			next = curNum - 1 < 0 ? 9999 : curNum - 1;
			if (!visited[next])
			{
				visited[next] = 1;
				q.push(make_pair(next, curCmd + 'S'));
			}
			next = (curNum % 1000) * 10 + curNum / 1000; // ���� ����Ʈ
			if (!visited[next])
			{
				visited[next] = 1;
				q.push(make_pair(next, curCmd + 'L'));
			}
			next = curNum % 10 * 1000 + curNum / 10; // ������ ����Ʈ
			if (!visited[next])
			{
				visited[next] = 1;
				q.push(make_pair(next, curCmd + 'R'));
			}
		}
	}
}