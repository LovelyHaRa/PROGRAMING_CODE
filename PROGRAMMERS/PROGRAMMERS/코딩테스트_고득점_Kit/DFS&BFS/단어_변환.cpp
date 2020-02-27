#include <string>
#include <vector>
#include <queue>

using namespace std;
// ť�� ������� ����
class Word {
	public:
	string s;
	int count;
};
// �湮 ����
int visit[50];
// BFS �̿�
int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	// 1. ���۰� ����
	queue<Word> q;
	Word w;
	w.s = begin;
	w.count = 0;
	q.push(w);
	// 2. ť�� �����϶����� �ݺ�
	while (!q.empty()) {
		// 3. ť�ּ� �ϳ� ������
		w = q.front();
		q.pop();
		// 4. target�� ������ ī��Ʈ ����
		if (w.s == target) {
			return w.count;
		}
		// 5. �ܾ� ����ŭ �ݺ�
		for (int i = 0; i < words.size(); i++) {
			// 6. �ش�ܾ �湮�Ǿ��ٸ� �ǳʶٱ�
			if (visit[i] == 1) {
				continue;
			}
			// 7. ö�� 1�� ���� ��ġ���� �˻�
			int count = 0;
			for (int j = 0; j < words[i].size(); j++) {
				if (w.s[j] != words[i][j]) {
					count++;
				}
				if (count > 1)
					break;
			}
			// 8. 2�� �̻� ��ġ �ϸ� �ǳʶٱ� (��ȯ�� �� �����Ƿ�)
			if (count > 1) {
				continue;
			}
			// 9. ��ȯ �����ϸ� ť�� �����ϰ� �湮���� ����
			else {
				Word tmp;
				tmp.s = words[i];
				tmp.count = w.count + 1; // ī��Ʈ ����
				q.push(tmp);
				visit[i] = 1;
			}
		}
	}
	// ���� �� ���ٸ� 0 ����
	return answer;
}