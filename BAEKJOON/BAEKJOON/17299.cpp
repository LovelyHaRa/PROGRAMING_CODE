#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> a(n); // ����
	vector<int> count(1000001); // ī���� ����
	vector<int> res(n, -1); // ����ū�� ����
	stack<int> s; // ������ �ε��� ����
	for (int i = 0; i < n; i++)
	{
		cin >> a[i]; // ���� ����
		count[a[i]]++; // ī����
	}
	for (int i = 0; i < n; i++)
	{
		// ����ū�� ����: ���� ��ġ�� ī���� ���� ������ ī���� ������ ���� �� ���� ���ÿ��� ����
		while (!s.empty() && count[a[s.top()]] < count[a[i]])
		{
			res[s.top()] = a[i]; // ��� ����
			s.pop();
		}
		// �ε��� ���� �ױ�
		s.push(i);
	}
	// ��� ���
	for (int i = 0; i < n; i++) cout << res[i] << ' ';

}