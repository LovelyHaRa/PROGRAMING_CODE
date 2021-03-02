// ����
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ���丮���� 2�� 5�� ����
pair<long long, long long> countZero(long long k)
{
	int two = 0, five = 0;
	// ���� ����ŭ �߰��Ǵ°��� ���
	for (long long i = 2; i <= k; i *= 2)
		two += k / i;
	for (long long i = 5; i <= k; i *= 5)
		five += k / i;
	
	return { two, five };
}

int main(void)
{
	long long n, m;
	cin >> n >> m;
	// 1. n!�� 2�� 5�� ������ ���Ѵ�.
	// 2. n! ��� (n-m)!�� ���ؼ� 1�� ����
	// 3. n! ��� m!�� ���ؼ� 1�� ����
	// 4. 2�� ������ 5�� ������ ���� 1-2-3 �� ���� ���� ����� �ּ��� �� ���
	vector<pair<long long, long long>>res(3);
	
	res[0] = countZero(n); // 1
	res[1] = countZero(n-m); // 2
	res[2] = countZero(m); // 3
	// 4
	cout << min((res[0].first - res[1].first - res[2].first),
		(res[0].second - res[1].second - res[2].second)) << '\n';
}