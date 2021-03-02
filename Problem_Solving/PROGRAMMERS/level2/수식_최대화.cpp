#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<long long> num; // ���� ���� �迭
vector<char> op; // ������ ���� �迭

// ������ ���ڿ� �����ڷ� �и�
void convert(string exp) {
	int n = 0;
	for (int i = 0; i < exp.size(); i++) {
		// ����
		if (exp[i] >= '0' && exp[i] <= '9') {
			n *= 10;
			n += (exp[i] - '0');
		}
		// ������
		else {
			num.push_back(n); // ���� ����
			n = 0;
			op.push_back(exp[i]); // ������ ����
		}
	}
	num.push_back(n); // ������ �� ����
}

char oper[] = { '+','-','*' }; // ������
bool check[3]; // oper Ž�� ���� Ȯ��
vector<char> selected; // oper���� ���õ� ������ �켱����
long long answer = 0; // ����� �ִ�(���� ��)

// a, b�� op�� ���
long long calc(long long a, long long b, char op) {
	switch (op) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	}
}

// ������ �켱������ dfs�� ���� �����Ǿ��� ��, �־��� ������ ���
void getScore() {
	// ����� ���� ����, ������ �迭�� ����
	vector<long long> cnum = num;
	vector<char> cop = op;
	// i: ������ �켱����, j: ���Ŀ� ����ִ� ������ ����
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < cop.size(); j++) {
			// �ش� �����ڰ� �켱������ �����ϸ�
			if (selected[i] == cop[j]) {
				cnum[j] = calc(cnum[j], cnum[j + 1], cop[j]); // ��� �� ù��° �ǿ����ڿ� ����
				cnum.erase(cnum.begin() + j + 1); // �ι�° �ǿ����� ����
				cop.erase(cop.begin() + j); // ���� ������ ����
				j--; // ��ü ���̰� 1 �پ����Ƿ� j�� ���� ��Ŵ
			}
		}
	}
	answer = max(answer, abs(cnum[0])); // ���� ���� �� �ִ� ����
}

// ��� ������ �켱������ Ž���ϱ� ���� dfs
void dfs(int cnt) {
	// ������ �켱������ �����Ǿ�����
	if (cnt == 3) {
		getScore(); // ���� ���
	}
	// ������ Ž��
	for (int i = 0; i < 3; i++) {
		// üũ �ȵǾ�������
		if (!check[i]) {
			check[i] = 1; // üũ
			selected.push_back(oper[i]); // �켱���� �迭 ����
			dfs(cnt + 1);
			// ���� ����
			check[i] = 0;
			selected.pop_back();
		}
	}
}

long long solution(string expression) {
	convert(expression); // ���� ����Ʈ
	dfs(0); // dfs Ž��
	return answer;
}