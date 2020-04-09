#include <string>
#include <vector>

using namespace std;

string solution(int n) {
	string answer = "";
	// 1. �Է¹��� ���� 0�� �ɶ����� �ݺ�
	while (n) {
		// 2. 3���� ���� �������� �����ϴµ� 0�� 4�� �ٲ㼭 ���� ����(1,2,4)
		answer = to_string(!(n % 3) ? 4 : n % 3) + answer;
		// 3. ������ �������� ���� ���� 1 �����ϹǷ� 1�� ����� �ڸ����� �����ȴ�
		n = !(n % 3) ? n / 3 - 1 : n / 3;
	}
	return answer;
}