#ifndef TREE_HPP
#define TREE_HPP
#include <functional>

template <class K, class V>
class i_tree
{
public:
	virtual ~i_tree() = default;
	virtual void clear() noexcept = 0;
	virtual void set_visit_function(std::function<void(const pair_node<K, V>* const node)> visit) noexcept = 0;
	virtual bool empty() const noexcept = 0;
	virtual void in_order() const noexcept = 0;
	virtual void pre_order() const noexcept = 0;
	virtual void post_order() const noexcept = 0;
	virtual void breadth_first() const noexcept = 0;
	virtual void insert(const K key, const V value) noexcept(false) = 0;
	virtual void remove(const K key) noexcept(false) = 0;
	virtual V search(const K& key) const noexcept(false) = 0;
	virtual V& search(const K& key) noexcept(false) = 0;
};

#endif