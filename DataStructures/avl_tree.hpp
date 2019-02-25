#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include "i_tree.hpp"
#include "avl_node.hpp"
#include <functional>

template <class K, class V>
class avl_tree : i_tree<K, V>
{
public:
	avl_tree();
	~avl_tree();
	avl_tree(const avl_tree& copy) noexcept(false);
	avl_tree& operator=(const avl_tree& rhs) noexcept(false);
	avl_tree(avl_tree&& copy) noexcept(false);
	avl_tree& operator=(avl_tree&& rhs) noexcept(false);
	void set_visit_function(std::function<void(const pair_node<K, V>* node)> visit) noexcept override { visit_ = visit; }
	void clear() noexcept override;
	bool empty() const noexcept override;
	void in_order() const noexcept override;
	void pre_order() const noexcept override;
	void post_order() const noexcept override;
	void breadth_first() const noexcept override;
	void insert(const K key, const V value) noexcept(false) override;
	void remove(const K key) noexcept(false) override;
	V search(const K& key) const noexcept(false) override;
	V& search(const K& key) noexcept(false) override;

private:
	avl_node<K, V>* root_ = nullptr;
	std::function<void(const pair_node<K, V> * const node)> visit_;

};



#endif