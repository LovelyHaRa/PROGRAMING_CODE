#include<iostream>
#include<algorithm>
using namespace std;

int main(void)
{
	int n;
	int k[1000], c=0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> k[i];
	/*
	���Ը� �������� ����
	c:0~c���� ���� ����
	c+1<k[i]�� �����ϸ�
	c+1 ���� k[i] ������ ���Դ� ������ �� ����
	*/
	sort(k, k + n);
	for (int i = 0; i < n; i++)
	{
		if (c + 1 < k[i])
			break;
		c += k[i];
	}
	cout << c + 1 << endl;
}