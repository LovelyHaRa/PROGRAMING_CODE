#include <string>
#include <vector>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int dp[501][501];

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	// 1. ��� �� dp ���ÿ� ����
	dp[0][1] = triangle[0][0];	
	// 2. ���� ���κ��� ������ ���� ���� ������ �� �� ������ �� ū �� ����
	for (int i = 1; i < triangle.size(); i++) {
		for (int j = 1; j <= i + 1; j++) {
			dp[i][j] += triangle[i][j - 1] + max(dp[i - 1][j - 1], dp[i - 1][j]);
			// 3. ������ ���� �� �ִ� ����
			if (i == triangle.size() - 1) {
				answer = answer < dp[i][j] ? dp[i][j] : answer;
			}
		}
	}
	return answer;
}