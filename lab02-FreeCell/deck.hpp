#ifndef DECK_HPP
#define DECK_HPP
#include "../DataStructures/array.hpp"
#include "card.hpp"
#include <random>


class deck
{
public:
	explicit  deck() = default;
	~deck() = default;

	card get_card(int index) const;

	void load_hopper();
	void shuffle();
	
private:
	std::string rank_[13] = {
		"A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"};
	std::string suit_[4] = { "H", "D", "C", "S" };
	dynamic_array<card> hopper_;
};

inline card deck::get_card(const int index) const
{
	return hopper_[index];
}

inline void deck::load_hopper()
{
	hopper_.set_length(52);
	auto i{ 0 };
	for (const auto& suit : suit_)
	{
		for (const auto& rank : rank_)
		{
			hopper_[i].set_rank(rank);
			hopper_[i].set_suit(suit);
			hopper_[i].set_value((i % 13) + 1);
			if(suit == "H" || suit == "D")
			{
				hopper_[i].set_color(0);
			}
			else(hopper_[i].set_color(1));
			i = i + 1;
		}
	}
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
