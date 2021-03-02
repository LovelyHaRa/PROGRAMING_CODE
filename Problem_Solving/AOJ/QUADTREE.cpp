#include<iostream>
#include<string>

using namespace std;

string reverse(string::iterator& it)
{
	char head = *it; // ù����
	++it; // �ݺ��� ����
	if (head == 'b' || head == 'w')
		return string(1, head); // b, w 1�� ������ ����� ����
	// x�̸� 4�и� ��� ���ȣ��
	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);
	// ������ ���� ���� ���� (3,4,1,2)
	return "x" + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main(void)
{
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		string::iterator it = s.begin();
		// �ݺ��� �����͸� �Ķ���ͷ� �����ν�, ������ ��ġ�� �Ź� ���� ����
		cout << reverse(it) << '\n';
	}
}