#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
	int answer = 0;
	// ���� Ž��(123~987)
	for (int num = 123; num <= 987; num++) {
		string t = to_string(num);
		// ���ھ߱� ��Ģ�� ��߳��� ���� ����
		if (t[0] == t[1] || t[0] == t[2] || t[1] == t[2] || t[0] == '0' || t[1] == '0' || t[2] == '0') {
			continue;
		}
		int i;
		// ��Ʈ����ũ, �� �˻�
		for (i = 0; i < baseball.size(); i++) {
			string s = to_string(baseball[i][0]);
			int strike = 0, ball = 0;
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if (t[j] == s[k]) {
						j == k ? strike++ : ball++;
						continue;
					}
				}
			}
			// �־��� ���� ��ġ���� ������ break
			if (strike != baseball[i][1] || ball != baseball[i][2])
				break;
		}
		// ������ Ž���ϸ� ���� �� �� �ִ� ���̴�.
		if (i == baseball.size())
			answer++;
	}
	return answer;
}