#include <string>
#include <vector>
#include<iostream>

using namespace std;

// �������� ��Ű�� ��� �ϸ� �ȴ�.
vector<int> solution(string msg) {
	vector<int> answer;
	vector<string> dic;
	char a = 'A';
	// 1. ���� �ʱ�ȭ
	for (int i = 0; i < 26; i++) {
		string x;
		x += a + i;
		dic.push_back(x);
	}
	// 2. Ž��
	int k = 0;
	while (k < msg.size()) {
		int range = 1; // �ܾ� ����
		int idx = -1; // ���� ��ȣ
		// 3. �ܾ ������ ���� �� ���� �ݺ�
		while (k + range - 1 < msg.size()) {
			string t = msg.substr(k, range); // �ܾ� ����(1,2,3...����)
			int find = -1; // ��ã���� -1
			// 4. �ܾ� �˻�
			for (int i = 0; i < dic.size(); i++) {
				if (t.compare(dic[i]) == 0) {
					find = i + 1; // ã���� �ε��� + 1 ����
					break;
				}
			}
			// 5. ã���� ���� ��ȣ ����
			if (find >= 0) {
				range++; // ���� �� ����
				idx = find;
				continue;
			}
			// 6. ��ã���� �ߴ�
			else {
				break;
			}
		}
		// 7. ã�� �ܾ� ���ι�ȣ�� ����
		answer.push_back(idx);
		// 8. ã�� �ܾ� ������ ����
		dic.push_back(msg.substr(k, range));
		// 9. �ܾ� ���̸�ŭ Ž�� �ε��� ����
		k += range - 1;
	}
	return answer;
}

int main(void) {
	solution("KAKAO");
}