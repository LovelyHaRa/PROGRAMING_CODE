#include<iostream>
#include<list>
#include<string>

using namespace std;

int main(void)
{
	list<char> s;
	string t;
	cin >> t;
	// 1. ���ڿ� ����Ʈ�� ����
	for (int i = 0; i < t.size(); i++)
		s.push_back(t[i]);
	// 2. �ʱ� ������ ����
	list<char>::iterator start, end, cursor, del; // ������, ������, ������ġ, ����Ÿ��
	start = s.begin(); // �ʱ� ������ ����
	end = s.end(); // �ʱ� ������ ����
	cursor = s.end(); // ó�� Ŀ���� ��ġ�� ������
	// 3. ��� ó��
	int n;
	cin >> n;
	while (n--)
	{
		// 4. ��� ����
		char c;
		cin >> c;
		// ���� �̵�, Ŀ���� �������̸� ����
		if (c == 'L' && cursor != start)
			cursor--;
		// ������ �̵�, Ŀ���� �������̸� ����
		else if (c == 'D' && cursor != end)
			cursor++;
		// ����, Ŀ���� �������̸� ����
		else if (c == 'B' && cursor != start)
		{
			del = --cursor; // �������� ����
			cursor = s.erase(del); // ���ϰ��� ���� �� �ٷ� ������ ���ͷ�
		}
		// ����
		else if (c == 'P')
		{
			// ������ ���� �Է¹���
			char x;
			cin >> x;
			// Ŀ�� ��ġ�� ���� ó��
			if (start == cursor)
				s.push_front(x);
			else if (end == cursor)
				s.push_back(x);
			else
				s.insert(cursor, x); // ���� ���ͷ� ���ʿ� �߰���			
		}
		// ����, ������ ����Ʈ�� ���ŵǹǷ� ����, �������� ����
		start = s.begin();
		end = s.end();
	}
	// ����Ʈ ���
	for (auto it = s.begin(); it != s.end(); it++)
		cout << *it;
}