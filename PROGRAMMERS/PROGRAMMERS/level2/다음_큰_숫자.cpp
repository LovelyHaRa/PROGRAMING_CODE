#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(int n) {
	int answer = 0;
	int k = n;
	int count = 0;
	// 1. n�� 1�� ������ ���Ѵ�.
	while (k) {
		k % 2 ? count++ : count;
		k = k >> 1; // = k/2;
	}
	// 2. n+1���� 1�� ������Ű�鼭 Ž��
	k = n + 1;
	while (1) {
		int tcount = 0;
		int tk = k;
		// 3. ���� ���� 1�� ������ ���Ѵ�.
		while (tk) {
			tk % 2 ? tcount++ : tcount;
			tk = tk >> 1;
		}
		// 4. n�� 1�� ������ ������ ����
		if (count == tcount) return k;
		k++;
	}
}