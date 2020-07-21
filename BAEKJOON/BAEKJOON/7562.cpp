#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int l;
		cin >> l;
		int a, b, x, y; // ���� ��ġ (a, b), ��ǥ ��ġ (x, y)
		cin >> a >> b >> x >> y;
		vector<vector<int>> visited(l, vector<int>(l)); // ü���� ���� �湮 ����
		queue<pair<int, int>> q; // bfs queue
		// �ʱ����: ���������� ť�� ����
		visited[a][b] = 1; // üŷ
		q.push(make_pair(a, b));
		// ����Ʈ �̵� ���� ��ǥ
		int dx[] = { -1,-2,-2,-1,1,2,2,1 };
		int dy[] = { -2,-1,1,2,2,1,-1,-2 };
		// �ѹ� �̵����� �� ť�� �߰� Ƚ���� ����/����
		//moving: �̵�Ƚ��, flag: ��ǥ������ �����ϸ� Ż���ϱ� ���� �÷���
		int seq = 1, curSeq, moving = 0, flag = 0;
		// bfs Ž��
		while (!q.empty())
		{
			curSeq = 0;
			// ������ ť�� �߰��� Ƚ����ŭ ť���� ����(1�� �̵��Ҷ� ť�� �߰��� Ƚ��)
			for (int i = 0; i < seq; i++)
			{
				// ť���� ����
				int cx = q.front().first;
				int cy = q.front().second;
				q.pop();
				// ��ǥ���� ���޽� Ż��
				if (cx == x && cy == y)
				{
					flag = 1;
					break;
				}
				// ���� �������κ��� ����Ʈ �̵�
				for (int j = 0; j < 8; j++)
				{
					int nx = cx + dx[j], ny = cy + dy[j];
					// ü���� ���� ���̰� �ѹ��� üŷ���� �ʾ����� ť�� �߰�
					if (nx >= 0 && nx < l && ny >= 0 && ny < l && !visited[nx][ny])
					{
						visited[nx][ny] = 1; // üŷ
						q.push(make_pair(nx, ny));
						curSeq++; // ť�� �߰��� Ƚ�� �߰�
					}
				}
			}
			if (flag) break;
			seq = curSeq; // ť�� �߰��� Ƚ�� ����
			moving++; // �̵� Ƚ�� ����
		}
		cout << moving << '\n'; // �̵�Ƚ�� ���
	}

}