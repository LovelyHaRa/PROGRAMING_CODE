#include<iostream>

using namespace std;

// �ִ����� ���ϱ�
int gcd(int a, int b)
{
	if (a > b) return gcd(a%b, b);
	if (!a) return b;
	return gcd(b%a, a);
}

int main(void)
{
	int n, s;
	cin >> n >> s;
	// �ʱⰪ ����
	int min;
	cin >> min;
	min = min > s ? min - s : s - min; // ������ ���밪 ����
	n--;
	while (n--)
	{
		// �ι�° ���� ��
		int a;
		cin >> a;
		int k = a > s ? a - s : s - a; // ������ ���밪 ����
		int g = gcd(min, k); // �ּҰ��� ���� ���� �ִ����� ���ϱ�
		min = min > g ? g : min; // �ּҰ� ����
	}
	cout << min;
}