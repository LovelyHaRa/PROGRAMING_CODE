#include<iostream>
#include<cmath>

using namespace std;

int main(void)
{
	int n, a, b, res = 1, t;
	cin >> n >> a >> b;
	/*
	  n�� ��ʸ�Ʈ ���� �� : log2(n)�� �ø���
	  a,b �� ��� �Ǻ�
	  �� ��ȣ�� ���̰� 1�̸鼭 ���� ���� Ȧ���̸�
	  ����� ����� ����
	  �׷��� ������ �� ��ȣ�� +1 �ϰ� 2�� ������
	  ���� ������ ��ȣ�� ����
	*/
	t = (int)ceil(log2(n));
	while ((t+1)!=res)
	{
		int max = a > b ? a : b;
		int min = a < b ? a : b;
		if (min % 2 && max - min == 1)
			break;
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		res++;
	}
	if (res > t)
		cout << "-1" << endl;
	else
		cout << res << endl;
}