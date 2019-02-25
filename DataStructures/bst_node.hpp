#ifndef BST_NODE_HPP
#define BST_NODE_HPP

#include "pair_node.hpp"

template <class K, class V>
class bst_node : public pair_node<K, V>
{
public:
	bst_node(const K key, const V value, bst_node<K, V>* right = nullptr, bst_node<K, V>* left = nullptr);
	~bst_node();
	bst_node(const bst_node & copy) noexcept;
	bst_node& operator=(const bst_node& rhs) noexcept;
	bst_node(bst_node && copy) noexcept;
	bst_node& operator=(bst_node&& rhs) noexcept;
	bst_node*& get_left() noexcept;
	bst_node*& get_right() noexcept;
	bst_node* get_left() const noexcept;
	bst_node* get_right() const noexcept;
	void set_left(bst_node * const left) noexcept;
	void set_right(bst_node* const right) noexcept;

private:
	bst_node * left_ = nullptr;
	bst_node * right_ = nullptr;
};


template <class K, class V>
bst_node<K, V>::bst_node(const K key, const V value, bst_node<K, V>* right, bst_node<K, V>* left)
	: pair_node<K,V>(key, value)
{
	right_ = right;
	left_ = left;
}

template <class K, class V>
bst_node<K, V>::~bst_node()
{
	delete right_;
	delete left_;
}

template <class K, class V>
bst_node<K, V>::bst_node(const bst_node& copy) noexcept
{
	*this = copy;
}

template <class K, class V>
bst_node<K, V>& bst_node<K, V>::operator=(const bst_node& rhs) noexcept
{
	if (this != &rhs)
	{
		if (pair_node<K, V>::key_ == nullptr) delete pair_node<K, V>::key_;
		if (node<V>::data_ == nullptr) delete node<V>::data_;

		pair_node<K,V>::key_ = rhs.get_key();
		node<V>::data_ = rhs.get_data();
	}
	return *this;
}

template <class K, class V>
bst_node<K, V>::bst_node(bst_node&& copy) noexcept
{
	*this = std::move(copy);
}

template <class K, class V>
bst_node<K, V>& bst_node<K, V>::operator=(bst_node&& rhs) noexcept
{
	if (this != &rhs)
	{
		pair_node<K, V>::key_ = rhs.get_key();
		node<V>::data_ = rhs.get_data();
	}
	return *this;
}

template <class K, class V>
bst_node<K, V>*& bst_node<K, V>::get_left() noexcept
{
	return left_;
}

template <class K, class V>
bst_node<K, V>*& bst_node<K, V>::get_right() noexcept
{
	return right_;
}

template <class K, class V>
bst_node<K, V>* bst_node<K, V>::get_left() const noexcept
{
	return left_;
}

template <class K, class V>
bst_node<K, V>* bst_node<K, V>::get_right() const noexcept
{
	return right_;
}

template <class K, class V>
void bst_node<K, V>::set_left(bst_node* const left) noexcept
{
	try
	{
		left_ = left;
	}
	catch (const std::bad_alloc & exception)
	{
		throw adt_exception(exception.what());
	}
	
}

template <class K, class V>
void bst_node<K, V>::set_right(bst_node* const right) noexcept
{
	try
	{
		right_ = right;
	}
	catch (const std::bad_alloc & exception)
	{
		throw adt_exception(exception.what());
	}
}

#endif
