#include<iostream>

using namespace std;

// �ܱ� ó���� �ùķ��̼� �Ѵ�.
double balance(double amount, int duration, double rates, double monthlyPayment)
{
	double balance = amount; // ���� �ݾ׺��� ����
	// ������ ��ȯ
	for (int i = 0; i < duration; i++)
	{
		balance *= (1.0 + (rates / 12) / 100); // �ܱ� �Ҹ���
		balance -= monthlyPayment; // ��ȯ�ϱ�
	}
	return balance; // ���� �����
}

// �̺� Ž������ �Ѵ޿� ��ȯ�ؾ��� �ݾ��� ���Ѵ�
double payment(double amount, int duration, double rates)
{
	// �ּ�: �ƿ� ���� �ʴ� ���(0), �ִ�: �����޿� ��� ���� ��ȯ�ϴ� ���
	double lo = 0, hi = amount * (1.0 + (rates / 12) / 100);
	for (int i = 0; i < 100; i++)
	{
		double mid = (lo + hi) / 2.0;
		// ������� ��� ���� �� ������
		if (balance(amount, duration, rates, mid) <= 0)
			hi = mid; // �ּڰ� Ž��
		else
			lo = mid; // �ִ� Ž��
	}
	return hi; // ���� �� �ִ� ���� ��ȯ
}

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		double n, p;
		int m;
		cin >> n >> m >> p;
		cout.precision(12);
		cout << fixed << payment(n, m, p) << '\n';
	}
}