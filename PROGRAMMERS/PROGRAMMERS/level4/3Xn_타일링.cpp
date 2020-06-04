#include <string>
#include <vector>

using namespace std;

vector<long long> cache;
int mod = 1000000007;

int solution(int n) {
	if (n % 2) return 0;
	vector<long long> cache(n + 1);
	cache[0] = 1;
	cache[1] = 0;
	int sum = 0; // Ư���� ��� ����
	for (int i = 2; i <= n; i += 2) {
		// �⺻ ����� 3��, Ư���� ����� 2���� ���� �� ����
		cache[i] = (3 * cache[i - 2] + 2 * sum) % mod;
		sum = (sum + cache[i - 2]) % mod;
	}
	return cache[n] % mod;
}