#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	// �ּ� ��, �ִ� ��, ť ����
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;
	queue<int> q;
	int i = 0;
	// 1. ���� Ƚ�� ��ŭ Ž��
	while (i != operations.size()) {
		string oper = operations[i];
		// 2. ���� ������ ��
		if (oper[0] == 'I') {
			// 3. ���� ����(3�������� ����)
			string num = operations[i].substr(2);
			int n = stoi(num);
			// 4. ���� ����
			max_heap.push(n);
			min_heap.push(n);
		}
		// 5. ���� ������ ��
		else {
			char n = oper[2];
			// 6. �ּڰ� ���� ������ ��
			if (n == '-') {
				// 7. ���� ������� ������
				if (!min_heap.empty()) {
					// 8. �ּ� ������ ����
					int j = min_heap.top();
					min_heap.pop();
					// 9. �ִ� �������� ���� �� ����
					while (1) {
						// 9-1. �ӽ� ť�� ��� ����ְ� �ٽ� �����ϴ� ������ ����
						int k = max_heap.top();
						max_heap.pop();
						if (j == k) {
							while (!q.empty()) {
								max_heap.push(q.front());
								q.pop();
							}
							break;
						}
						q.push(k);
					}
				}
			}
			// 10. �ִ� ���� ������ ��
			else {
				// 11. 7~9������ �ִ� ���� ���� ����
				if (!max_heap.empty()) {
					int j = max_heap.top();
					max_heap.pop();
					while (1) {
						int k = min_heap.top();
						min_heap.pop();
						if (j == k) {
							while (!q.empty()) {
								min_heap.push(q.front());
								q.pop();
							}
							break;
						}
						q.push(k);
					}
				}
			}
		}
		i++;
	}
	// ��� ����
	if (!max_heap.empty())
		answer.push_back(max_heap.top());
	else
		answer.push_back(0);
	if (!min_heap.empty())
		answer.push_back(min_heap.top());
	else
		answer.push_back(0);
	return answer;
}