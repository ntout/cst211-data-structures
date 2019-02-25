#ifndef BST_TREE_HPP
#define BST_TREE_HPP

#include "bst_node.hpp"
#include "i_tree.hpp"
#include <functional>
#include <iostream>

template <class K, class V>
class bst_tree : public i_tree<K, V>
{
public:
	bst_tree();
	~bst_tree() = default; //clear -> postorder (istead of visit, check if null, delete)
	bst_tree(const bst_tree& copy) noexcept(false);
	bst_tree& operator=(const bst_tree& rhs) noexcept(false);
	bst_tree(bst_tree&& copy) noexcept(false);
	bst_tree& operator=(bst_tree&& rhs) noexcept(false);
	void set_visit_function(std::function<void(const pair_node<K, V>* node)> visit) noexcept override { visit_ = visit; }
	void clear() noexcept override;
	bool empty() const noexcept override;
	void in_order() const noexcept override { in_order(root_); }
	void pre_order() const noexcept override { pre_order(root_); }
	void post_order() const noexcept override { post_order(root_); }
	void breadth_first() const noexcept override;
	void insert(const K key, const V value) noexcept(false) override;
	void remove(const K key) noexcept(false) override;
	V search(const K& key) const noexcept(false) override;
	V& search(const K& key) noexcept(false) override;

private:
	bst_node<K, V>* root_ = nullptr;
	std::function<void(const pair_node<K, V> * const node)> visit_;

	void insert(bst_node<K, V>*&root, const K key, const V value) noexcept(false);
	void in_order(bst_node<K, V>* root) const noexcept;
	void pre_order(bst_node<K, V>* root) const noexcept;
	void post_order(bst_node<K, V>* root) const noexcept;
	void remove(bst_node<K, V>* root) noexcept(false);
};

template <class K, class V>
bst_tree<K, V>::bst_tree()
{
	auto visit = [&](const pair_node<int, std::string> * const node)
	{
		std::cout << node->get_key() << " " << node->get_data() << std::endl;
	};

	visit_ = visit;
}

template <class K, class V>
bst_tree<K, V>::bst_tree(const bst_tree& copy) noexcept(false)
{
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
void bst_tree<K, V>::clear() noexcept
{

}

template <class K, class V>
bool bst_tree<K, V>::empty() const noexcept
{
	return true;
}

template <class K, class V>
void bst_tree<K, V>::breadth_first() const noexcept
{
}

template <class K, class V>
void bst_tree<K, V>::insert(const K key, const V value) noexcept(false)
{
	insert(root_, key, value);
}

template <class K, class V>
void bst_tree<K, V>::remove(const K key) noexcept(false)
{
	if(empty()){ throw "Tree is empty"; }
	else
	{
		auto curr = root_;
		auto prev = root_;
		auto found{false};
		while (curr != nullptr && found)
		{
			if (curr->get_key() == key) found = true;
			else
			{
				prev = curr;
				if (curr->get_key() > key) curr = curr->get_left();
				else curr = curr->get_right();
			}
		}
		if(curr == nullptr) { throw "Current equals nullptr"; }
		else if(found)
		{
			if (root_ == curr) remove(root_);
			else if (prev->get_key() > key) remove(prev->get_left());
			else remove(prev->get_right());
		}
	}
}

template <class K, class V>
V bst_tree<K, V>::search(const K& key) const noexcept(false)
{
	return V();
}

template <class K, class V>
V& bst_tree<K, V>::search(const K& key) noexcept(false)
{
	return V();
}

template <class K, class V>
void bst_tree<K, V>::insert(bst_node<K, V>*& root, const K key, const V value) noexcept(false)
{
	if(root == nullptr)
	{
		root = new bst_node<K, V>(key, value, nullptr, nullptr);
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
void bst_tree<K, V>::remove(bst_node<K, V>* root) noexcept(false)
{
	auto curr = root;
	if (root == nullptr) throw "Root == nullptr";
	//else if(root)
}


#endif
