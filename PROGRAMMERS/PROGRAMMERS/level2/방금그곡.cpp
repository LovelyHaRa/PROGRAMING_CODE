#include <string>
#include <vector>

using namespace std;

// ī��Ʈ ���ϱ�
int getCount(string start, string end) {
	// �ð� ���
	int hour = stoi(end.substr(0, 2)) - stoi(start.substr(0, 2));
	// �� ���
	int s_min = stoi(start.substr(3, 2)), e_min = stoi(end.substr(3, 2));
	int min, lower = 0;
	if (s_min > e_min) {
		min = 60 - s_min + e_min;
		lower = 1; // �ڸ� ����
	}
	else {
		min = e_min - s_min;
	}
	// ������ ȯ�� �� ����
	return (hour - lower) * 60 + min;
}
string solution(string m, vector<string> musicinfos) {
	string answer = "(None)";
	vector<pair<string, int>> info; // ����, ī��Ʈ ��� �迭
	for (int i = 0; i < musicinfos.size(); i++) {
		// 1. �ð� ����
		string start = musicinfos[i].substr(0, 5);
		string end = musicinfos[i].substr(6, 5);
		int j = 12; // ���� ������
		string name, melody; // ����, ��ε�
		string t; // �ӽ� ���ڿ�
		// 2. ���� ����
		while (1) {
			if (musicinfos[i][j] == ',') {
				name = t;
				break;
			}
			else {
				t += musicinfos[i][j++];
			}
		}
		// 3. ��ε� ����
		melody = musicinfos[i].substr(j + 1);
		// 4. ī���� ���ϱ�(�ð���)
		int count = getCount(start, end);
		int c = count; // ī��Ʈ ����(������ �� ���)
		t = ""; // ����� ��ε�
		// 5. ����� ��ε� ���ڿ� ���ϱ�
		j = 0;
		while (count > 0) {
			if (j == melody.size()) j = 0; // j�� �迭 ������ ����� �ʱ�ȭ
			// ���� �������� # �̸� �ҹ��ڷ� �ٲ㼭 ����
			if (j + 1 < melody.size() && melody[j + 1] == '#') {
				t += melody[j] + 32; // �ҹ��ڷ� �ٲٱ�
				j += 2; // # �پ�ѱ�
			}
			// �׷��� ������ ��ȯ ���� ����
			else {
				t += melody[j++];
			}
			count--;
		}
		// 6. ����� ��ε� #�� �ҹ��ڷ� �ٲ㼭 ����
		string mm;
		j = 0;
		while (j < m.size()) {
			// ���� �������� # �̸� �ҹ��ڷ� �ٲ㼭 ����
			if (j + 1 < m.size() && m[j + 1] == '#') {
				mm += m[j] + 32; // �ҹ��ڷ� �ٲٱ�
				j += 2; // # �پ�ѱ�
			}
			// �׷��� ������ ��ȯ ���� ����
			else {
				mm += m[j++];
			}
		}
		// 7. ���ڿ� ã��
		auto n = t.find(mm);
		// 8 �߰��ϸ� info �迭�� ��� ����
		if (n == string::npos) continue;
		info.push_back({ name, c });
	}
	int max = -1;
	// 9. ī��Ʈ�� �ִ밪�� info �� ����
	for (int i = 0; i < info.size(); i++) {
		if (max < info[i].second) {
			max = info[i].second;
			answer = info[i].first;
		}
	}
	return answer;
}