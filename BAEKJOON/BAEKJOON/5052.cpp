// ���ڿ� �ؽ�
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		vector<string> phone;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			phone.push_back(s);
		}
		// 1. ����
		// 2. �Է� ��ȭ��ȣ ���� -1 ��ŭ Ž��
		// 3. ���� ��ȭ��ȣ ���̰� ���� ��ȭ��ȣ ���� ���� ���� ��
		// 4. find�� �̿��� ���ڿ��� �˻�, ���� �ε����� 0�̸� break
		// 5. ������ Ž���ϸ� YES �ƴϸ� NO

		sort(phone.begin(), phone.end()); // 1

		int res = 1;
		// 2
		for (int i = 0; i < phone.size() - 1; i++)
		{
			// 3
			if (phone[i].length() < phone[i + 1].length())
			{
				// 4
				if (!phone[i + 1].find(phone[i]))
				{
					res = 0;
					break;
				}
			}
		}
		cout << (res ? "YES\n" : "NO\n"); // 5
	}
}