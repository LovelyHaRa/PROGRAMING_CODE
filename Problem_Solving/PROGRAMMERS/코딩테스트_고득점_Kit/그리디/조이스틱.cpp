#include <string>
#include <vector>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }
int sum(vector<int> t) {
	int res = 0;
	for (int i : t) {
		res += i;
	}
	return res;
}

int solution(string name) {
	int answer = 0;
	int n = name.size();
	// 1. �� ���� ���� �̵� Ƚ���� ����
	vector<int> count(n);
	for (int i = 0; i < n; i++) {
		// 1-1. ���ĺ��� ������ �ɰ� �̵� Ƚ���� ��� ���� ��, �ּڰ��� ����
		count[i] = min(name[i] - 'A', 'Z' - name[i] + 1);
	}
	// 2. �̵� ��� ����
	int where = 0;
	while (1) {
		// 3. ���� ��ġ�� �ִ� �̵� Ƚ�� ����
		answer += count[where];
		count[where] = 0;
		// 4. �̵�Ƚ���� ��� ����������(��� 0�̸�) ����
		if (!sum(count))
			break;
		// 5. ������ �������� ������ ���� �̵� Ƚ���� ���� �� ���� �̵�
		int left = 0, right = 0;
		int left_move = where, right_move = where;
		// 5-1. �������� �̵�
		while (count[left_move] <= 0) {
			left++;
			left_move = left_move <= 0 ? (n - 1) : left_move - 1;
		}
		// 5-2. ���������� �̵�
		while (count[right_move] <= 0) {
			right++;
			right_move = (right_move + 1) % n;
		}
		// 6. ���� �̵� Ƚ���� ������ �̵�Ƚ���� ��, �ּڰ����� �̵�
		answer += left < right ? left : right;
		where = left < right ? left_move : right_move;
	}
	return answer;
}