#include<iostream>
#include<map>
#include<queue>
using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	// ��, ��ٸ� ���о��� map���� ����
	map<int, int> laddersnake;
	for (int i = 0; i < n + m; i++)
	{
		int key, value;
		cin >> key >> value;
		laddersnake[key] = value;
	}
	// �湮 ����
	bool visited[101] = { false, };
	// �ʱ� ť ����
	queue<int> q;
	q.push(1);
	int moveCnt = 0; // �̵� Ƚ��
	// BFS Ž��
	while (!q.empty())
	{
		// ���� �̵� Ƚ������ �������� �̵��� �� �ִ� ��� ����� ��
		int turnSize = q.size();
		// ��� ��� Ž��
		while (turnSize--)
		{
			// ť���� ����
			int cur = q.front();
			q.pop();
			// ��ǥĭ�� 100���� �����ϸ� ����ϰ� ����
			if (cur == 100)
			{
				cout << moveCnt << '\n';
				return 0;
			}
			// �ֻ����� 1���� 6���� ����
			for (int i = 1; i <= 6; i++)
			{
				int next = cur + i; // �ֻ��� �� ���ϱ�
				// �� �Ǵ� ��ٸ��� ������ ���
				if (laddersnake.find(next) != laddersnake.end())
					next = laddersnake[next]; // ĭ ��ȣ ����
				// �湮 ���� Ȯ��
				if (!visited[next])
				{
					visited[next] = 1; // �湮 üũ
					q.push(next); // ť�� ����
				}
			}
		}
		moveCnt++; // �̵� Ƚ�� ����
	}
}