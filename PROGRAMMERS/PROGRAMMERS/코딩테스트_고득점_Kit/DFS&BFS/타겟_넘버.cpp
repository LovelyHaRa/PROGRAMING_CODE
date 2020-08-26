#include <string>
#include <vector>

using namespace std;

int answer = 0;
// DFS�� �̿��Ͽ� ���� Ž��
void DFS(vector<int> n, int sum, int i, int target) {
	// ���� ����: ���ڸ� ��� Ž�� ���� ��
	if (i == n.size()) {
		// Ÿ�� �ѹ��� �� ���� ��ġ�ϸ� ����� �� �߰�
		if (sum == target)
			answer++;
		return;
	}

	// �ش� ���ڸ� ���ϰ� �� ���� ���Ž��
	DFS(n, sum + n[i], i + 1, target);
	DFS(n, sum - n[i], i + 1, target);
}

int solution(vector<int> numbers, int target) {
	DFS(numbers, 0, 0, target);

	return answer;
}