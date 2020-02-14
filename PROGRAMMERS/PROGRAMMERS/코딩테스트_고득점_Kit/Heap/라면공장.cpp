#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<int> pq;
	int supply = 0;
	// 1. 0�� ���� k�ϱ��� �ݺ�
	for (int i = 0; i < k; i++) {
		// 2. ���� ���ڿ� ���޹��� �� ������ �켱���� ť�� ����
		if (dates[supply] == i) {
			pq.push(supplies[supply]);
			supply < supplies.size() - 1 ? supply++ : supply;
		}
		// 3. ��� �ٶ������� ���� ���� ������� ����
		// �׷��� ������ �ּҷ� ���� �� �ִ�.
		if (!stock) {
			stock += pq.top();
			pq.pop();
			answer++;
		}
		// 4. �Ϸ��� ���� ���Һ�� ������
		stock--;
	}
	return answer;
}