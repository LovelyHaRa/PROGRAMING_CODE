#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
	int answer = 1; // ������ �ּҰ��� �ݵ�� 1(1�ڸ� ���ڿ�)
	int n = s.size(); // �κ� ���ڿ� ����
	while (n > 0) {
		int i;
		// �κ� ���ڿ� Ž��
		for (i = 0; i <= s.size() - n; i++) {
			int j;
			// �縰��� �˻�(�� ���̵尡 �Ȱ����� �ݺ����� ������ �����)
			for (j = 0; j < n / 2; j++) {
				if (s[i + j] != s[i + n - j - 1]) break;
			}
			// �ݺ����� ������ ����Ǹ� ���� n�� �ִ��̹Ƿ� ����
			if (j == n / 2) {
				return n;
			}
		}
		n--; // ¦���� �����ϹǷ� 1�� ����
	}
	// �ּҰ� ��ȯ
	return answer;
}