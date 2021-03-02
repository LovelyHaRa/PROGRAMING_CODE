#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	vector<int> dp;
	dp.push_back(0);
	dp.push_back(1);
	// �޸����̼� �̿�
	for (int i = 2; i <= n; i++) {
		// ��� �������� ���� �������� ���ϴ°Ͱ� ��� ����� �� �������� ���Ѱ��� �Ȱ����� �̿�
		dp.push_back((dp[i - 2] % 1234567 + dp[i - 1] % 1234567) % 1234567);
	}
	int answer = dp[n];
	return answer;
}