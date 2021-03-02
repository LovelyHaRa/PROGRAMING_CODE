#include<iostream>
#include<queue>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

bool check[1001][1001] = { 0, }; // �� ���� ���� �湮 ����

int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;
	int d = a + b + c;
	// 1. ���� 3���� ������ �������� ������ �Ұ���
	if (d % 3) { cout << "0\n"; return 0; }
	// �ʱ� ť ����
	queue <pair<int, int>> q;
	q.push(make_pair(a, b));
	check[a][b] = 1;
	// BFS Ž��
	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();
		int z = d - x - y; // ������ �ϳ��� �� ���ϱ�
		// ���� ��� ������ ��� �� ����
		if (x == y && y == z)
		{
			cout << "1\n";
			return 0;
		}
		// (x,y) (x,z) (y,z) �� ���ؼ� Ž��
		int nx[] = { x,x,y }, ny[] = { y,z,z };
		for (int i = 0; i < 3; i++)
		{
			x = nx[i], y = ny[i];
			// ������ �ǳʶٱ�
			if (x == y)  continue;
			// x,y ����
			if (x > y)	x -= y, y *= 2;
			else y -= x, x *= 2;
			// ������ �ϳ� ���ϱ�
			z = d - x - y;
			// �ߺ��� ���ϱ� ���� �� ���� �ִ�/�ּҰ��� ����
			int X = min(min(x, y), z), Y = max(max(x, y), z);
			// ť�� ����
			if (!check[X][Y])
			{
				check[X][Y] = 1;
				q.push(make_pair(X, Y));
			}
		}
	}
	// �Ұ��� �� ���
	cout << "0\n";
}