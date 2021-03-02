#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;
	int n = A.size();
	// ���� �ּڰ��� �� Ž������
	// ���� �迭���� �ִ�, �ٸ� ���� �迭���� �ּҰ��� ������
	// ���� ���� ���ϸ� �ȴ�.

	// 1. A�� ��������, B�� �������� ����(�ٲ� ����)
	sort(A.begin(), A.end(), greater<int>());
	sort(B.begin(), B.end());
	// 2. ��ġ�� ���� ���Ҹ� ���� ���� ���ϸ� ����
	for (int i = 0; i < n; i++) {
		answer += A[i] * B[i];

	return answer;
}