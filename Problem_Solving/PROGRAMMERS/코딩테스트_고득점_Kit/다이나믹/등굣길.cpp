#include <string>
#include <vector>

using namespace std;

int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	// 1. �ʱⰪ ����
	dp[1][1] = 1;
	// 2. �����̴� -1�� �ʱ�ȭ
	for (vector<int> i : puddles) {
		dp[i[1]][i[0]] = -1;
	}
	// 3. Ž��
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// 4. �����̸� ������ 0���� ü����
			if (dp[i][j] == -1) {
				dp[i][j] = 0;
			}
			else {
				// 5. ù��° ���̸� ���ʰ��� ������
				if (i == 1) {
					dp[i][j] += dp[i][j - 1];
				} // 6. �ι��� �ٺ��ʹ� ����, ��ܰ��� ���ؼ� ������ ���� ���� �������� ������
				else {
					dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
				}
			}
		}
	}
	// 7. �׷��� ������Ų ���� ��ȯ
	answer = dp[n][m];
	return answer;
}