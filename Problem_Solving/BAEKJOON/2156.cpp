#include<iostream>

using namespace std;

int wine[10000];
int d[10000];

int max(int a, int b) { return a > b ? a : b; }

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> wine[i];
	/* ��ܿ������ ���
	   ���� ������ġ����
	   �ƿ� �ȸ��ô� ���
	   ���� ���ΰ� ������ ������ ���ô� ���
	   ���� ���ΰ� �ι�° �� ������ ���ô� ��� ��
	   �ִ��� �����Ѵ�.
	*/
	d[0] = wine[0];
	d[1] = d[0] + wine[1];
	d[2] = max(max(d[1], wine[2] + wine[1]), wine[2] + d[0]);
	for (int i = 3; i < n; i++)
		d[i] = max(max(d[i - 1], wine[i] + d[i - 2]), wine[i] + wine[i - 1] + d[i - 3]);
	cout << d[n - 1] << endl;
}