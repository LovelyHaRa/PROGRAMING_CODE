// ���� ����
#include<iostream>
#include<stack>

using namespace std;

int main(void)
{
	stack<int> s;
	int k;
	cin >> k;
	// ��Ű�´�� �ϸ� ��
	int res = 0;
	for (int i = 0; i < k; i++)
	{
		int n;
		cin >> n;
		if (!n) // 0�� ��
		{
			res -= s.top(); // ���ð� ����
			s.pop();
		}
		else
		{
			// ���� ����
			res += n;
			s.push(n);
		}
	}
	cout << res << '\n';
}