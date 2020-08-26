#include <string>
#include <vector>

using namespace std;

int answer = -1;

void dfs(int N, int number, int count, int prev) {
	int t = N;
	// 1. ��������1 : �ּڰ��� 8�� �ʰ��ϸ� ����
	if (count > 8) {
		answer = -1;
		return;
	}
	// 2. ��������2 : �־��� ���� ������� ���� ���� ���� ��
	if (number == prev) {
		// 2-1. ���ʹ߰��̰ų� �ּڰ��� ��� ����
		if (answer == -1 || answer > count) {
			answer = count;
			return;
		}
	}
	// 3. ����Ž��
	for (int i = 0; i < 8 - count; i++) {
		// 3-1. ��Ģ���� ����
		dfs(N, number, count + i + 1, prev + t);
		dfs(N, number, count + i + 1, prev - t);
		dfs(N, number, count + i + 1, prev*t);
		dfs(N, number, count + i + 1, prev / t);
		// 3-2. t���� N �̾� ���̱�
		t = t * 10 + N;
	}
}

int solution(int N, int number) {
	dfs(N, number, 0, 0);
	return answer;
}