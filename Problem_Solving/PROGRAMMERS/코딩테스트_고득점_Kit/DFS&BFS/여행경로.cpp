#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> answer;
bool dfs(string from, vector<vector<string>>& tickets, vector<string>& result, vector<int>& visit, int count) {
	// 3. ��� ����
	result.push_back(from);
	// 4. ��ΰ� �ϼ��Ǹ� ���� ���� �� true ����
	if (count == tickets.size()) {
		answer = result;
		return true;
	}
	// 5. Ƽ�� Ž��
	for (int i = 0; i < tickets.size(); i++) {
		// 6. ������� ���� Ƽ���� �� ���� ���ٸ�
		if (tickets[i][0] == from && !visit[i]) {
			// 7. �ش� Ƽ�� ���
			visit[i] = 1;
			// 7-1. �������� �������, ī��Ʈ�� 1 �������� dfs Ž��
			bool success = dfs(tickets[i][1], tickets, result, visit, count + 1);
			// 7-2. ��ΰ� �ϼ��Ǹ� dfs ����
			if (success)
				return true;
			// 7-3 .Ƽ�� ��� ���� ����
			visit[i] = 0;
		}
	}
	// 8. ��� ����
	result.pop_back();
	return false;
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> result; // ��� ���
	vector<int> visit(tickets.size()); // Ƽ�� ��� ����
	// 1. ���ĺ� �켱����̹Ƿ� ����
	sort(tickets.begin(), tickets.end());
	// 2. dfs Ž��
	dfs("ICN", tickets, result, visit, 0);
	// 9. ���� ����
	return answer;
}