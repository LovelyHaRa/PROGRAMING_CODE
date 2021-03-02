#include<iostream>

using namespace std;

long long L = 2000000000;

// �·� ���ϱ�
int ratio(long long games, long long wins)
{
	return (wins * 100) / games;
}

int needGames(long long games, long long wins)
{
	// �Ұ����� ��츦 �̸� �ľ��Ѵ�
	if (ratio(games, wins) == ratio(games + L, wins + L)) return -1;
	// �̺�Ž��
	long long lo = 0, hi = L;
	for (int i = 0; i < 100; i++)
	{
		long long mid = (lo + hi) / 2;
		if (ratio(games, wins) != ratio(games + mid, wins + mid))
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		long long n, m;
		cin >> n >> m;
		cout << needGames(n, m) << '\n';;
	}
}