#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string s;
	cin >> s;
	int n;
	cin >> n;
	int k = 1;
	int res = 0;
	// �� �ڸ������� �������� üũ
	for (int i = s.size() - 1; i >= 0; i--)
	{
		// ���� �ڸ����� 10������ ��ȯ
		int t;
		if (s[i] >= 'A') t = s[i] - 'A' + 10;
		else t = s[i] - '0';
		// �� ����
		res += k * t;
		k *= n; // �ڸ��� ����
	}
	cout << res;
}