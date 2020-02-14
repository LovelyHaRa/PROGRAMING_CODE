#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	// 1. �������� �켱���� ť�� ������ ����ֱ�
	for (int i = 0; i < scoville.size(); i++) {
		pq.push(scoville[i]);
	}
	// 2. �켱���� ť�� �ΰ� �̻� �����Ͱ� �����ϰ� ����Ǵ� ���� K �̸��� ������ �ݺ�
	while (pq.top() < K && pq.size() > 1) {
		// 3. ù��°�� �ι�° �����͸� ť���� ����
		int first, second;
		first = pq.top();
		pq.pop();
		second = pq.top();
		pq.pop();
		// 4. ���ο� ���ں� ���� ��� �� push
		pq.push(first + second * 2);
		answer++;
	}
	// 5. ��� ��쿡�� ���ں� ������ K�� ���� ���ϴ� ��� -1 ���
	if (pq.top() < K)
		return -1;
	return answer;
}