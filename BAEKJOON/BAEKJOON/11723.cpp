#include<iostream>
#include<string>
#include<set>

using namespace std;

int main(void)
{
	// �Է� ���� ���Ƽ� �ð��ʰ� ����
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	set<int> s;
	int m;
	cin >> m;
	while (m--)
	{
		string op;
		cin >> op;
		int x;
		// add, all
		if (op[0] == 'a')
		{
			// add
			if (op[1] == 'd')
			{
				cin >> x;
				s.insert(x);
			}
			// all
			else
			{
				for (int i = 1; i <= 20; i++)
					s.insert(i);
			}
		}
		// remove, check
		else if (op[0] == 'r' || op[0] == 'c')
		{
			cin >> x;
			// ���� ���� ���� Ȯ��
			if (s.find(x) != s.end())
			{
				// remove�� ����, check�̸� 1 ���
				if (op[0] == 'r')
					s.erase(s.find(x));
				else
					cout << "1\n";
			}
			// check �̰� ���Ұ� ������ 0 ���
			else if (op[0] == 'c')
				cout << "0\n";
		}
		// toggle
		else if (op[0] == 't')
		{
			cin >> x;
			// ������ ����
			if (s.find(x) != s.end())
				s.erase(s.find(x));
			else
				s.insert(x);
		}
		// empty
		else if (op[0] == 'e')
			s.clear();
	}
}