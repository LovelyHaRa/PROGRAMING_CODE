#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<vector<double>> cache;

// ��¥, ������ ��
double climb(int days, int climbed)
{
	// �������: m�ϱ��� �������� ��
	if (days == m) return climbed >= n ? 1.0 : 0; // ������ ���� n���� ũ�� ����
	// �޸������̼�
	double& ret = cache[days][climbed];
	if (ret != -1) return ret;
	// Ȯ���� �ٷ� ����
	return ret = 0.25*climb(days + 1, climbed + 1) + 0.75*climb(days + 1, climbed + 2);
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n >> m;
		cache.resize(n, vector<double>(n * 2 + 1, -1));
		cout.precision(10); // 10�ڸ����� ���
		cout << climb(0, 0) << endl;		
		cache.clear();
	}
}