#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
// BFS Ž�� Ȱ��
void bfs(int n, vector<vector <int>>& g, queue<int>& q, vector<int>& visit, int count) {
	// 3. ��������: ť�� ������� �� ����
	if (q.empty()) {
		return;
	}
	// 4. ť���� ���� ����
	int t = q.front();
	q.pop();
	// 5. ��� ����ŭ Ž��
	for (int i = 1; i <= n; i++) {
		// 6. ��� ���̰� ����Ǿ��ְ� �湮������ ������
		if (g[t][i] && visit[i] < 0) {
			// 7. ���� �Ÿ��� +1�� �湮 ���� �迭�� ���� 
			visit[i] = visit[t] + 1;
			// 8. ť�� ����
			q.push(i);
		}
	}
	// 9. ť�� �� ������ ��� Ž��
	bfs(n, g, q, visit, count + 1);
}

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	// 1. �׷��� ���̺� ����
	vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < edge.size(); i++) {
		// ������ ǥ���ϱ� ���� 1�� �����Ѵ�
		g[edge[i][0]][edge[i][1]] = g[edge[i][1]][edge[i][0]] = 1;
	}
	// BFS ť
	queue<int> q;
	// ��� 1���� �Ÿ��� �����԰� ���ÿ� �湮���� Ȯ��
	vector<int> visit(n + 1, -1);
	// ���� �䱸����: 1���� ����
	q.push(1);
	visit[1] = 0;
	// 2. BFS Ž��
	bfs(n, g, q, visit, 0);
	// 10. ����
	sort(visit.begin(), visit.end());
	// 11. �ִ��� ���� ������ ��(�������� ����)
	int max = visit[n];
	// 12. �ִ񰪰� �޶��� �� ���� ���䰪 1�� ����
	while (max == visit[n--]) {
		answer++;
	}
	return answer;
}