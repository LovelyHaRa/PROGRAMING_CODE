#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	unordered_map<string, int> dic; // key: ���ϸ�, value: ��ȣ
	vector<string> dic2; // key: ��ȣ, value: ���ϸ�
	// ���� ����
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		dic[s] = i + 1;
		dic2.push_back(s);
	}
	// ���� �˻�
	while(m--)
	{
		string s;
		cin >> s;
		// �����̸�
		if (s[0] >= '0' && s[0] <= '9')
			cout << dic2[stoi(s) - 1] << '\n';
		// ���ϸ��̸�
		else
			cout << dic[s] << '\n';
	}
}