#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
	int answer = 0;
	stack<char> t;
	// ���ڿ� ���̰� Ȧ���̸� �ݵ�� 1���� ���´�.
	if (s.size() % 2) return 0;
	// 1. ù���� ���� push
	t.push(s[0]);
	// 2. ���ڿ� Ž��
	for (int i = 1; i < s.size(); i++) {
		// 3. ������ ����ְų� top�� ���� ���ڰ� ��ġ���� ������ push
		if (t.empty() || t.top() != s[i]) {
			t.push(s[i]);
		}
		// 4. �׷��� ������ pop
		else {
			t.pop();
		}
	}
	// 5. ������ ��������� 1 �ƴϸ� 0 ����
	return t.empty();
}