#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
	// ���� ī���ͷ� �ذ� ����
	int top = 0;
	for (int i = 0; i < s.size(); i++) {
		s[i] == '(' ? top++ : top--;
		// ��ȣ�� )�� ���۵Ǹ� ������ false
		if (top < 0) return false;
	}
	// top�� ���������� �ùٸ��� ���� ���ڿ�
	return !top;
}