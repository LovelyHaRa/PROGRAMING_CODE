#include<iostream>

using namespace std;

struct TreeNode {
	char label;
	TreeNode *left, *right;
};

// Ʈ���� ��� �߰�
void add(TreeNode* t, char r, char left, char right)
{
	if (t == NULL) return;
	// ��带 ã������ ����Ʈ�� ����
	if (t->label == r)
	{
		// ���� ����Ʈ�� ����
		if (left != '.')
		{
			t->left = new TreeNode();
			t->left->label = left;
		}
		// ������ ����Ʈ�� ����
		if (right != '.')
		{
			t->right = new TreeNode();
			t->right->label = right;
		}
		return;
	}
	// ���� Ʈ�� Ž��
	else
	{
		add(t->left, r, left, right);
		add(t->right, r, left, right);
	}
}

void preorder(TreeNode* T)
{
	if (T == NULL) return;
	cout << T->label;
	preorder(T->left);
	preorder(T->right);
}

void inorder(TreeNode* T)
{
	if (T == NULL) return;
	inorder(T->left);
	cout << T->label;
	inorder(T->right);
}

void postorder(TreeNode* T)
{
	if (T == NULL) return;
	postorder(T->left);
	postorder(T->right);
	cout << T->label;
}

int main(void)
{
	TreeNode* T = new TreeNode(); // Ʈ�� �ʱ�ȭ
	T->label = 'A'; // ��Ʈ�� �׻� A
	int n;
	cin >> n;
	while (n--)
	{
		char r, a, b;
		cin >> r >> a >> b;
		add(T, r, a, b); // Ʈ���� ��� �߰�
	}
	preorder(T);
	cout << '\n';
	inorder(T);
	cout << '\n';
	postorder(T);
	cout << '\n';
}