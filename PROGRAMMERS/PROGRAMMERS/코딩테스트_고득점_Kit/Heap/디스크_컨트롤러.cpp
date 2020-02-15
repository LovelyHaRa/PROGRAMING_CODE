#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct compare {
	bool operator()(vector<int> a, vector<int> b) {
		return a.at(1) > b.at(1); // greater
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	// 1. �ð��뺰 �������� ����
	sort(jobs.begin(), jobs.end());
	// 2. ���͸� ������ �� �ִ� �켱���� ť ����
	priority_queue<vector<int>, vector<vector<int>>, compare> pq;
	int i = 0, time=0; // �۾��ܰ�, ���� �ð�
	// 3. ť�� ����ְ� ��� �۾��� �Ϸ��� �� ���� Ž��
	while (i < jobs.size() || !pq.empty()) {
		// 4. ���� �۾��� ����ð����� �۾Ƽ� ť�� ���� �� ���� ��
		if (i < jobs.size() && time>=jobs[i][0]) {
			// 4-1. ť�� ����
			pq.push(jobs[i++]);
			// 4-2. �ٸ� �۾��� ���ð��뿡 ���� �� �����Ƿ� ��Ž��
			continue;
		}
		// 5. ť�� ������� ������
		if (!pq.empty()) {
			// 5-1. �۾� �ð� ����
			time += pq.top()[1];
			// 5-2. �۾��� ������ �Ϸ��� �� ���� �ð�=(����ð�-���½ð�)
			answer += time-pq.top()[0];
			// 5-3. ť���� ����
			pq.pop();
		}
		// 6. ť�� ����ִٸ� ���� �۾� �ð���ŭ ����
		else
			time = jobs[i][0];
	}
	return answer / jobs.size();
}

int main(void) {
	solution({ { 0,3 }, { 1,9 }, { 2,6 } });
}