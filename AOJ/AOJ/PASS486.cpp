#include<iostream>
#include<vector>

using namespace std;

const int M = 1000 * 1000 * 10;
vector<int> factors(M + 1, 0);

// ��� ���� ���ϱ�(�ܼ� �˰���)
void getFactors()
{
	for (int div = 1; div <= M; div++)
		for (int multiple = div; multiple <= M; multiple += div)
			factors[multiple]++;
}

int main(void)
{
	getFactors();
	int c;
	cin >> c;
	while (c--)
	{
		int n, lo, hi;
		cin >> n >> lo >> hi;
		int cnt = 0;
		// �������� ������ �����ϸ� ī����
		for(int i=lo;i<=hi;i++)
			if (n == factors[i])
				cnt++;
		cout << cnt << '\n';
	}
}