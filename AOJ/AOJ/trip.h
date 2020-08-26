#pragma once
#include<cstdlib>
#include<utility>

template<typename T>
struct TripNode
{
	// ��忡 ����� ����
	T key;
	// �� ��带 ��Ʈ�� �ϴ� ����Ʈ���� ũ��
	int priority, size;
	// �� �ڽ� ����� ������
	TripNode *left, *right;
	// �����ڿ��� ���� �켱������ �����ϰ� size�� left/right�� �ʱ�ȭ�Ѵ�
	TripNode(const T& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL) {}
	void setLeft(TripNode* newLeft) { left = newLeft; calcSize(); }
	void setRight(TripNode* newRight) { right= newRight; calcSize(); }
	// size ����� �����Ѵ�
	void calcSize()
	{
		size = 1;
		if (left) size += left->size;
		if (right)size += right->size;
	}
};

template<typename T>
// root�� ��Ʈ�� �ϴ� Ʈ���� key �̸��� ���� �̻��� ���� ���� �� ���� Ʈ������ �и��Ѵ�
std::pair<TripNode<T>*, TripNode<T>*> split(TripNode<T>* root, T key)
{
	if (root == NULL) return std::pair<TripNode<T>*, TripNode<T>*>(NULL, NULL);
	// ��Ʈ�� key �̸��̸� ������ ����Ʈ���� �ɰ���
	if (root->key < key)
	{
		std::pair<TripNode<T>*, TripNode<T>*> rs = split(root->right, key);
		root->setRight(rs.first);
		return std::pair<TripNode<T>*, TripNode<T>*>(root, rs.second);
	}
	// ��Ʈ�� key �̻��̸� ���� ����Ʈ���� �ɰ���
	std::pair<TripNode<T>*, TripNode<T>*> ls = split(root->left, key);
	root->setLeft(ls.second);
	return std::pair<TripNode<T>*, TripNode<T>*>(ls.first, root);
}

template<typename T>
//  root�� ��Ʈ�� �ϴ� Ʈ���� �� ��� node�� ������ �� ��� Ʈ���� ��Ʈ�� ��ȯ�Ѵ�
TripNode<T>* insert(TripNode<T>* root, TripNode<T>* node)
{
	if (root == NULL) return node;
	// node�� ��Ʈ�� ��ü�ؾ� �Ѵ�. �ش� ����Ʈ���� ������ �߶� ���� �ڼ����� �Ѵ�
	if (root->priority < node->priority)
	{
		std::pair<TripNode<T>*, TripNode<T>*> splitted = split(root, node->key);
		node->setLeft(splitted.first);
		node->setRight(splitted.second);
		return node;
	}
	else if (node->key < root->key)
		root->setLeft(insert(root->left, node));
	else
		root->setRight(insert(root->right, node));
	return root;
}

template<typename T>
// a�� b�� �� ���� Ʈ���̰�, max(a) < min(b)�� �� �� ���� ��ģ��
TripNode<T>* merge(TripNode<T>* a, TripNode<T>* b)
{
	if (a == NULL) return b;
	if (b == NULL) return a;
	if (a->priority < b->priority) {
		b->setLeft(merge(a, b->left));
		return b;
	}
	a->setRight(merge(a->right, b));
	return a;
}

template<typename T>
// root�� ��Ʈ�� �ϴ� Ʈ������ key�� ����� ��� Ʈ���� ��Ʈ�� ��ȯ�Ѵ�
TripNode<T>* erase(TripNode<T>* root, T key)
{
	if (root == NULL) return root;
	// root�� ����� �� ����Ʈ���� ��ģ �� ��ȯ�Ѵ�
	if (root->key == key)
	{
		TripNode<T>* ret = merge(root->left, root->right);
		delete root;
		return ret;
	}
	if (key < root->key)
		root->setLeft(erase(root->left, key));
	else
		root->setRight(erase(root->right, key));
	return root;
}

template<typename T>
// root�� ��Ʈ�� �ϴ� Ʈ�� �߿��� k��° ���Ҹ� ��ȯ�Ѵ�
TripNode<T>* kth(TripNode<T>* root, int k)
{
	// ���� ����Ʈ���� ũ�⸦ �켱 ����Ѵ�
	int leftSize = 0;
	if (root->left != NULL) leftSize = root->left->size;
	if (k <= leftSize) return kth(root->left, k);
	if (k == leftSize + 1) return root;
	return kth(root->right, k - leftSize - 1);
}

template<typename T>
// key���� ���� Ű���� ���� ��ȯ�Ѵ�
int countLessThan(TripNode<T>* root, T key)
{
	if (root == NULL) return0;
	if (root->key >= key)
		return countLessThan(root->left, key);
	int ls = (root->left ? root->left->size : 0);
	return ls + 1 + countLessThan(root->right, key);
}