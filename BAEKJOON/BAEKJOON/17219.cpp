#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	unordered_map<string, string> pw; // �ؽ� ���̺� ����
	string key;
	// ������ �߰�
	while(n--)
	{
		string value;
		cin >> key >> value;
		pw[key] = value;
	}
	// ������ �˻�
	while(m--)
	{
		cin >> key;
		cout << pw[key] << '\n';
	}
}