#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// �� �Լ�
bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
	// 2. ���� ��ȣ ��������
	if (p1.second - p1.first == p2.second - p2.first)
		return p1.first < p2.first;
	// 1. ���� ���� ��������
	return p1.second - p1.first < p2.second - p2.first;
}

vector<int> solution(vector<string> gems) {
	vector<int> answer;
	set<string> gemset; // ���� ���� ����
	// 1. ���� ���� ����
	for (string gem : gems) {
		gemset.insert(gem);
	}
	unordered_map<string, int> display; // �������� ��ȣ, ���������� map���� ����
	vector<pair<int, int>> range; // ������ �� �ִ� ������ ����(����, ��)
	int n = gems.size();
	// 2. ������ Ž��
	for (int i = 0; i < n; i++) {
		display[gems[i]] = i; // ������ map�� ����
		// ���� ������ ��ȣ
		int start_dp = n - 1; 
		// map�� ���� ������ ��� ����Ǿ��ٸ� ���� ����
		if (display.size() == gemset.size()) {
			// ���� ������ ��ȣ ���ϱ�
			for (auto it = display.begin(); it != display.end(); it++) {
				start_dp = start_dp > it->second ? it->second : start_dp;
			}
			// ���� ����
			range.push_back(make_pair(start_dp, i));
		}
	}
	// 3. ���� ����
	sort(range.begin(), range.end(), compare);
	// 4. ����
	answer.push_back(range[0].first + 1);
	answer.push_back(range[0].second + 1);
	return answer;
}