#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<int> cache;

int min(int a, int b) { return a < b ? a : b; }

// k�� �������� ������ ǥ���� �� �ִ� �������� ������ ���Ѵ�
int countSum(int k)
{
	// ���� ���: k==1
	if (k == 1) return 1;
	// �޸������̼�
	int& ret = cache[k];
	if (ret != -1) return ret;
	ret = 100001; // �ּڰ� ������ ���� �ʱⰪ ����
	double t = sqrt((double)k); // ������ �� ���ϱ�
	if (t == ceil(t)) return ret = 1; // k�� ���������� �Ǻ�
	else
	{
		// k ���� ������ ��� ������ Ž��( 12�� ��� (4+4+4) < (9+1+1+1) )
		// ��ȭ�� countSum(k)=count(i^2)+count(k-i^2) (i: 1~t)
		for (int i = (int)t; i > 0; i--)
			ret = min(ret, countSum(pow(i, 2)) + countSum(k - pow(i, 2))); // �ּڰ� ����
	}
	return ret;
}

int main(void)
{
	int n;
	cin >> n;
	cache.resize(n + 1, -1);
	cout << countSum(n);
}