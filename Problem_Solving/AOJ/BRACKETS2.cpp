#include<iostream>
#include<stack>
#include<string>

using namespace std;

int matched(const string& s)
{
	stack<char> st;
	const string opening("({["), closing(")}]");
	for (int i = 0; i < s.size(); i++)
	{
		// ���� ��ȣ�� ������ ���ÿ� ����
		if (opening.find(s[i]) != -1)
			st.push(s[i]);
		else
		{
			// ������ ��������� ����
			if (st.empty()) return false;
			// ¦�� ���� �ʾƵ� ����
			if (opening.find(st.top()) != closing.find(s[i]))
				return false;
			// ¦�� ������ ���ÿ��� ����
			st.pop();
		}
	}
	// ������ ��������� ����
	return st.empty();
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		string s;
		cin >> s;
		cout << (matched(s) ? "YES\n" : "NO\n");
	}
}