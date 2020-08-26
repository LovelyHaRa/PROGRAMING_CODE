#include<iostream>
#include<list>

using namespace std;

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n, k;
		cin >> n >> k;
		list<int> survivors;
		for (int i = 1; i <= n; i++) survivors.push_back(i); // ��ȣ ����
		list<int>::iterator kill = survivors.begin(); // 1�� ������� �ڰ�
		// �θ� ��� ���� �� ���� �ݺ�
		while (n > 2)
		{
			kill = survivors.erase(kill); // ���� ��� �ڰ�, �����ʹ� ���� ����� ����Ų��
			// ���� ����Ʈ ó�� ����
			if (kill == survivors.end()) kill = survivors.begin();
			n--; // ��� �� ����
			// k-1������� ������ ����(��������� �̹� ����Ű�� �����Ƿ�)
			for (int i = 0; i < k - 1; i++)
			{
				kill++; // ������ ����
				// ���� ����Ʈ ó�� ����
				if (kill == survivors.end()) kill = survivors.begin();
			}
		}
		// �����ִ� �λ�� ���
		cout << survivors.front() << ' ' << survivors.back() << '\n';
	}
}