#include<iostream>
#include<queue>
#include<vector>

using namespace std;

// ���� �յ� ���� ������
struct RNG
{
	int seed, a, b;
	RNG(int _a, int _b) :a(_a), b(_b), seed(1983) {}
	int next()
	{
		int ret = seed; // ���� �õ�
		seed = ((seed*(long long)a) + b) % 20090711; // �� �õ� ����
		return ret; // ���� �õ� ����
	}
};

int runningMedian(int n, RNG rng)
{
	// �� ����
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int ret = 0; // �߰��� �հ� ����
	// �Һ���
	// 1. maxHeap ũ��� minHeap ũ�⺸�� �׻� �۰ų� ����
	// 2. maxHeap ��Ʈ�� minHeap ��Ʈ���� �׻� �۰ų� ����
	for (int i = 0; i < n; i++)
	{
		// 1�� �Һ��� ������Ű��
		if (maxHeap.size() == minHeap.size())
			maxHeap.push(rng.next());
		else
			minHeap.push(rng.next());
		// 2�� �Һ����� �������� ������ ���� ��Ʈ�� swap
		if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top())
		{
			int a = maxHeap.top(), b = minHeap.top();
			maxHeap.pop();
			minHeap.pop();
			maxHeap.push(b);
			minHeap.push(a);
		}
		// �߰��� ����
		ret = (ret + maxHeap.top()) % 20090711;
	}
	// ����
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n, a, b;
		cin >> n >> a >> b;
		RNG rng(a, b);
		cout << runningMedian(n, rng) << '\n';
	}
}