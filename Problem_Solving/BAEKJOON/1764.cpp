#include<iostream>
#include<set>
#include<string>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	set<string> s; // ���� ���� ��� ����
	// ���� ���� ��� �߰�
	while (n--)
	{
		string str;
		cin >> str;
		s.insert(str);
	}
	set<string> ss; // �赵 ���� ���� ��� ����
	// �赵 ���� ���� ��� �߰�
	while (m--)
	{
		string str;
		cin >> str;
		// ���� ���� ����̸� �߰�
		if (s.find(str) != s.end())
			ss.insert(str);			
	}
	// ���
	cout << ss.size() << '\n';
	for (auto it = ss.begin(); it != ss.end(); it++)
		cout << *it << '\n';
}