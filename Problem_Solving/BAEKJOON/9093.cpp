#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	cin.ignore(); // ���� �����
	while (t--)
	{
		string s;
		getline(cin,s); // ���� �Է¹���
		string u;
		// ���ڿ� Ž��
		for (int i = 0; i < s.size(); i++)
		{
			// �����̸� �ܾ� ���� ���
			if (s[i] == ' ')
			{
				reverse(u.begin(), u.end());
				cout << u << ' ';
				u = ""; // ���ο� �ܾ �����ϱ� ���� �ʱ�ȭ
			}
			// �׷��� ������ �ܾ� ����
			else
				u.push_back(s[i]);
			
		}
		// ������ �ܾ� ���� ���
		reverse(u.begin(), u.end());
		cout << u;
		cout << '\n';
	}
}