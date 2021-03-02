#include <string>
#include <vector>

using namespace std;

int N;
vector<int> col(15); // ���� �������� �ప�� ����
int cnt = 0;

// ���밪
int abs(int a, int b) {
	return a < b ? b - a : a - b;
}

bool isPossible(int row) {
	// ���� �࿡ �ְų� �밢���� �����ϸ� false
	for (int i = 0; i < row; i++) {
		if (col[row] == col[i] || (abs(col[row], col[i]) == abs(row, i))) return false;
	}
	return true;
}

// ��Ʈ��ŷ
void queen(int row) {
	if (row == N) {
		cnt++;
	}
	else {
		for (int i = 0; i < N; i++) {
			col[row] = i;
			if (isPossible(row)) {
				queen(row + 1);
			}
			else {
				col[row] = 0;
			}
		}
	}
	col[row] = 0;
}

int solution(int n) {
	N = n;
	queen(0);
	return cnt;
}