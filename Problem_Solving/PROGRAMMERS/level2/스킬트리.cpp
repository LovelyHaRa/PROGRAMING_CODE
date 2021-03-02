#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	// 1. ��ųƮ�� ������ŭ �ݺ�
	for (int i = 0; i < skill_trees.size(); i++) {
		int impossible = 0; // ��ųƮ�� �Ұ��� ����
		int j = 0;
		queue<char> q, tq; // ��ų����
		// 2. ��ų���� ������Ʈ
		while (j < skill.size()) {
			q.push(skill[j++]);
		}
		// 3. ��ųƮ�� ��ȸ
		for (j = 0; j < skill_trees[i].size(); j++) {
			int flag = 0; // ù��° ��ų ��ġ����
			// 4. ��ųƮ�� ���¸� �ӽ÷� ����
			tq = q;
			// 5. �ӽ� ��ųƮ�� ��ȸ
			while (!tq.empty()) {
				// 6. ù��° ��ȸ�� ��ġ���� �ʰ� �ι�° ��ȸ���� ��ġ�ϸ� �Ұ���
				if (flag && tq.front() == skill_trees[i][j]) {
					impossible = 1;
					break;
				}
				// 7. ù��° ��ȸ�� ��ġ�ϸ� ��ų���¿��� pop
				else if (tq.front() == skill_trees[i][j]) {
					q.pop();
					break;
				}
				tq.pop();
				flag = 1;
			}
			// 8 �Ұ��ɽ� Ž�� �ߴ�
			if (impossible) {
				break;
			}
		}
		// 9 ���� �Ұ��� ���ο� ���� ���� ����
		answer = impossible ? answer : answer + 1;
	}
	return answer;
}

int main(void) {
	solution("CBD", { "BACDE","CBADF", "AECB", "BDA" });
}