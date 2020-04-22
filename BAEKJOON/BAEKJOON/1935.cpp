#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(void)
{
	int n;
	int a[26];
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	stack<double> st;
	double res = 0;
	for (int i = 0; i < s.size(); i++)
	{
		// 1. �ǿ����ڸ� ���ÿ� ����
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			st.push(a[s[i]-'A']);
		}
		// 2. �׷��� �ʴٸ�
		else
		{
			// 3. �ǿ����� �ΰ��� ���ÿ��� ������.
			double y =st.top();
			st.pop();
			double x = st.top();
			st.pop();
			// 4. �����ڿ� �ش��ϴ� ������ �����ؼ� ���ÿ� �ٽ� ���� �ִ´�.
			switch (s[i])
			{
			case '+':
				st.push(x + y);
				break;
			case '-':
				st.push(x - y);
				break;
			case '*':
				st.push(x*y);
				break;
			case '/':
				st.push(x / y);
				break;
			}
		}
	}
	// 5. 2�� ������ ���ÿ� �����ִ� ���� ���� ����̴�.
	cout << fixed;
	cout.precision(2);
	cout << st.top() << '\n';
}