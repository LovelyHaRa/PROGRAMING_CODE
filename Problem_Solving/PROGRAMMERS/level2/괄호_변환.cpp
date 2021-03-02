#include <string>
#include <vector>

using namespace std;

/*
	1. �Է��� �� ���ڿ��� ���, �� ���ڿ��� ��ȯ�մϴ�.
	2. ���ڿ� w�� �� "�������� ��ȣ ���ڿ�" u, v�� �и��մϴ�.��, u�� "�������� ��ȣ ���ڿ�"�� �� �̻� �и��� �� ����� �ϸ�, v�� �� ���ڿ��� �� �� �ֽ��ϴ�.
	3. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�" �̶�� ���ڿ� v�� ���� 1�ܰ���� �ٽ� �����մϴ�.
	  3 - 1. ������ ��� ���ڿ��� u�� �̾� ���� �� ��ȯ�մϴ�.
	4. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�"�� �ƴ϶�� �Ʒ� ������ �����մϴ�.
	  4 - 1. �� ���ڿ��� ù ��° ���ڷ� '('�� ���Դϴ�.
	  4 - 2. ���ڿ� v�� ���� 1�ܰ���� ��������� ������ ��� ���ڿ��� �̾� ���Դϴ�.
	  4 - 3. ')'�� �ٽ� ���Դϴ�.
	  4 - 4. u�� ù ��°�� ������ ���ڸ� �����ϰ�, ������ ���ڿ��� ��ȣ ������ ����� �ڿ� ���Դϴ�.
	  4 - 5. ������ ���ڿ��� ��ȯ�մϴ�.
*/

// �ùٸ� ��ȣ������ üũ
bool check(string s) {
	int top = 0;
	for (int i = 0; i < s.size(); i++) {
		s[i] == '(' ? top++ : top--;
		// ������ ������ �ùٸ��� ���� ��ȣ��
		if (top < 0)
			return false;
	}
	return true;
}

// ���ڿ��� u, v�� �ж��ϴ� �Լ�(2)
vector<string> tokenize(string s) {
	int top = 0;
	int i = 0;
	vector<string> res(2); // u, v
	// u: �������� ��ȣ��: ó���� �����ϰ�
	//                  ���ʷ� ���� �����Ͱ� 0�̵Ǵ� ����
	do {
		s[i] == '(' ? top++ : top--;
		res[0] += s[i++];
	} while (top != 0);
	// v: u�� ������ ������
	res[1] = s.substr(i);
	return res;
}

string process(string u, string v) {
	// 1. u�� �ùٸ� ���ڿ��̸�(3)
	if (check(u)) {
		// v�� ���� 1�ܰ���� �ٽ� ����
		// (1)
		if (!v.size())
			return u;
		// (2)
		else {
			vector<string> token = tokenize(v);
			// ���� ����� ���̱�(3-1)
			return u + process(token[0], token[1]);
		}
	}
	// 2. u�� �ùٸ��� ���� ���ڿ��̸�(4)
	else {
		// (4-1)
		string t = "(";
		// (4-2)
		if (v.size()) {
			vector<string> token = tokenize(v);
			t += process(token[0], token[1]);
		}
		// (4-3)
		t += ')';
		// (4-4)
		for (int i = 1; i < u.size() - 1; i++) {
			t += u[i] == '(' ? ')' : '(';
		}
		// (4-5)
		return t;
	}
}

string solution(string p) {
	vector<string> token = tokenize(p);
	return process(token[0], token[1]);
}