#include <string>
#include <vector>

using namespace std;

// �ش� �α� ������ ������ �ð�(ms), ó���ð�(ms)�� ��ȯ�Ͽ� ��ȯ
pair<int, int> getTime(string line) {
	// �α� �ð�(������ �ð�) string ����
	string hh = line.substr(11, 2);
	string mm = line.substr(14, 2);
	string ss = line.substr(17, 6);
	ss.erase(ss.begin() + 2);
	// �α� �ð� ��ȯ
	int h = stoi(hh) * 60 * 60 * 1000;
	int m = stoi(mm) * 60 * 1000;
	int s = stoi(ss);
	// ������ �ð� ����
	string p = line.substr(24);
	p.pop_back();
	// ������ �ð� ��ȯ
	int ptime = stod(p) * 1000;
	// ����
	return make_pair(h + m + s, ptime);
}

int solution(vector<string> lines) {
	int answer = 0;
	vector<int> start, end; // ���� �ð�, ������ �ð� �迭
	// �α� Ž��
	for (int i = 0; i < lines.size(); i++) {
		// �ð� ��ȯ
		pair<int, int> t = getTime(lines[i]);
		// ���� �ð� ���ϱ�
		int startTime = t.first - t.second + 1;
		// ���� �ð��� ������� 0���� �����
		if (startTime < 0) startTime = 0;
		// �迭�� ����
		start.push_back(startTime);
		end.push_back(t.first);
	}
	// �� �α� ���� ������ �ð��� �������� 1�� ���� ó���� ���� ���Ѵ�
	for (int i = 0; i < lines.size(); i++) {
		int cnt = 1; // �ش� �ð� ó����
		int effectTime = end[i] + 999; // �ð� ����
		// ������ �ѱ�� ���� ������ �� ����
		if (effectTime > 60 * 60 * 24 * 1000) effectTime = 60 * 60 * 24 * 1000;
		// ���� �α� ���� ���� �α� ������ Ž��
		for (int j = i + 1; j < lines.size(); j++) {
			// ���� �ð��� �ð� ���� ���� ������ ó���� ����
			if (start[j] <= effectTime) {
				cnt++;
			}
		}
		// ó���� �ִ밪 ����
		answer = answer < cnt ? cnt : answer;
	}
	return answer;
}