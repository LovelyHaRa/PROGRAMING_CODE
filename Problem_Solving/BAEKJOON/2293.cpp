#include<iostream>

using namespace std;

int main(void)
{
	int c[101], d[10001] = { 0 }; // ���� ����, ����Ǽ� ����
	int n, k; // n���� ����, k�� ����� �ִ� ���
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> c[i]; // ���� ���� �Է�
	d[0] = 1;
	/* ù��° ������ ����� ���~ 
	   ù��° ���� n��° ������ ����� ��츦 �̿��Ͽ� ���
	   ��ȭ��
	   D(i,k)={	D(i,k-C(i))+D(i-1,k) (C(i)<=k)
				D(i-1,k) (C(i)>K }
	*/
	for (int i = 1; i <= n; i++)
	{
		for (int j = c[i]; j <= k; j++)
			d[j] += d[j - c[i]];
	}
	cout << d[k] << endl;	
}