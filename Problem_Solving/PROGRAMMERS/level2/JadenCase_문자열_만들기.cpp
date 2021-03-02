#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	int flag = 1;
	for (int i = 0; i < s.size(); i++) {
		// 1. ���� �� ù������ ��
		if (flag && s[i] != ' ') {
			// �ҹ����̸� �빮�� ����
			if (s[i] >= 'a' && s[i] <= 'z') {
				s[i] -= 32;
			}
			flag = 0;
		}
		// 2. �����̸� �÷��� ����
		else if (s[i] == ' ') {
			flag = 1;
		}
		// 3. �׿ܿ��� �빮���̸� �ҹ��ڷ� ����
		else {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				s[i] += 32;
			}
		}
		answer += s[i];
	}
	return answer;
}