#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	// set �̿�
	set<string> s;
	s.insert(words[0]);
	for (int i = 1; i < words.size(); i++) {
		// Ż���� ���� : ���� �ܾ� ��ġ / �����ڼ� + 1
		// Ż���� ��ȣ : ���� �ܾ� ��ġ % �����ڼ� + 1
		// 1. �ߺ� �ܾ� ȣ�� �� Ż��
		if (s.count(words[i])) {
			answer.push_back(i%n + 1);
			answer.push_back(i / n + 1);
			return answer;
		}
		// 2. ���� �ܾ��̸� set�� �߰�
		if (words[i - 1][words[i - 1].size() - 1] == words[i][0]) {
			s.insert(words[i]);
		}
		// 3. �����ձ� �� ���ݽ� Ż��
		else {
			answer.push_back(i%n + 1);
			answer.push_back(i / n + 1);
			return answer;
		}
	}

	return { 0,0 };
}