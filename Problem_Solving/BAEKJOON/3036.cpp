#include<iostream>

using namespace std;

/* �ִ� ����� */
int GCD(int a, int b)
{
	if (a < b) return GCD(a, b%a);
	if (b == 0) return a;
	GCD(b, a%b);
}

int main(void)
{
	int n, i;
	int r[100];
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> r[i];
	/*
	  1. i : 1 ~ n-1 
	     ù��° ���� i��° ���� �ִ� ������� ���Ѵ�.
	     2. ������ �ִ������� ���� ���� '/'�� �����Ͽ� ����Ѵ�.
	*/
	for (i = 1; i < n; i++)
	{
		int gcd = GCD(r[0], r[i]);
		cout << r[0] / gcd << "/" << r[i] / gcd << endl;
	}
}