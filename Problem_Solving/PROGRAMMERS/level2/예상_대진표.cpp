#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
	int answer = 1;
	while (n > 1) {
		// 1. ��� �Ǻ�
		int min = a < b ? a : b;
		int max = a > b ? a : b;
		// 2. ���� ���� Ȧ�� �̰� �� ���� ���� 1�̸� ���� Ȯ��
		if (min % 2 && max - min == 1) break;
		// 3. ���� ���� ��ȣ ����
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		// 4. ���� ����
		answer++;
		n /= 2;
	}

	return answer;
}