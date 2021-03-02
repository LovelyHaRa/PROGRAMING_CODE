#include<iostream>
#include<vector>
#include<string>

using namespace std;

int n;
vector<char> inequal;
vector<int> check(10);
string biggest, smallest;

// ���ǿ� ���� DFS Ž���� �ǽ��Ѵ�
void process(int cnt, string selected)
{
	// ���� ���: cnt==n+1
	if (cnt == n + 1)
	{
		// �ִ� ����
		if (biggest.compare(selected) < 0)
			biggest = selected;
		// �ּڰ� ����
		if (smallest.compare(selected) > 0)
			smallest = selected;
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		if (check[i]) continue; // ���� 1: ���ڴ� ��� �޶�� �Ѵ�.
		// ���� 2: �Է� ���� �ε�ȣ���� �����Ѵ�
		if (cnt > 0)
		{
			switch (inequal[cnt - 1])
			{
			case '>':
				if (selected[cnt - 1] <= (i + '0')) continue;
				break;
			case '<':
				if (selected[cnt - 1] >= (i + '0')) continue;
				break;
			}
		}
		// üũ
		check[i] = 1;
		// ���� �� Ž��
		process(cnt + 1, selected + to_string(i));
		// ���󺹱�
		check[i] = 0;
	}
}

int main(void)
{
	cin >> n;
	inequal.resize(n);
	for (int i = 0; i <= n; i++)
	{
		if (i != n) cin >> inequal[i];
		// �ʱⰪ ����
		biggest += to_string(i); // n=2�̸� 012
		smallest += to_string(9 - i); // n=2�̸� 987
	}
	process(0, "");
	cout << biggest << '\n' << smallest << '\n';
}