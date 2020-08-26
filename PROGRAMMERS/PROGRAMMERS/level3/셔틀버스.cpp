#include <string>
#include <vector>
#include<algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	vector<int> minutetable; // tametable �ð����� �� ������ ��ȯ�� �� ����
	// 1. timetable �ð����� �д����� ��ȯ
	for (int i = 0; i < timetable.size(); i++) {
		int minute = 0, k = 60, j = 0;
		while (k > 0) {
			minute += stoi(timetable[i].substr(j, j + 2))*k;
			k /= 60;
			j += 3;
		}
		minutetable.push_back(minute);
	}
	// 2. �������� ����
	sort(minutetable.begin(), minutetable.end());
	// 3. ���� ž�� �ùķ��̼�
	// ���� ���� �ð�, timetable �ε���, ž�� �ο� ��, �����ؾߵǴ� �ð�
	int bustime = 540, tableidx = 0, takecnt = m, res;
	// ��Ʋ ���� ��ȸ
	for (int i = 0; i < n; i++, bustime += t) {
		takecnt = m; // ž�� �ο� �� �ʱ�ȭ
		// ������ ����ϴ� ��� �¿��
		while (takecnt-- && tableidx != minutetable.size()) {
			// ���� ������ ��Ÿ�� ����� ��� ���� ������ Ÿ�ߵȴ�
			if (bustime < minutetable[tableidx]) {
				break;
			}
			tableidx++; // �ε��� ����
		}
		// ������ ������ ��
		if (i == n - 1) {
			// �°��� ��� �¿�ٸ�, ���� �������� ź������� 1�� �����;��Ѵ�
			if (takecnt < 0) res = minutetable[tableidx - 1] - 1;
			// �׷��� �ʴٸ� ���� �ð��� ���缭 �����ϸ� �ȴ�
			else res = bustime;
		}
	}
	// �����ؾ� �Ǵ� �ð����� �ð� ���ڿ��� ��ȯ�Ѵ�
	answer += (res / 60) / 10 + '0';
	answer += (res / 60) % 10 + '0';
	answer += ':';
	answer += (res % 60) / 10 + '0';
	answer += (res % 60) % 10 + '0';
	return answer;
}