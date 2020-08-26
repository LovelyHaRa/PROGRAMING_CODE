#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> A, pSum, pSqSum;
vector<vector<int>> cache;
const int INF = 1987654321;

// �κ��� ���ϱ�
void precalc()
{
	sort(A.begin(), A.end()); // ����
	pSum[0] = A[0];
	pSqSum[0] = A[0] * A[0];
	for (int i = 1; i < n; i++)
	{
		pSum[i] = pSum[i - 1] + A[i];
		pSqSum[i] = pSqSum[i - 1] + A[i] * A[i];
	}
}

// �κ� ���� �̿��Ͽ� ��� �ð��� ����� ����ϴ� ���
int minError(int lo, int hi)
{
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]); // ������ ��
	int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]); // ���� ������ ��
	int m = int(0.5 + sum / (double)(hi - lo + 1)); // ��� �ݿø�
	int ret = sqSum - (2 * m*sum) + (m * m*(hi - lo + 1)); // �ּ� ���� ���ϱ�
	return ret;
}

// ���� ����: �־��� ������ s�� �������� ������ �ּ� ������ ���� ���ϱ�
int quantize(int from, int parts)
{
	// ���� ���: ��� ���ڸ� �� ����ȭ ���� ��
	if (from == n) return 0;
	// ���� ���: ���ڴ� ���Ҵµ� ���� �� ���� ��: ���� ū ���� ��ȯ
	if (parts == 0) return INF;
	// �޸������̼�
	int& ret = cache[from][parts];
	if (ret != -1) return ret;
	ret = INF; // �ּڰ��� ���ϱ� ���� �ʱ�ȭ
	// ������ ���̸� ��ȭ��Ű�� �ּ�ġ�� ã�´�
	for (int partSize = 1; from + partSize <= n; partSize++)
		ret = min(ret, minError(from, from + partSize - 1) + quantize(from + partSize, parts - 1));
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int s;
		cin >> n >> s;
		A.resize(n);
		pSum.resize(n);
		pSqSum.resize(n);
		cache.resize(n, vector<int>(s + 1, -1));
		for (int i = 0; i < n; i++)
			cin >> A[i];
		precalc();
		cout << quantize(0, s) << '\n';
		A.clear();
		pSum.clear();
		pSqSum.clear();
		cache.clear();
	}
}