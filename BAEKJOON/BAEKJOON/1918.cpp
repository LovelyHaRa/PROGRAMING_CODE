#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(void)
{
	string s;
	cin >> s;
	stack<char> st;
	string res; // ���� ǥ���
	for (int i = 0; i < s.size(); i++)
	{
		// 1. �ǿ����ڴ� ������ ����ǥ��Ŀ� �߰�
		if (s[i] >= 'A' && s[i] <= 'Z')
			res += s[i];
		// 2. ������ �϶�
		else
		{
			// 3. ���� ��ȣ�� ���ÿ� Ǫ��
			if (s[i] == '(')
				st.push(s[i]);
			// 4. ���� ��ȣ�� �ƴ϶��
			else
			{
				// 5. ������ ������� �ʰ� ���� ��ȣ�� ���� �� ���� �ݺ�
				while (!st.empty() && st.top() != '(')
				{
					// 6. �켱������ ����(*, /) ������ �� ���
					if ((s[i] == '*' || s[i] == '/') && s[i] != ')')
					{
						// 7. �켱������ ���� ������(+, -)�� ������ break
						if (st.top() == '+' || st.top() == '-')
							break;
					}
					// 8. �����ڿ� ���� �������� ����
					res += st.top(); // ���� ǥ��Ŀ� ���� ���� �� �߰�
					st.pop(); // ���� ���� ����
				}
				// 9. �ݴ� ��ȣ�̸�  ���� ��ȣ ����(top ���� �ݵ�� ���� ��ȣ
				if (s[i] == ')') st.pop();
				else st.push(s[i]);
			}
		}	
	}
	// 10. ���ÿ� ���� ������ ����ǥ��Ŀ� �߰�
	while (!st.empty())
	{
		res += st.top();
		st.pop();
	}
	cout << res << '\n';
}