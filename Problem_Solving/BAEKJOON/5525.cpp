#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	int n, m;
	string s;
	cin >> n >> m >> s;
	int cnt = 0, res = 0; // �������� ã�� ����, ���� ��ġ ����
	for (int i = 0; i < m - 2; i++)
	{
		// IOI ������ ã�´�
		if (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I')
		{
			cnt++; // �������� ã�� ���� ����
			// ���� ������ �������� ã�� ������ ��������
			if (cnt == n)
			{
				res++; // ���� ��ġ ���� ����
				cnt--; // �������� ã�� ������ ���� ��Ű�� ���ؼ� �ϳ� ����
			}
			i++; // ��ĭ �ǳʶٱ�(������ ������ O �̱� ����)
		}
		else cnt = 0; // �������� ã�� ���� �ʱ�ȭ
	}
	cout << res << '\n'; // ��� ���
}