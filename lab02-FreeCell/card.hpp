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

class card
{
public:
	explicit card() = default;


	void display_card() const;


	const wchar_t*  get_rank() const;
	const wchar_t*  get_suit() const;
	void set_rank(const wchar_t* rank);
	void set_suit(const wchar_t* suit);

private:
	const wchar_t* rank_{};
	const wchar_t* suit_{};

};

inline void card::display_card() const
{
	if (suit_ == HEART || suit_ == DIAMOND)
	{
		std::wcout << RED << suit_ << rank_ << RESET;
	}
	else
	{
		std::wcout << GREEN << suit_ << rank_ << RESET;
	}
}

inline const wchar_t* card::get_rank() const
{
	return rank_;
}

inline const wchar_t* card::get_suit() const
{
	return  suit_;
}

inline void card::set_rank(const wchar_t* rank)
{
	rank_ = rank;
}

inline void card::set_suit(const wchar_t* suit)
{
	suit_ = suit;
}


#endif
