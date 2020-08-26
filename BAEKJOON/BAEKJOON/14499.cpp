#include<iostream>

using namespace std;

const int MAP_SIZE = 20;

int main(void)
{
	int n, m, x, y, k;
	int dice[7] = { 0 }; // �ֻ��� �迭, ������ 1 �Ʒ����� 6
	int map[MAP_SIZE][MAP_SIZE] = { 0 }; // ����
	int dx[4] = { 0,0,-1,1 }; // ��ɿ� ���� x��ǥ �̵� ũ��
	int dy[4] = { 1,-1,0,0 }; // ��ɿ� ���� y��ǥ �̵� ũ��
	// �Է�
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}
	// ��� ó��
	for (int i = 0; i < k; i++)
	{
		int order;
		cin >> order;
		// �̵� ��ǥ ���
		int xx, yy;
		xx = x + dx[order - 1];
		yy = y + dy[order - 1];
		// ��ǥ�� �����ȿ� �ִ��� �Ǵ�
		if (!(xx >= 0 && xx < n&&yy >= 0 && yy < m))
			continue;
		//�̵� ��ǥ ����
		x = xx;
		y = yy;
		// ��ɿ� ���� �ֻ��� �ε��� ��ü
		switch (order)
		{
		case 1:
			swap(dice[1], dice[4]);
			swap(dice[3], dice[4]);
			swap(dice[4], dice[6]);
			break;
		case 2:
			swap(dice[1], dice[3]);
			swap(dice[3], dice[6]);
			swap(dice[6], dice[4]);
			break;
		case 3:
			swap(dice[1], dice[2]);
			swap(dice[2], dice[6]);
			swap(dice[6], dice[5]);
			break;
		case 4:
			swap(dice[1], dice[5]);
			swap(dice[5], dice[6]);
			swap(dice[6], dice[2]);
		}		
		// ���ǿ� �°� ������ ����
		if (map[x][y] == 0)
			map[x][y] = dice[6];
		else
		{
			dice[6] = map[x][y];
			map[x][y] = 0;
		}
		// ���� ���
		cout << dice[1] << endl;
	}
}