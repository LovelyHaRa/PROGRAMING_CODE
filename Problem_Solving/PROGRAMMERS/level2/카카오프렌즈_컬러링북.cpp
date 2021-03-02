#include <vector>

using namespace std;

int p, q; // m, n �������� ���

int area(int location, int x, int y, vector<vector<int>>& picture) {
	int sum = 1; // ���� ����, 1�� ������Ŵ
	// ��ǥ�� ������ �Ѿ�� ���, ���� ��ġ���� �ʴ� ��� 0�� ����
	if (x < 0 || y < 0 || x >= p || y >= q || picture[x][y] != location)
		return 0;
	else {
		// üũ�� �ǹ̷� 0�� ����
		picture[x][y] = 0;
		// 4���� ���Ž��
		sum += area(location, x, y + 1, picture);
		sum += area(location, x, y - 1, picture);
		sum += area(location, x + 1, y, picture);
		sum += area(location, x - 1, y, picture);
		// ���� ������ ��ȯ
		return sum;
	}
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	vector<int> answer(2);
	p = m;
	q = n;
	// 1. ���Ʈ ���� Ž��
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			// 2. üũ���� �ʾҰų� ���� ���� ��� �ǳʶ�
			if (!picture[i][j]) continue;
			// 3. ������ ���� ���ϱ� ���� ���Ž��
			int sum = area(picture[i][j], i, j, picture);
			number_of_area++; // ������ ����
			// �ִ� ����
			max_size_of_one_area = max_size_of_one_area < sum ? sum : max_size_of_one_area;
		}
	}
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}