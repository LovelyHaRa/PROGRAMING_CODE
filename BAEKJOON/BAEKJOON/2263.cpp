#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> inorder, postorder, position;

// Ʈ���� ����Ž�� ����� ����Ž�� ����� �־��� �� ����Ž�� ����� ����Ѵ�.
void printPreOrder(int inStart, int inEnd, int postStart, int postEnd)
{
	// ���� ���: �� �� Ʈ���� ���� ����
	if (inStart > inEnd || postStart > postEnd) return;
	// ��Ʈ�� ������ȸ �迭 �� ���ڸ�
	const int root = postorder[postEnd];
	// ����Ž�� ������� ��Ʈ ��ġ �˻�
	int p = position[root];
	// ���� ����Ʈ�� ũ�� ���ϱ�
	int L = p - inStart;
	// ��Ʈ ���
	cout << root << ' ';
	// ���� ����Ʈ�� Ž��
	printPreOrder(inStart, p - 1, postStart, postStart + L - 1);
	// ������ ����Ʈ�� Ž��
	printPreOrder(p + 1, inEnd, postStart + L, postEnd - 1);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	inorder.resize(n+1);
	postorder.resize(n+1);
	position.resize(n+1);
	for (int i = 1; i <= n; i++) cin >> inorder[i];
	for (int i = 1; i <= n; i++) cin >> postorder[i];
	// position[i]= ����Ž�� ��� i����� ��ġ
	for (int i = 1; i <= n; i++) position[inorder[i]] = i;
	printPreOrder(1, n, 1, n);
	cout << '\n';
}