#include <string>
#include <vector>

using namespace std;
// �÷��̵� �ͼ� �˰���
int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	// 1. �׷��� ����
	vector<vector<bool>> g(n + 1, vector<bool>(n + 1, false));
	for (auto r : results) {
		g[r[0]][r[1]] = true; // ��� �ܹ��� üũ
	}
	// 2.�÷��̵� �ͼ� �˰��� �̿�
	// �߰�����
	for (int i = 1; i <= n; i++) {
		// ��������
		for (int j = 1; j <= n; j++) {
			// ������
			for (int k = 1; k <= n; k++) {
				// ����-�߰� �߰�-�� �� ����Ǿ� ������
				if (g[j][i] && g[i][k]) {
					g[j][k] = true; // ����-���� �����Ѵ�.
				}
			}
		}
	}
	// 3. �׷��� Ž��
	for (int i = 1; i <= n; i++) {
		// 4. �ܹ����̶� ����Ǿ������� ī��Ʈ ����
		// (�̱�� ���� ����Ǿ������� ���� Ȯ�� ����)
		int count = 0;
		for (int j = 1; j <= n; j++) {
			if (g[i][j] || g[j][i]) {
				count++;
			}
		}
		// 5. �ڱ� �ڽ��� �����ϰ� ��� ����Ǿ������� ����Ȯ�� ����
		if (count == n - 1) {
			answer++;
		}
	}
	return answer;
}