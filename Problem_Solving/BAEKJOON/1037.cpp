// ���� ����
#include<iostream>

using namespace std;

int main(void)
{
	int a[50];
	int n, min = 1987654, max = 1;
	cin >> n;
	// �ִ밪 * �ּҰ� = ���
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		max = max < a[i] ? a[i] : max;
		min = min > a[i] ? a[i] : min;
	}
	cout << max * min << '\n';

}