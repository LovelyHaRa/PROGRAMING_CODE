#include <string>
#include <vector>
#include<iostream>

using namespace std;

// ���� ��ȯ �� ���ڿ��� ��ȯ���ִ� �Լ�
string makeNum(int x, int n) {
	// 16���������� ���ڸ� ����
	char num[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	string res;
	// ���� ��ȯ
	while (x / n > 0) {
		res = num[x%n] + res;
		x /= n;
	}
	// ���� 0�϶�(������ ��) ���̱�
	res = num[x%n] + res;
	return res;
}

string solution(int n, int t, int m, int p) {
	string answer = "";
	string arr; // ���� �迭
	// �ּ� ũ��� t*m
	for (int i = 0; i < t*m; i++) {
		// ���� ���ڸ� ���� ��ȯ �� ���ڿ��� �̾����
		arr += makeNum(i, n);
	}
	// �ε������(p-1)���� �ڽ��� ���ʿ� ���ؾ� �ϴ� ���� �̾����
	for (int i = 0, q = p - 1; i < t; i++, q += m) {
		answer += arr[q];
	}
	return answer;
}