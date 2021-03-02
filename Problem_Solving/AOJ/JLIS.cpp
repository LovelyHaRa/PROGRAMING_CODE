#include<iostream>
#include<vector>
#include<limits>

using namespace std;

int n, m;
vector<int>A, B; // ����
vector<vector<int>> cache; // ĳ��
const long long NEGINF = numeric_limits<long long>::min(); // 64��Ʈ �ּҰ�

long long max(long long a, long long b) { return a > b ? a : b; }
int jlis(int indexA, int indexB)
{
	// �޸������̼�
	int& ret = cache[indexA + 1][indexB + 1];
	if (ret != -1) return ret;
	// ī��Ʈ�� A, B ���������� �ݵ�� �����ϹǷ� 2���� ����
	ret = 2;
	// a, b �� �ִ밪�� ����, -1�� �� -INF���� ����
	long long a = (indexA == -1 ? NEGINF : A[indexA]);
	long long b = (indexB == -1 ? NEGINF : B[indexB]); 
	long long maxElement = max(a, b);
	// A ���� �߿��� ���� ������ ��� Ž���Ѵ�.
	for (int i = indexA + 1; i < n; i++)
		if (maxElement < A[i]) ret = max(ret, jlis(i, indexB) + 1);
	// B ���� �߿��� ���� ������ ��� Ž���Ѵ�.
	for (int i = indexB + 1; i < m; i++)
		if (maxElement < B[i]) ret = max(ret, jlis(indexA, i) + 1);
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n >> m;
		A.resize(n);
		B.resize(m);
		cache.resize(n + 1, vector<int>(m + 1, -1)); // -1 �ε����� ����� ���̹Ƿ� size+1
		for (int i = 0; i < n; i++)
			cin >> A[i];
		for (int i = 0; i < m; i++)
			cin >> B[i];
		cout << jlis(-1, -1) - 2 << '\n'; // -1 ���� ���������Ƿ� ���� ������ -2 ����� �Ѵ�.
		A.clear();
		B.clear();
		cache.clear();
	}
}