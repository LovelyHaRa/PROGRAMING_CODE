// �׸��� �˰���
#include<iostream>
#include<algorithm>
using namespace std;

int main(void)
{
	int a[1000], b[1000]; // ������, �߰��� ����
	int n, min = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	/*
	1. �������� ����
	2. ���� �迭����� �������� ����(b)
	3. b�� ��Ҹ� ��� ����(min)
	*/
	sort(a, a + n);
	min = b[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		b[i] = b[i-1] + a[i]; // ������ ���
		min += b[i]; // ����� ���
	}
	cout << min << '\n';
}