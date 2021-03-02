#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
	// ��Ģ�� ã�ƺ��� �Ǻ���ġ �����̾���.
	long long a = 1, b = 2;
	if (n == 1) return n; // 1�� �� ó��
	// n�� 2�� �� �� ���� ����
	while (n-- >= 3) {
		// �Ǻ���ġ ���� ���
		long long c = (a + b) % 1234567;
		a = b;
		b = c;
	}
	return b % 1234567;
}