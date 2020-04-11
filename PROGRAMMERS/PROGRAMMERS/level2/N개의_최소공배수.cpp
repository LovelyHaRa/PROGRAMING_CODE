#include <string>
#include <vector>

using namespace std;

// �ִ�����
int gcd(int a, int b) {
	if (a > b) return gcd(a%b, b);
	if (!a) return b;
	return gcd(b%a, a);
}

int solution(vector<int> arr) {
	// ù������ �ι�° ������ �ּҰ������ ���ϰ�
	// �� �ּҰ������ ���� ������ �ּҰ������ ���ϴ� �۾���
	// ������ ���ұ��� ���ϸ� N���� �ּҰ������ ���� �� �ִ�.
	int lcm = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		lcm = lcm * arr[i] / gcd(lcm, arr[i]);
	}
	return lcm;
}