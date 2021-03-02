#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<int> price, pref, cache;

int max(int a, int b) { return a > b ? a : b; }

// ����� ���� ��ȹ�� (�ذ� �Ұ�, �޸� �ʰ�)
//int sushi(int budget)
//{
//	int& ret = cache[budget];
//	if (ret != -1) return ret;
//	ret = 0;
//	for (int dish = 0; dish < n; dish++)
//	{
//		if (budget < price[dish]) continue;
//		ret = max(ret, sushi(budget - price[dish]) + pref[dish]);
//	}
//	return ret;
//}

int sushi()
{
	int ret = 0;
	cache[0] = 0;
	for (int budget = 1; budget <= m; budget++)
	{
		int cand = 0;
		for (int dish = 0; dish < n; dish++)
		{
			if (budget >= price[dish])
				cand = max(cand, cache[(budget - price[dish]) % 201] + pref[dish]);
		}
		cache[budget % 201] = cand;
		ret = max(ret, cand);
	}
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n >> m;
		price.resize(n);
		pref.resize(n);
		// �ʹ��� ������ 100�� ������� �̿�
		// ������ ������ �ǹ̰� ������ ��� ����� ������ 100���� ����
		// 10��->1000��
		cache.resize(201); // ĳ�� ����� 20001 -> 201
		for (int i = 0; i < n; i++)
		{
			cin >> price[i] >> pref[i];
			price[i] /= 100;
		}
		m /= 100;
		cout<<sushi()<<'\n';
		price.clear();
		pref.clear();
		cache.clear();
	}
}