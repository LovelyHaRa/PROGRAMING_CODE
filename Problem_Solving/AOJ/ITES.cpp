#include<iostream>
#include<queue>

using namespace std;

// ���� ������
struct RNG
{
	unsigned seed;
	RNG() : seed(1983) {} // ������
	unsigned next()
	{
		unsigned ret = seed; // ������ �����ؾ��� ���� ������
		seed = ((seed * 214013u) + 2531011u); // ���� �� �̸� ���
		return ret % 10000 + 1; // ������ ����
	}
};

// �¶��� �˰��� Ȱ��
int countRanges(int k, int n)
{
	RNG rng; // ���� ������
	queue<int> range;
	int ret = 0, rangeSum = 0;
	for (int i = 0; i < n; i++)
	{
		int newSignal = rng.next(); // ���ο� ������ �޴´�
		rangeSum += newSignal; // �����տ� �߰�
		range.push(newSignal); // ť�� ���� ���� ����

		// �������� k�� �ʰ��ϸ� k ���ϰ� �� ������ ť���� ���� �� �����տ��� ����
		while (rangeSum > k)
		{
			rangeSum -= range.front();
			range.pop();
		}
		// �������� k�� ��� ����� �� �߰�
		if (rangeSum == k) ret++;
	}
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int k, n;
		cin >> k >> n;
		cout << countRanges(k, n) << '\n';
	}
}