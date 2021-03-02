#include<iostream>
#include<string>

using namespace std;

string words[50];
int n, k, res;

// ���� ���ĺ� ����, ������� ���ĺ�, ���ݱ��� ��� ���ĺ� ���� ������ ������
// ���ڸ� ���� �� �ִ��� Ȯ���Ѵ� 
void readWord(int dic, int alpha, int cnt)
{	
	// ���ڸ� ��� �� ������ŭ ����ٸ�
	if (cnt == k)
	{
		int canRead = 0; // ���� �� �ִ� �ܾ� ����
		for (int i = 0; i < n; i++)
		{
			int j;
			for (j = 4; j < words[i].size() - 4; j++)
			{
				// �ش� ���ڰ� ������ ���ٸ� �극��ũ
				if (!(dic & 1 << words[i][j] - 97))
					break;
			}
			// ������ �����ϸ� ���� �� ������ �ǹ�
			if (j == words[i].size() - 4) canRead++;
		}
		// �ִ밪 ����
		res = res < canRead ? canRead : res;
		return;
	}
	// ���� Ž��
	for (int i = alpha; i < 26; i++)
	{
		// ���ĺ��� ����� ���� ���¶��
		if (!(dic & 1 << i))
		{
			// ������ �߰�
			dic |= 1 << i;
			// �������� Ž��
			readWord(dic, i + 1, cnt + 1);
			// ���󺹱�
			dic &= ~(1 << i);
		}
	}
}

int main(void)
{
	int dic = 0; // ��Ʈ����ũ ���ĺ� ����
	// ������ ���λ�, ���̻� ���ĺ� �߰�
	for (char c : {'a', 'n', 't', 'i', 'c'})
		dic |= 1 << c - 97;
	cin >> n >> k;
	// k�� 5 �̸��̸� ���ڸ� ��� �� ����
	if (k - 5 < 0)
	{
		cout << 0 << '\n';
		return 0;
	}
	// k�� 26�̸� ��� ���ڸ� ��� �� �ִ�
	if (k == 26)
	{
		cout << n << '\n';
		return 0;
	}
	k -= 5; // �̹� ���λ�, ���̻� ���ĺ��� �����
	// �ܾ� �Է�
	for (int i = 0; i < n; i++)
		cin >> words[i];
	readWord(dic, 0, 0);
	cout << res << '\n';
}