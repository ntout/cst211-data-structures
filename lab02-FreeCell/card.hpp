#ifndef CARD_HPP
#define CARD_HPP

#define RESET	"\033[0m"
#define BLACK	"\033[30m"      /* Black */
#define RED		"\033[31m"      /* Red */
#define GREEN	"\033[32m"      /* Green */
#define YELLOW	"\033[33m"      /* Yellow */
#define BLUE	"\033[34m"      /* Blue */
#define MAGENTA	"\033[35m"      /* Magenta */
#define CYAN	"\033[36m"      /* Cyan */
#define WHITE	"\033[37m"      /* White */

#define top		L"\x250c\x2500\x2500\x2500\x2510"
#define bot		L"\x2514\x2500\x2500\x2500\x2518"
#define vert_line  L"\x2502"
#define SPADE	L"\x2660"
#define HEART	L"\x2665"
#define DIAMOND L"\x2666"
#define club	L"\x2663"

using std::string;
using std::cout;

class card
{
public:
	explicit card() = default;
	//card(const card& copy);
	//card& operator=(const card& rhs);

	void display_card() const;
	void display_top() const;

	string  get_rank() const;
	string  get_suit() const;
	int get_value() const;
	int get_color() const;
	void set_rank(string rank);
	void set_suit(string suit);
	void set_value(int n);
	void set_color(int n);

private:
	string rank_{" "};
	string suit_{" "};
	int value_{};
	int color_{};

};

inline void card::display_card() const
{
	if (suit_ == "H" || suit_ == "D")
	{
		std::cout << RED << rank_ << suit_ << RESET << "|";
	}
	else
	{
		std::cout  << CYAN << rank_ << suit_ << RESET << "|";
	}
}

inline void card::display_top() const
{
	if (suit_ == "H" || suit_ == "D")
	{
		std::cout << RED << "---" << RESET;
	}
	else
	{
		std::cout << CYAN <<"---" << RESET;
	}
}

inline string card::get_rank() const
{
	return rank_;
}

inline string card::get_suit() const
{
	return  suit_;
}

inline int card::get_value() const
{
	return value_;
}

inline int card::get_color() const
{
	return color_;
}

inline void card::set_rank(string rank)
{
	rank_ = rank;
}

inline void card::set_suit(string suit)
{
	suit_ = suit;
}

inline void card::set_value(int n)
{
	value_ = n;
}

inline void card::set_color(int n)
{
	color_ = n;
}


#endif
