#include <string>
#include <vector>
#include<queue>
#include<iostream>

using namespace std;

long long solution(int n, vector<int> works) {
	long long answer = 0;
	// �켱 ���� ť�� ����Ͽ� �ذ�
	priority_queue<int> pq;
	for (int i = 0; i < works.size(); i++) {
		pq.push(works[i]); // ť�� ���� ����
	}
	int t = n;
	while (t--) {
		int x = pq.top();
		if (x == 0) return 0; // �ִ밪�� 0�̶�� �ǹ��̹Ƿ� �ٷ� 0 ����
		pq.pop();
		pq.push(--x); // -1�� ���� �ٽ� ť�� ����
	}
	// ť�� ���� ������ �����Ͽ� ���� �� ����
	while (!pq.empty()) {
		int x = pq.top();
		answer += x * x;
		pq.pop();
	}
	return answer;
}