// �ùķ��̼� ����
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	queue<int> q;
	int sum = 0;
	
	// 1. ť�� ����� �� : ť�� Ʈ�� �߰�, ���� ����, �ð� �߰�
	// 2. ť�� ��á�� �� : ť���� Ʈ�� ����, ���� ����
	// 3. 1,2�� �ƴѰ��
	// 4. ���԰� �ʰ��� ��� : ť�� 0�� �߰�(���� �������), �ð� �߰�
	// 5. 4�� �ƴ� ��� : 1�� ���� �۾�

	for (int i = 0; i < truck_weights.size(); i++) {
		int k = truck_weights[i];
		while (1) {
			// 1
			if (q.empty()) {
				q.push(k);
				sum += k;
				answer++;
				break;
			}
			// 2
			else if (q.size() == bridge_length) {
				sum -= q.front();
				q.pop();
			}
			// 3
			else {
				// 5
				if (sum + k <= weight) {
					q.push(k);
					sum += k;
					answer++;
					break;
				}
				// 4
				else {
					q.push(0);
					answer++;
				}
			}
		}
	}
	// �� �ð� = ���ݱ��� ���ѽð� + ������ Ʈ���� �ǳʴ� �ð�(�ٸ� ����)
	answer += bridge_length;
	return answer;
}