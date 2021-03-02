#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
	int answer = 0;
	// 1. �������� ����
	sort(weight.begin(), weight.end());
	// 2. Ž��
	for (int i = 0; i < weight.size(); i++) {
		// 3. �����ձ����� ��� ǥ�� �����ϴ�
		// ���� ������ �������� ���� �ߺ��� ������
		// �� ���� ǥ���� �� ���� �ּڰ��� �ȴ�.
		if (answer + 1 < weight[i]) {
			break;
		}
		// 4. 3�� �ƴ� ��� ������ �� ����
		answer += weight[i];
	}
	return answer + 1;
}