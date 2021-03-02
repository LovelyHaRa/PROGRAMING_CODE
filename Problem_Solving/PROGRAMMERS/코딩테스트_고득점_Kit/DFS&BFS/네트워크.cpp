#include <string>
#include <vector>

using namespace std;

int visit[200]; // ���� Ž�� ����

// DFS
void dfs(int start, vector<vector<int>> &computers, int n) {
	visit[start] = 1; // ���� �湮 üũ
	for (int i = 0; i < n; i++) {
		// �ش� �������� ���� ���� Ž���Ǵ� �� ���ȣ��
		if (computers[start][i] && !visit[i]) {
			dfs(i, computers, n);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	// 1. ��Ʈ��ũ ����ŭ Ž��
	for (int i = 0; i < n; i++) {
		// 2. DFS �ϳ��� ��Ʈ��ũ �ϳ��̹Ƿ� ���� ������ answer �߰�
		if (!visit[i]) {
			dfs(i, computers, n);
			answer++;
		}
	}
	return answer;
}