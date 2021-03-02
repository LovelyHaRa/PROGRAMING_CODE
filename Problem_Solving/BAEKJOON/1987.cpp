#include<iostream>
#include<string>

using namespace std;

string board[20];
int r, c, dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 };

int max(int a, int b) { return a > b ? a : b; }

// (x, y) ��ġ���� 4�������� �̵��Ѵ�
// ��Ʈ����ũ�� �̿��Ͽ� ���ĺ��� üũ�Ѵ�(26�ڸ�, MSB: Z, LSB, A)
int move(int x, int y, int check)
{
	int ret = 0; // ���� ���������� �̵� Ƚ��
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i]; // ���� ��ġ ���
		// ������ ����ų� �̹� üũ�� ���ĺ��̸� �����Ѵ�
		if (nx < 0 || nx >= r || ny < 0 || ny >= c || check & 1 << board[nx][ny] - 65) continue;
		// 4���� �� ���� �ָ� �� �� �ִ� Ƚ���� ���Ѵ�
		ret = max(ret, move(nx, ny, check | 1 << board[nx][ny] - 65));
	}
	return ++ret; // �� ������ �湮 �����Ƿ� �̵� Ƚ���� 1 �߰��Ѵ�
}

int main(void)
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		cin >> board[i];
	cout << move(0, 0, 1 << board[0][0] - 65) << '\n';
}