#ifndef FREE_CELL_HPP
#define FREE_CELL_HPP
#include "deck.hpp"
#include "../DataStructures/static_stack.hpp"
#include "../DataStructures/dynamic_stack.hpp"


class free_cell
{

public:
	explicit free_cell() = default;

	void deal_cards(deck d);


	card get_cells(int index);
	static_stack<card> get_home(int index);
	dynamic_stack<card> get_tableau(int index);

	void display_stack();
	card get_nth(const int arr_index, const int ll_index);
	void display_table();

private:
	dynamic_array<card> cell_;
	dynamic_array<static_stack<card>> home_;
	dynamic_array<dynamic_stack<card>> tableau_;
};

inline void free_cell::deal_cards(deck d)
{
	cell_.set_length(4);
	home_.set_length(4);
	tableau_.set_length(8);


	for (auto card{ 0 }; card < 52; ++card)
	{
		//if (card % 8 == 0)
		//{
		//	std::wcout << L"\n";
		//}
		tableau_[card % 8].push(d.get_card(card));
		//tableau_[card % 8].peek().display_card();
	}
}


inline card free_cell::get_cells(const int index)
{
	return cell_[index];
}

inline static_stack<card> free_cell::get_home(const int index)
{
	return home_[index];
}

inline dynamic_stack<card> free_cell::get_tableau(const int index)
{
	return tableau_[index];
}

inline void free_cell::display_stack()
{
	for (auto i{ 0 }; i < 8; ++i)
	{
		const auto head = tableau_[i].get_stack().get_head();
		auto disp = head;
		while (disp != nullptr)
		{
			//std::wcout << L"X";
			disp->get_data().display_card();
			if (disp->get_next() == nullptr)
			{
				break;
			}
			disp = disp->get_next();
		}
		std::wcout << "\n";
	}




}

inline card free_cell::get_nth(const int arr_index, const int ll_index)
{
	const auto head = tableau_[arr_index].get_stack().get_head();
	auto disp = head;
	auto count = 0;
	while (disp != nullptr)
	{
		if (count == ll_index)
		{
			break;
		}
		++count;
		if (disp->get_next() == nullptr)
		{
			break;
		}
		disp = disp->get_next();
	}
	return disp->get_data();
}

inline void free_cell::display_table()
{

	for (auto j{ 0 }; j < 13; ++j)
	{
		for (auto i{ 0 }; i < 8; ++i)
		{
			if (j < tableau_[i].size())
			{
				get_nth(i, j).display_card();
			}
		}
		std::wcout << L"\n";
	}
}


#endif