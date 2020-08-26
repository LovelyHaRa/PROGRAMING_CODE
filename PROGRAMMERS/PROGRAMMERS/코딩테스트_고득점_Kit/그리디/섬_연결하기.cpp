#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> d; // �ش� ����� ������带 ��Ÿ��

bool compare(vector<int> &a, vector<int> &b) {
	return a[2] < b[2]; // ����ġ�� �������� ����
}

int find(int node) {
	if (node == d[node]) return node;
	else return d[node] = find(d[node]);
}
// ũ�罺Į �˰������� �ּ� ���д� Ʈ���� �����Ѵ�.
int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	// 1. ����ġ �������� �������� ����
	sort(costs.begin(), costs.end(), compare);
	d.resize(n);
	// 2. ������� �ʱ�ȭ
	for (int i = 0; i < n; i++) {
		d[i] = i; // ó������ �ڱ� �ڽ��� ������� ��
	}
	// 3. ���� ������ŭ Ž��
	for (int i = 0; i < costs.size(); i++) {
		// 4. �������� ������ ����ġ�� ���Ѵ�.
		int start = find(costs[i][0]);
		int end = find(costs[i][1]);
		int cost = costs[i][2];
		// 5. start�� end�� �ٸ��� ������� ������ �ǹ�
		if (start != end) {
			d[start] = end; // �����ϰ�
			answer += cost; // �� �߰�
		}
	}
	return answer;
}