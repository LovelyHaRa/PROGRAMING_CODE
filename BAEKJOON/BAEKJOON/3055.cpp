#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int main(void)
{
	int r, c;
	cin >> r >> c;
	vector<string> map(r); // ���� ����
	queue<pair<int, int>> water_pos; // �ʱ⿡ ���� �� �ִ� ������ ��ǥ
	queue<pair<int, int>> q; // ����ġ �̵� ��ǥ
	//  ��ǥ �� ���� ��������� �ð�, ��ǥ �� �̵� �ð�
	vector<vector<int>> water_map(r, vector<int>(c)), check(r, vector<int>(c));
	for (int i = 0; i < r; i++)
	{
		cin >> map[i];
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] == '*') water_pos.push(make_pair(i, j)); // ���� �� �ִ� ���� ��ǥ�� ť�� ����
			else if (map[i][j] == 'S') q.push(make_pair(i, j)); // ���� ���� ť�� ����
		}
	}
	int dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 }; // �����¿� �̵� ������
	// ���� ���� �ð��� �˱� ���� BFS Ž��
	while (!water_pos.empty())
	{
		// ť���� ����
		int x = water_pos.front().first;
		int y = water_pos.front().second;
		water_pos.pop();
		// �����¿� �̵�
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i]; // ���ο� ��ǥ ��
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue; // ���� ���̸� �ǳʶٱ�
			// ���� �̵��� �� �ִ� ������ �̵�
			if (!water_map[nx][ny] && map[nx][ny] == '.')
			{
				water_map[nx][ny] = water_map[x][y] + 1; // �ð� ����
				water_pos.push(make_pair(nx, ny)); // ť�� ����
			}
		}
	}
	// ����ġ �̵� BFS Ž��
	while (!q.empty())
	{
		// ť���� ����
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		// ��������: ���������� ���� ��
		if (map[x][y] == 'D')
		{
			// ��� �� ���α׷� ����
			cout << check[x][y] << '\n';
			return 0;
		}
		// �����¿� �̵�
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i]; // ���ο� ��ǥ ��
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue; // ���� ���̸� �ǳ� �ٱ�
			// �̵� ������ ����
			// 1. �湮���� ���� ���
			// 2. ���������� ���
			// 3. ����ִ� ���̸鼭 ���� �ƿ� �������� ���� �����̰ų� ���� ���� �ð��� ���� ��ġ + 1 ���� ũ��
			if (!check[nx][ny] && (map[nx][ny] == 'D' || (map[nx][ny] == '.' && (!water_map[nx][ny] || water_map[nx][ny] > check[x][y] + 1))))
			{
				check[nx][ny] = check[x][y] + 1; // �̵� �ð� ���
				q.push(make_pair(nx, ny)); // ť�� ����
			}		
		}
	}
	cout << "KAKTUS\n"; // �Ұ����� ��� ���
}