#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
	int answer = 0;
	// 1. ���� ��ȣ�� ���������� ����
	// 2. �ݴ� ��ȣ�� ������ ��
	// 3. ���������� ����
	// 4. ���� ���� ���� ��ȣ�� ��: �踷��⿡ ���� ������ ��ŭ �߰�
	// 5. 4�� �ƴϸ� �踷��⿡ 1 �߰�
	int top = 0;
	for (int i = 0; i < arrangement.size(); i++) {
		if (arrangement[i] == '(')
			top++;
		else if (arrangement[i] == ')') {
			top--;
			if (i > 0 && arrangement[i - 1] == '(') {
				answer += top;
			}
			else {
				answer += 1;
			}
		}
	}
	return answer;
}