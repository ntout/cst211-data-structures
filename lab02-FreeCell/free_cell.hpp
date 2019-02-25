#ifndef FREE_CELL_HPP
#define FREE_CELL_HPP
#include "deck.hpp"
#include "../DataStructures/static_stack.hpp"
#include "../DataStructures/dynamic_stack.hpp"

using std::cout;


class free_cell
{

public:
	explicit free_cell() = default;

	void deal_cards(deck d);
	card get_cells(int index);
	static_stack<card> get_home(int index);

	card get_nth(const int arr_index, const int ll_index);

	void display_table();
	void display_cell();
	void display_home();
	void display_game();

	void remove_card(char a, int c);
	void move_card();


private:
	dynamic_array<card> cell_;
	dynamic_array<static_stack<card>> home_;
	dynamic_array<dynamic_stack<card>> tableau_;
};

inline void free_cell::deal_cards(deck d)
{
	cell_.set_length(4);
	home_.set_length(4);
	for(auto i {0}; i < 4; ++i)
	{
		home_[i].set_size(13);
	}
	tableau_.set_length(8);
	for (auto card{ 0 }; card < 52; ++card)
	{
		tableau_[card % 8].push(d.get_card(card));
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
	auto temp = tableau_[0].size();
	for(auto i{1}; i < 8; ++i)
	{
		if(temp < tableau_[i].size())
		{
			temp = tableau_[i].size();
		}
	}
	for (auto j{ 0 }; j < temp; ++j)
	{
		cout << "*" << RESET << "  |";
		for (auto i{ 0 }; i < 8; ++i)
		{
			if(j < tableau_[i].size() || tableau_[i].empty())
			{
				get_nth(i, j).display_card();
			}
			else 
			{
				cout << "   ";
			}
		}
		cout << GREEN << " *\n";
	}
}

inline void free_cell::display_cell()
{
	cout << "|";
	for(auto i{0}; i < 4; ++i)
	{
		cell_[i].display_card();
	}
}

inline void free_cell::display_home()
{
	cout << "|";
	for (auto i{ 0 }; i < 4; ++i)
	{
		home_[i].peek().display_card();
	}
}

inline void free_cell::display_game()
{
	cout << GREEN << "\n****CELLS****";
	cout << "****";
	cout << "****HOME*****\n" << RESET;
	display_cell();
	cout << GREEN << " ** " << RESET;
	display_home();
	cout << GREEN << "\n c0 c1 c2 c3 **** h0 h1 h2 h3  \n";
	cout << "************TABLE*************\n";
	display_table();
	cout << GREEN << "*   t0 t1 t2 t3 t4 t5 t6 t7  *\n";
	cout << "******************************\n" << RESET;
	
}

inline void free_cell::remove_card(char a, int c)
{
	if (a == 't')
	{
		tableau_[c].pop();
	}
	else if (a == 'h')
	{
		home_[c].pop();
	}
	else if (a == 'c')
	{
		cell_[c].set_rank(" ");
		cell_[c].set_suit(" ");
	}
}

inline void free_cell::move_card()
{
	string input;

	cout << "Move a card(ex: card t3 to c2 = t3c2): ";
	std::cin >> input;

	const auto area = input[0];  //h = home, t = tableau, c = cell
	const int column = input[1] - 48;
	const auto destination = input[2];//h = home, t = tableau, c = cell
	const int dest_column = input[3] - 48;

	card c;

	if(area == 't')
	{
		c = tableau_[column].peek();
	}
	else if (area == 'h')
	{
		
		c = home_[column].peek();
	}
	else if (area == 'c')
	{
		c = cell_[column];
	}

	if (destination == 't')
	{
		if (tableau_[dest_column].peek().get_value() - c.get_value() == 1 || tableau_[dest_column].empty())
		{
			if (c.get_color() == tableau_[dest_column].peek().get_color())
			{
				cout << "\nCannot place card here: same color." << std::endl;
			}
			else
			{
				tableau_[dest_column].push(c);
				remove_card(area, column);
			}
		}
		else
		{
			cout << "\nCannot place card here: incorrent rank." << std::endl;
		}
	}

	else if (destination == 'h')
	{
		if(home_[dest_column].peek().get_rank() != " " && home_[dest_column].peek().get_suit() != " ")
		{
			if(c.get_suit() == home_[dest_column].peek().get_suit())
			{
				if(c.get_value() - home_[dest_column].peek().get_value() == 1)
				{
					home_[dest_column].push(c);
					remove_card(area, column);
				}
				else
				{
					cout << "\nCannot place card here: incorrent rank." << std::endl;
				}
			}
			else
			{
				cout << "\nCannot place card here: not the same suit." << std::endl;
			}
		}
		else
		{
			if(c.get_rank() == "A")
			{
				home_[dest_column].push(c);
				remove_card(area, column);
			}
			else
			{
				cout << "\nMust start with an Ace." << std::endl;
			}
		}
	}

	else if (destination == 'c')
	{
		cell_[dest_column] = c;
		remove_card(area, column);
	}
}




#endif



