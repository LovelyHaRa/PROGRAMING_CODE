#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string s;
	cin >> s;
	string res; // ��� ������
	// ������ ��ȯ �迭
	string nonZeroBin[] = { "0","1","10","11","100","101","110","111" };
	string zeroBin[] = { "000","001","010","011","100","101","110","111" };
	res += nonZeroBin[s[0]-'0']; // �� ���ڸ� ���ڴ� ��ȯ �Ŀ� 0���� �����ϸ� �ȵ�
	// ������ ���ڴ� ���ڸ��� 0���� ä�� �������� ��� �迭�� ����
	for (int i = 1; i < s.size(); i++)
		res += zeroBin[s[i]-'0'];
	cout << res;
}