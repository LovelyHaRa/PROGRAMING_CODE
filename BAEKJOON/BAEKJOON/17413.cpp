#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void)
{
	string s;
	getline(cin, s); // �Է� ����
	string t; // �±�, �ܾ ����
	int tag = 0; // �ε����� �±� ���̿� ��ġ�ϰ� �ִ��� ����
	for (int i = 0; i < s.size(); i++)
	{
		// 1. ���� ���ڸ� ����ؾ��� ����: ���鹮�� �̰� �±׻��̿� ���ų� �±� �������� ���
		if ((s[i] == ' ' && !tag) || (s[i] == '<'))
		{
			// ���� ���� ���
			reverse(t.begin(), t.end());
			cout << t;
			// t �ʱ�ȭ
			t = "";
			// �±� �������� ��� '<' ����
			if (s[i] == '<')
			{
				t += '<';
				tag = 1; // �±� ����
			}
			// �����̾��� ��� ���� �߰� ���
			else
				cout << ' ';
		}
		// 2. �±׸� ����ؾ��� ����(�ܼ� ���� ���): �±� �������ΰ��
		else if (s[i] == '>')
		{
			// '>' ����
			t += '>';
			// ���ڿ� ���
			cout << t;
			// t �ʱ�ȭ
			t = "";
			tag = 0; // �±� ����
		}
		// 3. 1, 2�� �ƴ� ��쿡�� �ܾ� ����
		else
			t += s[i];
	}
	// ������ ���ڰ� �±װ� �ƴϾ��ٸ� ������ �ܾ� ������ ���
	if (s[s.size() - 1] != '>')
	{
		reverse(t.begin(), t.end());
		cout << t;
	}
}