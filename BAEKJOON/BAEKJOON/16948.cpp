#include<iostream>
#include<queue>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	bool visited[200][200] = { 0, }; // ��ǥ �湮 ����
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	// �̵� ������
	int dr[] = { -2,-2,0,0,2,2 };
	int dc[] = { -1,1,-2,2,-1,1 };
	// �ʱ� ť ����
	queue<pair<int, int>> q;
	q.push(make_pair(r1, c1));
	visited[r1][c1] = 1;
	int moveCnt = 0; // �̵� Ƚ��
	// BFS Ž��
	while (!q.empty())
	{
		int curSize = q.size(); // ���� �̵��� ������ ���� �̵����� ������ ��� ����� ��
		while (curSize--)
		{
			// ���� ����
			int cr = q.front().first, cc = q.front().second;
			q.pop();
			// ��ǥ���� ���� Ȯ��
			if (cr == r2 && cc == c2)
			{
				// ��� �� ���α׷� ����
				cout << moveCnt << '\n';
				return 0;
			}
			// ��ǥ �̵� ����
			for (int i = 0; i < 6; i++)
			{
				int nr = cr + dr[i], nc = cc + dc[i]; // ��ǥ ����
				// ���� Ȯ��
				if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc]) continue;
				// �̵��� �� ������ �ǹ�
				visited[nr][nc] = 1; // �湮 üũ
				q.push(make_pair(nr, nc)); // ť�� �߰�
			}
		}
		moveCnt++;
	}
	cout << "-1\n"; // ��ǥ ��ġ�� �������� ����
}