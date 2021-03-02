#include <string>
#include <vector>

using namespace std;

long long dp[90];

long long solution(int N) {
	long long answer = 0;
	// �Ǻ���ġ ���� ����
	dp[1] = 1;
	dp[2] = 1;
	// ��ȭ�� N>=3, dp(N) = dp(N-2)+dp(N-1) , dp(1)=dp(2)=1;
	for (int i = 3; i <= N + 1; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	// �簢�� ����: ���� dp(N), ���� dp(N+1)
	answer = dp[N + 1] * 2 + dp[N] * 2;

	return answer;
}