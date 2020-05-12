#include <string>
#include <vector>

using namespace std;

vector<int> cache(60001, -1);

int tiling(int n) {
	// ���� ���: 1, 2�� ����� ���� 1����
	if (n <= 1) return 1;
	// �޸������̼�
	int& ret = cache[n];
	if (ret != -1) return ret;
	// ����Ÿ�� 1���� ���� ���� ����Ÿ�� 2���� ���� ��츦 ����
	return ret = (tiling(n - 1) + tiling(n - 2)) % 1000000007;
}

int solution(int n) {
	return tiling(n);
}