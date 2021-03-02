#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<string> data) {
	int answer = 0;
	// 1. ģ���� �迭�� �����.
	vector<char> photo = { 'A','C','F','J','M','N','R','T' };
	// 2. ���� ����Ž�� (8! �̶� ����)
	do {
		int i;
		// 3 ���� ������ŭ �ݺ�
		for (i = 0; i < n; i++) {
			// 4. ������ ����
			char a = data[i][0], b = data[i][2]; // ģ�� a, b
			char c = data[i][3]; // �� ����
			int interval = data[i][4] - '0'; // a, b ������ ģ�� ��
			// 5. ģ�� ��ġ ã��
			int idx_a = -1, idx_b = -1; // a, b �ε���
			for (int j = 0; j < 8; j++) {
				if (a == photo[j])
					idx_a = j;
				else if (b == photo[j])
					idx_b = j;
			}
			// 6. a-b�� ���밪 ���ϱ�
			int max = idx_a > idx_b ? idx_a : idx_b;
			int min = idx_a < idx_b ? idx_a : idx_b;
			int ab = max - min - 1;
			// 7. �������� ���� ���ϸ� break
			if (c == '=' && ab != interval) break; // ���ƾ��ϴµ� ���� ������ break
			else if (c == '>' && ab <= interval) break; // �ʰ��ؾ��ϴµ� �����̸� break
			else if (c == '<' && ab >= interval) break; // �̸��̾���ϴµ� �̻��̸� break
		}
		// 8. ��� ������ �����ϸ� ���� �� ����
		if (i == n) answer++;
	} while (next_permutation(photo.begin(), photo.end())); // ��� ���� ����
	return answer;
}