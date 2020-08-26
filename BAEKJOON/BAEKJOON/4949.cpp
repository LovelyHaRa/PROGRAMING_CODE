// ���� ����
#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(void)
{
	string str;

	while (1)
	{
		stack<char> s;
		getline(cin, str);
		// ���� ����
		if (str[0] == '.' && str.length()==1)
			break;
		int i = 0;
		int flag = 1;
		// 1. �ݴ� ��ȣ�϶�
		// 2. ������ �̿��Ͽ� ��ȣ¦�� �´��� �˻�
		// 3. ������ pop
		// 4. 2�� ������ �ƴϸ� no
		// 5. ���� ��ȣ�� push
		// 6. ���ڿ� ��ȸ�� ������ yes
		for (int i = 0; i < str.length(); i++)
		{
			// 1
			if (str[i] == ')')
			{
				// 2
				if (!s.empty() && s.top() == '(')
					s.pop(); // 3
				else
				{
					// 4
					flag = 0;
					break;
				}
			}
			// 1
			else if (str[i] == ']')
			{
				// 2
				if (!s.empty() && s.top() == '[')
					s.pop(); // 3
				else
				{
					// 4
					flag = 0;
					break;
				}
			}
			// 5
			else if (str[i] == '(' || str[i] == '[')
				s.push(str[i]);
		}
		// 6
		if (flag && s.empty())
			cout << "yes" << '\n';
		else
			cout << "no" << '\n'; // 4
	}
}