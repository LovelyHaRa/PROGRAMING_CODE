#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	vector<char> s(number.size());
	int i = 0, top = 0, t = 0;
	// 1. ù��° ���� ���ÿ� �ֱ�
	s[top] = number[i++];
	// 2. ���� ������ Ž���ϴµ� ���Ű� �Ϸ�Ǹ� Ż��
	while (i != number.size() && t != k) {
		// 3. ������ �� ������ ���� ���ں��� ���� �� ����
		while (top >= 0 && s[top] < number[i]) {
			top--;
			t++;
			// 3-1. ������ ������ �ʰ��ϸ� Ż��
			if (t == k)
				break;
		}
		// 4. ������ �� �������� ���ÿ� ���� ���ڸ� ���� �ʴ´�.
		if (top == number.size() - k - 1)
			i++;
		// 5. �׷��� ������ ���ÿ� ���� ���ڸ� ����
		else
			s[++top] = number[i++];
	}
	// 6. ���Ű� �Ϸ� �Ǿ� �̸� Ż�� ���� ��, ������ ���ڸ� ����ִ´�.
	if (i < number.size()) {
		for (int j = i; j < number.size(); j++) {
			s[++top] = number[j];
		}
	}
	// 7. ���ڿ��� �����.
	for (int j = 0; j <= top; j++) {
		answer += s[j];
	}
	return answer;
}