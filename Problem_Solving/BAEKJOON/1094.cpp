#include<iostream>

using namespace std;

int main(void)
{
	int x, res = 0;
	cin >> x;
	/*
	  x�� �������� �مf�� �� 1�� ����
	*/
	for (; x; x /= 2)
		res += x % 2;
	cout << res;
}