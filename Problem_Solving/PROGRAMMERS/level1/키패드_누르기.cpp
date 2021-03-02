#include <string>
#include <vector>

using namespace std;

int abs(int a) { return a < 0 ? -a : a; }

string solution(vector<int> numbers, string hand) {
	string answer = "";
	// Ű�е带 0���� �����ϴ� ���� �ٲ Ǯ�� ����
	int posL = 9, posR = 11; // �ʱ� ��ġ(*, #)
	for (int i = 0; i < numbers.size(); i++) {
		int k = numbers[i] - 1; // Ű�е带 0���� �����ϴ� ���� �ٲٱ�
		if (k == -1) k = 10; // 0�� ��ġ 10�� �ش��Ѵ�
		// ���� ��ư�� ���� ó��(1, 4 ,7)
		if (k % 3 == 0) {
			answer += 'L';
			posL = k;
		}
		// ������ ��ư�� ���� ó��(3, 6, 9)
		else if (k % 3 == 2) {
			answer += 'R';
			posR = k;
		}
		// ��� ��ư�� ���� ó��
		else {
			// ���� ���� ��ġ�� ���̵忡 �ִ��� Ȯ��
			// ���̵忡 �ִٸ� ����� �����ϴ� �Ÿ� 1�� �߰��Ǿ�� �Ѵ�
			int distL = (posL % 3 == 0);
			int distR = (posR % 3 == 2);
			// �Ÿ� ���: Ű�е��� ���� ��ġ�� ���̸� ���밪 ���� ��
			distL += abs(k / 3 - posL / 3);
			distR += abs(k / 3 - posR / 3);
			// ������ ������ư�� ������ �ϴ� ���
			if (distL == distR && hand == "right" || distL > distR) {
				answer += 'R';
				posR = k;
			}
			// ���� ������ư�� ������ �ϴ� ���
			else {
				answer += 'L';
				posL = k;
			}
		}
	}
	return answer;
}