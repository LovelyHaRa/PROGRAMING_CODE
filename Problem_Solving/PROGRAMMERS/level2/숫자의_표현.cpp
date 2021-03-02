#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	vector<int> k(n + 1); // k[i] = 1~i������ ��
	// 1. k[i] ����
	for (int i = 1; i <= n; i++) {
		k[i] = i + k[i - 1];
	}
	// i~j�� �� = (1~j�� ��) - (1-i) ������ �̿��Ͽ� �ذ�
	// 2. k Ž��
	for (int i = 1; i <= n; i++) {
		int j = i;
		// i~j�� ���� n�̸� answer �߰�
		// 3. j�� �÷����鼭 i~j�� ���� ���� 
		while (k[j] - k[i - 1] <= n) {
			if (k[j++] - k[i - 1] == n) {
				answer++;
				break;
			}
		}
	}
	return answer;
}