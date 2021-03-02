#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void)
{
	int n; // ���� ũ��
	cin >> n;
	vector<vector<int>> space(n, vector<int>(n)); // ���� ���� ���
	pair<int, int> shark_pos; // �Ʊ� ��� ��ġ
	// �Է�
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> space[i][j];
			if (space[i][j] == 9)
			{
				shark_pos = { i,j };
				space[i][j] = 0;
			}
		}
	// �ּڰ� ������ ���� �Ѱ谪, �Ʊ� ��� ������, ���� Ƚ��, �� �̵��Ÿ�(��� ��)
	int limit = 401, shark_size = 2, eating = 0, res = 0;
	int dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 }; // �����¿� �̵� ������
	// ����Ⱑ ������ �� ���� �ݺ�
	while (1)
	{
		// �ּ� �Ÿ��� ���� ��ǥ ��, �ּ� �Ÿ�
		int min_x = limit, min_y = limit, min_dist = limit;
		// �̵� �Ÿ� �� �湮���� üũ
		vector<vector<int>> check(n, vector<int>(n, -1));
		// �ʱ� ť ����
		queue<pair<int, int>> q;
		q.push(shark_pos); 
		check[shark_pos.first][shark_pos.second] = 0;
		// BFS Ž��
		while (!q.empty())
		{
			// ť���� ��ǥ ����
			int x = q.front().first, y = q.front().second;
			q.pop();
			// �����¿� �̵�
			for (int i = 0; i < 4; i++)
			{
				// ���ο� ��ġ ��ǥ ��
				int nx = x + dx[i], ny = y + dy[i];
				// ���� ���̰ų� �̹� �湮 �߰ų� ����Ⱑ �Ʊ� ��� ũ�⺸�� ū ��� �ǳ� �ٱ�
				if (nx < 0 || nx >= n || ny < 0 || ny >= n || check[nx][ny] != -1 || space[nx][ny]>shark_size) continue;
				check[nx][ny] = check[x][y] + 1; // �Ÿ� ����
				// ���� �� �ִ� ���
				if (space[nx][ny] > 0 && space[nx][ny] < shark_size)
				{
					// �Ÿ��� �ּڰ� ����
					if (min_dist > check[nx][ny])
					{
						min_dist = check[nx][ny];
						min_x = nx;
						min_y = ny;
					}
					// �Ÿ��� �ּ� ���� ���ٸ�
					else if (min_dist == check[nx][ny])
					{
						// �»�� ��ġ ����
						if (min_x == nx)
							min_y = min_y > ny ? ny : min_y;
						else if (min_x > nx)
						{
							min_x = nx;
							min_y = ny;
						}
					}
				}
				// ť�� ��ǥ �� ����
				q.push(make_pair(nx, ny));
			}
		}
		// ���� �� �ִ� ����⸦ ã�Ҵٸ�
		if (min_x != limit)
		{
			res += check[min_x][min_y]; // �Ÿ� ����
			// �Ʊ� �� �ڱ� ũ�⸸ŭ ����⸦ �Ծ�����
			if (shark_size == ++eating)
			{
				// ũ�� ���� �� ���� ȱ�� �ʱ�ȭ
				shark_size++;
				eating = 0;
			}
			// ����� ���ֱ�
			space[min_x][min_y] = 0;
			// �Ʊ� ��� ��ġ ����
			shark_pos = { min_x,min_y };
		}
		else break; // ���� �� �ִ� ����Ⱑ ������ �����
	}
	cout << res << '\n'; // ��� ���
}