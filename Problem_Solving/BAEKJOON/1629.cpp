// ��������
#include <iostream>

using namespace std;

long long a, b, c;

// �Ϲ����� ���� ��ʹ� O(N)
// ���� ������ �̿��Ͽ� O(logN)���� ������ �� �ִ�.
long long multi(int a, int b)
{
	if (!b)
		return 1;
	if (b == 1)
		return a;
	if (b % 2)
		return multi(a, b - 1)*a; // Ȧ���� a^(b-1)*a�� ���� ����
	long long h = multi(a, b / 2); // ¦���� a^(b/2)*a^(b/2)�� ���� ����
	// ��� �߰��� ���� �������� ��� ����� ���� �� ���� �������� ����
	h %= c;
	return (h*h) % c;

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> c;
	
	cout << multi(a, b) % c << '\n';

}