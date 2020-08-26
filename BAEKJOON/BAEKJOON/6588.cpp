#include<iostream>
#include<vector>

using namespace std;

vector<int> prime(1000001);
vector<int> setprime;

// �����佺�׳׽��� ü
void getPrime()
{
	for (int i = 2; i < prime.size(); i++)
		prime[i] = i;
	for (int i = 2; i*i < prime.size(); i++)
	{
		if (!prime[i])
			continue;
		for (int j = i * 2; j < prime.size(); j += i)
			prime[j] = 0;
	}
}

int main(void)
{
	// �̰� ���ؼ� Ÿ�Ӿƿ�
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Ҽ� ���̺� ����
	getPrime();
	// �Ҽ� ������ ���� ����
	for (int i = 3; i < prime.size(); i++)
	{
		if (prime[i]) setprime.push_back(i);
	}
	while (1)
	{
		// �Է�
		int n;
		cin >> n;
		if (!n) break;
		int i;
		// �Ҽ� ���� Ž��(�Ҽ��� n/2 ������ Ž���Ǹ� ��)
		for (i = 0; i < setprime.size() && setprime[i] <= n / 2; i++)
		{
			// n-setprime[i] �� �Ҽ��̸� b-a�� �ִ밡 �Ǵ� �� ���� ����
			if (prime[n - setprime[i]])
			{
				cout << n << " = " << setprime[i] << " + " << n - setprime[i] << '\n';
				break;
			}
		}
		// �����ϴ� ������ ����
		if (i == setprime.size() || setprime[i] > n / 2)
			cout << "Goldbach's conjecture is wrong.\n";

	}
}