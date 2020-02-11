// ���Ʈ����, ����
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	// ��ü ���� ����
	int width = brown + red;
	// ����� �� : ��ü ���� ������ ���
	for (int i = width / 2; i >= 1; i--) {
		// ��� �߰� ��
		if (!(width%i)) {
			// x: ���� ����, y: ���� ����
			int x = i;
			int y = width / i;
			// ī���� ���ΰ� ���κ��� �� �� ����
			if (x < y) continue;
			// ������ ���� ����: (���α���-2)*(���α���-2)
			int red_cnt = (x - 2)*(y - 2);
			// ���� ���� ����: (��ü ���ڰ���)-(������ ���� ����)
			int brown_cnt = width - red_cnt;
			// �Է°� ��ġ���� �˻�: ��ġ�ϸ� ����, ���α��� ����
			if (red_cnt == red && brown_cnt == brown) {
				answer.push_back(x);
				answer.push_back(y);
				break;
			}
		}
	}
	return answer;
}