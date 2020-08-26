#include<iostream>

using namespace std;

// ���� ũ��, ����, ������ ����(+, -, *, /), �ּ�/�ִ밪
int n, a[11], oper[4], _min = 1987654321, _max = 0 - 1987654321;

// oper �ε����� ���� a,b�� ���� ��� ��ȯ
int calc(int a, int b, int op)
{
	switch (op)
	{
	case 0:
		return a + b;
	case 1:
		return a - b;
	case 2:
		return a * b;
	case 3:
		return a / b;
	}
}

// ������ ���� ��ġ���� �κ� �� sum�� ���� ������ �����ڷ� ������ ��� ��츦 ���
void makeSum(int here, int sum)
{
	// ������ ���� ������ ��� �ּ�/�ִ밪 ����
	if (here == n - 1)
	{
		_min = _min > sum ? sum : _min;
		_max = _max < sum ? sum : _max;
		return;
	}
	// ��� �����ڿ� ���� ���
	for (int i = 0; i < 4; i++)
	{
		// �����ڰ� ������
		if (oper[i])
		{
			oper[i]--; // ������ ���� ����
			// �κ� �� ����
			int t = !here ? calc(a[here], a[here + 1], i) : calc(sum, a[here + 1], i);
			makeSum(here + 1, t); // ���� ���� Ž��
			oper[i]++; // ���� ����
		}
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < 4; i++)
		cin >> oper[i];
	makeSum(0, 0);
	cout << _max << '\n' << _min << '\n';
}