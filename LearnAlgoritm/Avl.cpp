#include "Avl.h"


size_t Avl::height(Node* node)
{
	return node ? node->height : 0;
}

int Avl::bfactor(Node* node)
{
	return height(node->right) - height(node->left);
}

void Avl::fix_height(Node* node)
{
	size_t h_left = height(node->left);
	size_t h_right = height(node->right);

	node->height = (h_left > h_right ? h_left : h_right) + 1;
}

// Поворот направо
Avl::Node* Avl::rotateRight(Node* node)
{
	Node* q = node->left;

	node->left = q->right;
	q->right = node;
	fix_height(node);
	fix_height(q);

	return q;
}

// Поворот налево
Avl::Node* Avl::rotateLeft(Node* node)
{
	Node* q = node->right;

	node->right = q->left;
	q->left = node;
	fix_height(node);
	fix_height(q);

	return q;
}

// выполняем балансировку дерева вокруг узла
Avl::Node* Avl::balance(Node* const node)
{
	// вычисляем правильную высоту для узла
	fix_height(node);

	// Балансируем дерево в зависимости от фактора балансировки
	if (bfactor(node) == 2)
	{
		if (bfactor(node->right) < 0)
			node->right = rotateRight(node->right);
		return rotateLeft(node);
	}

	if (bfactor(node) == -2)
	{
		if (bfactor(node->left) > 0)
			node->left = rotateLeft(node->left);
		return rotateRight(node);
	}

	// балансировка не нужна
	return node;
}

const Avl::Node* Avl::bfs(const int& key) const
{
	if (_root == nullptr)
		return nullptr;
	// Создаем пустую очередь для добавления узлов с одинакового уровня -
	// имеющие одинаковую высоту
	std::queue<Node*> q;
	// кладем корень в очередь
	q.push(_root);
	while (q.empty() == false)
	{
		Node* node = q.front();
		q.pop();

		if (node->key == key)
			return node;

		if (node->left != nullptr)
			q.push(node->left);
		if (node->right != nullptr)
			q.push(node->right);
	}
}

const Avl::Node* Avl::dfs(const Node* node, const int& key)
{
	if (_root == nullptr)
	{
		return nullptr;
	}
	std::queue<Node*> q;
	q.push(_root);
	while (q.empty() == false)
	{
		Node* node = q.front();
		if (node->key == key)
		{
			return node;
		}
		else if (node->key > key)
		{
			dfs(node->left, key);
		}
		else if (node->key < key)
		{
			dfs(node->right, key);
		}
	}
	return nullptr;
}

void Avl::insert(int&& key)
{
	Node* node = new Node(key);
	_root = insert(_root, node);
}

Avl::Node* Avl::insert(Node* root, Node* const node)
{
	if (!root)
		return node;

	if (node->key < root->key)
		root->left = insert(root->left, node);
	else
		root->right = insert(root->right, node);

	return balance(root);
}

Avl::Node* Avl::removemin(Node* node)
{
	if (!node->left)
		return node->right;

	node->left = removemin(node->left);

	return balance(node);
}

Avl::Node* Avl::findmin(Node* node)
{
	return node->left ? findmin(node->left) : node;
}

void Avl::delete_node(const int& key)
{
	_root = delete_node(_root, key);
}

Avl::Node* Avl::delete_node(Node* node, const int& key)
{
	if (!node)
		return 0;

	if (key < node->key)
		node->left = delete_node(node->left, key);
	else if (key > node->key)
		node->right = delete_node(node->right, key);
	else //  k == p->key
	{
		Node* q = node->left;
		Node* r = node->right;
		node->left = nullptr;
		node->right = nullptr;
		delete node;

		if (!r)
			return q;

		Node* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}

	return balance(node);
}