#include<iostream>
#include<queue>

using namespace std;

// �Էµ� �̸�Ƽ�� ����, Ŭ������ ������, �Էµ� ���� �ð�
struct emoticon {
	int length, clipboard, time;
};

int main(void)
{
	int s;
	cin >> s;
	queue<emoticon> q;
	// visited[x][y] ���̰� x�̰� Ŭ������ ����� y�� ���� �湮 ����
	bool visited[1001][1001] = { false, };
	// �ʱ� ť
	q.push({1,0,0});
	visited[1][0] = 1;
	// BFS Ž��
	while (!q.empty())
	{
		// ť���� ����
		int k = q.front().length; // ����
		int c = q.front().clipboard; // Ŭ������ ������
		int sec = q.front().time; // �ð�
		q.pop();
		// ���̰� ��ǥ�� ��ġ�ϸ�
		if (k == s)
		{
			// ��� �� ����
			cout << sec << '\n';
			return 0;
		}
		// ���̰� ���� ���̸�
		if (k > 0 && k <= 1000)
		{
			// 1. Ŭ�����忡 ����
			if (!visited[k][k])
			{
				visited[k][k] = 1;
				q.push({ k,k,sec + 1 });
			}
			// 2. Ŭ������ ������ �ٿ� �ֱ�
			if (k + c <= 1000 && !visited[k + c][c])
			{
				visited[k + c][c] = 1;
				q.push({ k + c,c,sec + 1 });
			}
			// 3. ������ �ϳ� �����
			if (!visited[k - 1][c])
			{
				visited[k - 1][c] = 1;
				q.push({ k - 1,c,sec + 1 });
			}
		}
	}
}