#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
	string s;
	cin >> s;
	vector<string> tail(s.size());
	for (int i = 0; i < s.size(); i++)
	{
		// 1. ���̻� ����
		string t;
		for (int j = i; j < s.size(); j++)
			t += s[j];
		tail[i] = t;
	}
	// 2. ����
	sort(tail.begin(), tail.end());
	// 3. ���
	for (int i = 0; i < tail.size(); i++)
		cout << tail[i] << '\n';
}