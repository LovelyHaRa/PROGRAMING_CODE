#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> s;
	// 1. ũ���� �̵� Ƚ����ŭ Ž��
	for (int i = 0; i < moves.size(); i++) {
		// 2. ���� ��ġ �ε����� ����(-1)
		int location = moves[i] - 1;
		// 3. ���� ��ġ���� ���η� Ž��
		for (int j = 0; j < board.size(); j++) {
			// 4. ������ ó�� �߰ߵǸ�
			if (board[j][location] > 0) {
				// 5. ���� �ֻ�� ������ �Ȱ����� 2�� ���ֱ�
				if (!s.empty() && s.top() == board[j][location]) {
					answer += 2;
					s.pop();
				}
				// 6. �ƴϸ� ���ÿ� �߰�
				else {
					s.push(board[j][location]);
				}
				// 7. ���ڿ��� ����
				board[j][location] = 0;
				break;
			}
		}
	}
	return answer;
}