#ifndef DECK_HPP
#define DECK_HPP
#include "../DataStructures/array.hpp"
#include "card.hpp"
#include <random>


class deck
{
public:
	explicit  deck();
	~deck() = default;

	card get_card(int index) const;

	void shuffle();
	
private:
	const wchar_t* rank_[13] = {
		L"A", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"T", L"J", L"Q", L"K"};
	const wchar_t* suit_[4] = { L"\x2665", L"\x2666", L"\x2660", L"\x2663" };
	dynamic_array<card> hopper_;
};


inline deck::deck()
{
	hopper_.set_length(52);
	auto i{ 0 };
	for (const auto& suit : suit_)
	{
		for (const auto& rank : rank_)
		{
			hopper_[i].set_rank(rank);
			hopper_[i].set_suit(suit);
			hopper_[i].set_view();
			i = i + 1;
		}
	}
}

inline card deck::get_card(const int index) const
{
	return hopper_[index];
}

inline void deck::shuffle()
{
	std::mt19937 rng;
	rng.seed(std::random_device()());
	const std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 51);

	for(auto i{0}; i < 52; ++i)
	{
		const auto random_index = dist6(rng);
		std::swap(hopper_[i], hopper_[random_index]);
	}
}

#endif
