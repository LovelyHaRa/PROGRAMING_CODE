#include<iostream>

using namespace std;

int main(void)
{
	int e, s, m;
	cin >> e >> s >> m;
	int year = 1;
	int ee=1, ss=1, mm=1;
	// ����Ž��
	while (ee != 15 || ss != 28 || mm != 19)
	{
		// ���ǿ� �´� �����̸� ���� ���
		if (e == ee && s == ss && m == mm )
		{
			cout << year << '\n';
			break;
		}
		// �������� 0�̵Ǹ� 1�� �ʱ�ȭ
		ee = !((ee + 1) % 16) ? 1 : (ee + 1) % 16;
		ss = !((ss + 1) % 29) ? 1 : (ss + 1) % 29;
		mm = !((mm + 1) % 20) ? 1 : (mm + 1) % 20;
		year++;
	}
	// ������ Ž������ ���
	if (ee == 15 && ss == 28 && mm == 19)
		cout << year << '\n';
}