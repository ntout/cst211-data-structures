#ifndef PAIR_NODE_HPP
#define PAIR_NODE_HPP

#include "node.hpp"

template <class K, class V>
class pair_node : public node<V>
{
public:
	pair_node() = delete;
	K get_key() const noexcept { return key_; }
	K& get_key() noexcept { return key_; }
	void set_key(const K key) noexcept(false) { key_ = key; }
	virtual ~pair_node() = default;

protected:
	pair_node(const K key, const V value) noexcept
		: node<V>(value), key_(key){}
	pair_node(const pair_node& copy) noexcept;
	pair_node(pair_node&& copy) noexcept;
	pair_node& operator=(const pair_node& rhs) noexcept;
	pair_node& operator=(pair_node&& rhs) noexcept;

	K key_;
};

template <class K, class V>
pair_node<K, V>::pair_node(const pair_node& copy) noexcept
{
	*this = copy;
}

template <class K, class V>
pair_node<K, V>::pair_node(pair_node&& copy) noexcept
{
	*this = std::move(copy);
}

template <class K, class V>
pair_node<K, V>& pair_node<K, V>::operator=(const pair_node& rhs) noexcept
{
	if (this != &rhs)
	{
		if (key_ == nullptr) delete key_;
		if (node<V>::data_ == nullptr) delete node<V>::data_;

		key_ = rhs.get_key();
		node<V>::data_ = rhs.get_data();
	}
	return *this;
}

template <class K, class V>
pair_node<K, V>& pair_node<K, V>::operator=(pair_node&& rhs) noexcept
{
	if (this != &rhs)
	{
		key_ = rhs.get_key();
	}
	return *this;
}


#endif
