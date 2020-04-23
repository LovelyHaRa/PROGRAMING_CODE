#include<iostream>
#include<vector>

using namespace std;

vector<int> prime;

// �����佺�׳׽� ü�� �̿��Ͽ� �Ҽ� ���̺� ����
void setPrime(int n)
{
	prime.resize(n + 1);
	prime[0] = prime[1] = 1;
	for (int i = 2; i <= n; i++) prime[i] = i;
	for (int i = 2; i*i <= n; i++)
	{
		if (prime[i] == i)
		{
			for (int j = i * i; j <= n; j += i)
				if (prime[j] == j) prime[j] = i;
		}
	}
}

int main(void)
{
	setPrime(1000000); // �Ҽ� ���̺� �����
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int cnt = 0;
		// ���� ���� ¦���̱� ������ n/2 �� �ݵ�� ������ ������
		// n/2 ������ ���� ������ �ٲ� �� ������
		for (int i = 2; i <= (n / 2); i++)
		{
			// i, n-i �� �Ѵ� �Ҽ��̸� ī��Ʈ
			if (prime[i] == i && prime[n - i] == (n - i))
				cnt++;
		}
		cout << cnt << '\n';
	}
}