#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// �־��� �迭�� a���� b������ŭ �߶� ��ȯ
vector<int> slice(const vector<int>& v, int a, int b)
{
	return vector<int>(v.begin() + a, v.begin() + b);
}

// Ʈ���� ����Ž�� ����� ����Ž�� ����� �־��� �� ����Ž�� ����� ����Ѵ�.
void printPostOrder(const vector<int>& preorder, const vector<int>& inorder)
{
	// Ʈ���� ���Ե� ��� ��
	const int N = preorder.size();
	// ���� ���: �� �� Ʈ���� ���� ����
	if (preorder.empty()) return;
	// ��Ʈ�� ������ȸ �迭 �� ���ڸ�
	const int root = preorder[0];
	// ���� ����Ʈ�� ũ��� ����Ž�� ������� ��Ʈ�� ��ġ�� ã�Ƽ� �� �� �ִ�
	const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	// ���� ����Ʈ�� Ž��
	printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
	// ������ ����Ʈ�� Ž��
	printPostOrder(slice(preorder, L + 1, N), slice(inorder, L + 1, N));
	// ��Ʈ ���
	cout << root << ' ';
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		vector<int> preorder(n), inorder(n);
		for (int i = 0; i < n; i++) cin >> preorder[i];
		for (int i = 0; i < n; i++) cin >> inorder[i];
		printPostOrder(preorder, inorder);
		cout << '\n';
	}
}