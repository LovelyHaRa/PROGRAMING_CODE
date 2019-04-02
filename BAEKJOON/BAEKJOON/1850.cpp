#include<iostream>

using namespace std;

int GCD(long long a, long long b)
{
	if (a < b) return GCD(a, b%a);
	if (b == 0) return a;
	GCD(b, a%b);
}

int main(void)
{
	long long a, b;
	cin >> a >> b;
	/*
	  �� ���� �ִ� ����� ��ŭ 1�� �ݺ� ���
	  �� ���� �ִ� ����� ��ŭ 1�� �ݺ� ���
	*/
	for (int i = 0; i < GCD(a,b); i++)
		cout << "1";
	cout << endl;
}