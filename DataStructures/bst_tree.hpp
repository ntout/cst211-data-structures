#ifndef BST_TREE_HPP
#define BST_TREE_HPP

#include "bst_node.hpp"
#include "i_tree.hpp"
#include <functional>
#include <iostream>
#include <queue>

template <class K, class V>
class bst_tree : public i_tree<K, V>
{
public:
	bst_tree();
	~bst_tree();
	bst_tree(const bst_tree& copy) noexcept(false);
	bst_tree& operator=(const bst_tree& rhs) noexcept(false);
	bst_tree(bst_tree&& copy) noexcept(false);
	bst_tree& operator=(bst_tree&& rhs) noexcept(false);
	void set_visit_function(std::function<void(const pair_node<K, V>* node)> visit) noexcept override { visit_ = visit; }
	void clear() noexcept override { clear(root_); root_ = nullptr; }
	bool empty() const noexcept override;
	void in_order() const noexcept override { in_order(root_); }
	void pre_order() const noexcept override { pre_order(root_); }
	void post_order() const noexcept override { post_order(root_); }
	void breadth_first() const noexcept override;
	void insert(const K key, const V value) noexcept(false) override { insert(root_, key, value); }
	void remove(const K key) noexcept(false) override { remove(root_, key); }
	V search(const K& key) const noexcept(false) override { return search(root_, key); }
	V& search(const K& key) noexcept(false) override { return search(root_, key); }

	K find_smallest() const noexcept(false) { return find_smallest(root_); }

private:
	bst_node<K, V>* root_ = nullptr;
	std::function<void(const pair_node<K, V> * const node)> visit_;

	void insert(bst_node<K, V>*&root, const K key, const V value) noexcept(false);
	void in_order(bst_node<K, V>* root) const noexcept;
	void pre_order(bst_node<K, V>* root) const noexcept;
	void post_order(bst_node<K, V>* root) const noexcept;
	void breadth_first(bst_node<K, V>* root, std::queue< bst_node<K, V>*> q) const noexcept;

	void remove(bst_node<K, V>* parent, const K key) noexcept(false);
	void remove_root_match();
	void remove_match(bst_node<K, V>* parent, bst_node<K, V>* match, bool left);
	void clear(bst_node<K, V>* root) noexcept;

	V search(bst_node<K, V>* root, const K& key) const noexcept(false);
	V& search(bst_node<K, V>* root, const K& key) noexcept(false);

	K find_smallest(bst_node<K, V>* root);

	bst_node<K, V>* create_node(const K key, const V value);

};

template <class K, class V>
bst_tree<K, V>::bst_tree()
{
	auto visit = [&](const pair_node<K, V> * const node)
	{
		std::cout << node->get_key() << " " << node->get_data() << std::endl;
	};

	visit_ = visit;
}

template <class K, class V>
bst_tree<K, V>::~bst_tree()
{
	bst_tree<K, V>::clear();
	delete root_;
}

template <class K, class V>
bst_tree<K, V>::bst_tree(const bst_tree& copy) noexcept(false)
{
	*this = copy;
}

template <class K, class V>
bst_tree<K, V>& bst_tree<K, V>::operator=(const bst_tree& rhs) noexcept(false)
{
	return *this;
}

template <class K, class V>
bst_tree<K, V>::bst_tree(bst_tree&& copy) noexcept(false)
{
}

template <class K, class V>
bst_tree<K, V>& bst_tree<K, V>::operator=(bst_tree&& rhs) noexcept(false)
{
	return *this;
}

template <class K, class V>
bool bst_tree<K, V>::empty() const noexcept
{
	return root_ == nullptr;
}

template <class K, class V>
void bst_tree<K, V>::breadth_first() const noexcept
{
	std::queue<bst_node<K, V>*> q;
	breadth_first(root_, q); 
}


template <class K, class V>
void bst_tree<K, V>::insert(bst_node<K, V>*& root, const K key, const V value) noexcept(false)
{
	if(root == nullptr)
	{
		root = create_node(key, value);
	}
	else
	{
		if (key < root->get_key()) 
		{
			insert(root->get_left(), key, value);
		}
		else
		{
			insert(root->get_right(), key, value);
		}
	}
}

template <class K, class V>
void bst_tree<K, V>::in_order(bst_node<K, V>* root) const noexcept
{
	if (root != nullptr)
	{
		in_order(root->get_left());
		visit_(root);
		in_order(root->get_right());
	}
}

template <class K, class V>
void bst_tree<K, V>::pre_order(bst_node<K, V>* root) const noexcept
{
	if (root != nullptr)
	{
		visit_(root);
		pre_order(root->get_left());
		pre_order(root->get_right());
	}
}

template <class K, class V>
void bst_tree<K, V>::post_order(bst_node<K, V>* root) const noexcept
{
	if (root != nullptr)
	{
		post_order(root->get_left());
		post_order(root->get_right());
		visit_(root);
	}
}

template <class K, class V>
void bst_tree<K, V>::breadth_first(bst_node<K, V>* root, std::queue< bst_node<K, V>*> q) const noexcept
{
	if(root_ != nullptr)
	{
		if (q.empty()) return;
		auto curr = q.front();
		visit_(curr);
		if (curr->get_left() != nullptr) q.push(curr->get_left());
		if (curr->get_right() != nullptr) q.push(curr->get_right());
		q.pop();
		breadth_first(curr, q);
	}
	else throw "Tree is empty";
}

template <class K, class V>
K bst_tree<K, V>::find_smallest(bst_node<K, V>* root)
{
	if(root_ == nullptr)
	{
		throw "tree is empty";
	}
	else
	{
		if(root->get_left() != nullptr)
		{
			return find_smallest(root->get_left());
		}
		else
		{
			return root->get_key();
		}
	}
}

template <class K, class V>
void bst_tree<K, V>::remove(bst_node<K, V>* parent, const K key) noexcept(false)
{
	if(root_ != nullptr)
	{
		if(root_->get_key() == key)
		{
			remove_root_match();
		}
		else
		{
			if(key < parent->get_key() && parent->get_left() != nullptr)
			{
				parent->get_left()->get_key() == key ?
				remove_match(parent, parent->get_left(), true) :
				remove(parent->get_left(), key);
			}
			else if (key > parent->get_key() && parent->get_right() != nullptr)
			{
				parent->get_right()->get_key() == key ?
				remove_match(parent, parent->get_right(), false) :
				remove(parent->get_right(), key);
			}
			else
			{
				throw "Key was not in the tree";
			}
		}
	}
	else throw "Tree is empty";
}

template <class K, class V>
void bst_tree<K, V>::remove_root_match()
{
	if(root_ != nullptr)
	{
		auto temp = root_;
		auto root_key = root_->get_key();

		//case 0 - 0 children
		if(root_->get_left() == nullptr && root_->get_right() == nullptr)
		{
			root_ = nullptr;
			delete temp;
		}
		//case 1 - 1 child
		else if(root_->get_left() == nullptr && root_->get_right() != nullptr)
		{
			root_ = root_->get_right();
			temp->get_right() = nullptr;
			delete temp;
		}
		//case 1 - 1 child
		else if (root_->get_left() != nullptr && root_->get_right() == nullptr)
		{
			root_ = root_->get_left();
			temp->get_left() = nullptr;
			delete temp;
		}
		//case 2 - 2 children
		else
		{
			K smallest_right_subtree = find_smallest(root_->get_right());
			remove(root_, smallest_right_subtree);
			root_->get_key() = smallest_right_subtree;
		}
	}
	else throw "Cannot remove. tree is empty";
}

template <class K, class V>
void bst_tree<K, V>::remove_match(bst_node<K, V>* parent, bst_node<K, V>* match, bool left)
{
	if(root_ != nullptr)
	{
		auto match_key = match->get_key();

		//case 0  - 0 children
		if(match->get_left() == nullptr && match->get_right() == nullptr)
		{
			bst_node<K, V> * temp = match;
			left ? parent->get_left() = nullptr : parent->get_right() = nullptr;
			delete temp;
		}
		//case 1 - 1 child
		else if (match->get_left() == nullptr && match->get_right() != nullptr)
		{
			left ? parent->get_left() = match->get_right() : parent->get_right() = match->get_right();
			match->get_right() = nullptr;
			delete match;
		}
		else if (match->get_left() != nullptr && match->get_right() == nullptr)
		{
			left ? parent->get_left() = match->get_left() : parent->get_right() = match->get_left();
			match->get_left() = nullptr;
			delete match;
		}
		//case 2 - 2 children
		else
		{
			K smallest_right_subtree = find_smallest(match->get_right());
			remove(match, smallest_right_subtree);
			match->get_key() = smallest_right_subtree;
		}
	}
	else throw "tree is empty";
}

template <class K, class V>
void bst_tree<K, V>::clear(bst_node<K, V>* root) noexcept
{
	if (root != nullptr)
	{
		clear(root->get_left());
		clear(root->get_right());
		root = nullptr;
	}
	delete root;
}

template <class K, class V>
V bst_tree<K, V>::search(bst_node<K, V>* root, const K& key) const noexcept(false)
{
	if(root != nullptr)
	{
		if(root->get_key() == key)
		{
			return root->get_data();
		}
		else
		{
			if(key < root->get_key())
			{
				return search(root->get_left(), key);
			}
			else
			{
				return search(root->get_right(), key);
			}
		}
	}
	else
	{
		throw "Key not in tree";
	}
}

template <class K, class V>
V& bst_tree<K, V>::search(bst_node<K, V>* root, const K& key) noexcept(false)
{
	if (root != nullptr)
	{
		if (root->get_key() == key)
		{
			return root->get_data();
		}
		else
		{
			if (key < root->get_key())
			{
				return search(root->get_left(), key);
			}
			else
			{
				return search(root->get_right(), key);
			}
		}
	}
	else
	{
		throw "Key not in tree";
	}
}

template <class K, class V>
bst_node<K, V>* bst_tree<K, V>::create_node(const K key, const V value)
{
	auto* n = new bst_node<K, V>(key, value, nullptr, nullptr);

	return n;
}

#endif
