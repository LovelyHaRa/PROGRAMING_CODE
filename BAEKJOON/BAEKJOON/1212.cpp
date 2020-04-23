#include<iostream>
#include<string>

using namespace std;

// ���ڸ��� 0���� ä���� �ʰ� ��ȯ
string nonZeroTransform(char a)
{
	switch (a) 
	{
	case '0': return "0";
	case '1': return "1";
	case '2': return "10";
	case '3': return "11";
	case '4': return "100";
	case '5': return "101";
	case '6': return "110";
	case '7': return "111";
	}
	return "";
}

// ���ڸ��� 0���� ä��� ��ȯ
string zeroTransform(char a)
{
	switch (a)
	{
	case '0': return "000";
	case '1': return "001";
	case '2': return "010";
	case '3': return "011";
	case '4': return "100";
	case '5': return "101";
	case '6': return "110";
	case '7': return "111";
	}
	return "";
}

int main(void)
{
	string s;
	cin >> s;
	string res; // ��� ������
	res += nonZeroTransform(s[0]); // �� ���ڸ� ���ڴ� ��ȯ �Ŀ� 0���� �����ϸ� �ȵ�
	// ������ ���ڴ� ���ڸ��� 0���� ä�� �������� ��� �迭�� ����
	for (int i = 1; i < s.size(); i++)
		res += zeroTransform(s[i]);
	cout << res;
}