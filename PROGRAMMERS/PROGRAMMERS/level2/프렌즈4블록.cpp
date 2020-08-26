#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	while (1) {
		// 1. 2x2 ��� ã��
		vector<pair<int, int>> removeidx; // 2x2�� ������ ��ǥ�� ����
		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				// ���� ����� �ǳʶٱ�
				if (board[i][j] == ' ') continue;
				// 2x2 ����̸� ������ �߰�
				if (board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 1][j + 1] && board[i][j])
					removeidx.push_back(make_pair(i, j));
			}
		}
		// 2. ��������: 2x2 ����� ������ ����
		if (removeidx.empty()) break;
		// 3. 2x2 ��� ����
		for (int i = 0; i < removeidx.size(); i++) {
			// ��ǥ ����
			int x = removeidx[i].first;
			int y = removeidx[i].second;
			for (int j = x; j <= x + 1; j++) {
				for (int k = y; k <= y + 1; k++) {
					// �ش� ��ǥ�� �̹� ���ŵǾ��ٸ� �ǳʶٱ�(�ߺ�ó��)
					if (board[j][k] == ' ')
						continue;
					// ���� �� ī����
					board[j][k] = ' ';
					answer++;
				}
			}
		}
		// 3. ��� �Ʒ��� ����߸���
		for (int i = 0; i < n; i++) {
			int flag; // ���̻� ������ ����� ������ üũ�ϱ� ���� ����
			do {
				flag = 0;
				for (int j = 0; j < m - 1; j++) {
					// ���� ��ġ�� ����� �ְ�, ���� ��ġ���� ���� �� ��ġ �ű�
					if (board[j][i] != ' ' && board[j + 1][i] == ' ') {
						board[j + 1][i] = board[j][i];
						board[j][i] = ' ';
						flag = 1; // board�� ���ŵǾ����Ƿ� üũ
					}
				}
			} while (flag); // board�� ���ŵ��� ���� �� ���� �ݺ�
		}
	}
	return answer;
}