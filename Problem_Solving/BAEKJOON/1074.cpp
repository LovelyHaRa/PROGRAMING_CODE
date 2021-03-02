#include<iostream>

using namespace std;

int n, r, c, res;

void Z(int x, int y, int size)
{
	// ��ġ�� �����ϸ�
	if (x == r && y == c)
	{
		cout << res << '\n';
		return;
	}
	// �����ȿ� ���ϸ�
	if (r >= x && r < x + size && c >= y && c < y + size)
	{
		// Z��� ��� Ž��
		Z(x, y, size / 2); // �»��
		Z(x, y + size / 2, size / 2); // ����
		Z(x + size / 2, y, size / 2); // ���ϴ�
		Z(x + size / 2, y + size / 2, size / 2); // ���ϴ�
	}
	else res += size * size; // �׷��� ������ �ش� ��и� �ǳʶٱ�
}

int main(void)
{
	cin >> n >> r >> c;
	Z(0, 0, 1 << n);
}