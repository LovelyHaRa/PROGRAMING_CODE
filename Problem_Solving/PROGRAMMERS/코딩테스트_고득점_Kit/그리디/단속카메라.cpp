#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 1; // ���� �Ѵ� �̻��̹Ƿ� 1���� ����
	// 1. ���� ������ �������� �������� ����
	sort(routes.begin(), routes.end());
	// 2. ù ������ ���� ������ �������� �ʱ�ȭ
	int cur = routes[0][1];
	// 3. Ž��
	for (int i = 0; i < routes.size() - 1; i++) {
		// 4. ���� ������ ���� ������ �������� ���� ������
		// ���� ������ �����Ѵ�
		if (cur > routes[i][1]) {
			cur = routes[i][1];
		}
		// 5. ���� ������ ������������ ���������� ������
		// ��ġ�� �����Ƿ� ī�޶� ��� ���� �� �������� ����(���������� ��������)
		if (cur < routes[i + 1][0]) {
			cur = routes[i + 1][1];
			answer++;
		}
	}
	return answer;
}