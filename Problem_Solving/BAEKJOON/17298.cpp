#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> a(n); // ����
	vector<int> res(n, -1); // ��ū���� ����
	stack<int> s; // ������ �ε��� ����
	s.push(0); // �ʱ� ���� ����
	for (int i = 0; i < n; i++)
	{
		cin >> a[i]; // ���� ����
		if (!i) continue; // ó�� ���� ���� �ǳʶٱ�
		// ��ū�� ����: ������ ����ְų� top �ε������� ���� ���� �� ����
		while (!s.empty() && a[s.top()] < a[i])
		{
			res[s.top()] = a[i];
			s.pop();
		}
		// �ε��� ���ÿ� �ױ�
		s.push(i);
	}
	// ��� ���
	for (int i = 0; i < n; i++) cout << res[i] << ' ';

}