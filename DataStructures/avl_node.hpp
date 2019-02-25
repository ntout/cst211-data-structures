#ifndef AVL_NODE_HPP
#define AVL_NODE_HPP

#include "pair_node.hpp"

template <class K, class V>
class avl_node : public pair_node<K, V>
{
public:
	avl_node(const K key, const V value, avl_node<K, V>* right = nullptr, avl_node<K, V>* left = nullptr);
	~avl_node() = default;
	avl_node(const avl_node & copy) noexcept;
	avl_node& operator=(const avl_node& rhs) noexcept;
	avl_node(avl_node && copy) noexcept;
	avl_node& operator=(avl_node&& rhs) noexcept;
	avl_node*& get_left() noexcept;
	avl_node*& get_right() noexcept;
	avl_node* get_left() const noexcept;
	avl_node* get_right() const noexcept;
	size_t height() const noexcept;
	void set_left(avl_node * const left) noexcept;
	void set_right(avl_node* const right) noexcept;
	void update_height() noexcept;

private:
	avl_node * left_ = nullptr;
	avl_node * right_ = nullptr;
	size_t height_ = 0;

};

#endif