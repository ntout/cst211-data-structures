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
#define spade	L"\x2660"
#define heart	L"\x2665"
#define diamond L"\x2666"
#define club	L"\x2663"

class card
{
public:
	explicit card() = default;
	~card() = default;

	const wchar_t*  get_rank() const;
	const wchar_t*  get_suit() const;
	void set_rank(const wchar_t* rank);
	void set_suit(const wchar_t* suit);

	void set_view();

	const wchar_t* get_view_element(int index) const;
	void display_full_card() const;
	void display_top_card() const;
	void display_r2_card() const;


private:
	const wchar_t* rank_{};
	const wchar_t* suit_{};

	// view[0] = color, view_[3] && view_[15] = rank_, view_[9] = suit_
	const wchar_t* view_[20] = {top , vert_line , L"r" , L"  " , vert_line
		, vert_line , L" " , L"s" , L" " , vert_line
		, vert_line , L"  " , L"r" , vert_line , bot };
};

inline const wchar_t* card::get_rank() const
{
	return rank_;
}

inline const wchar_t* card::get_suit() const
{
	return  rank_;
}

inline void card::set_rank(const wchar_t* rank)
{
	rank_ = rank;
}

inline void card::set_suit(const wchar_t* suit)
{
	suit_ = suit;
}

inline void card::set_view()
{
	// view[0] = color, view_[3] && view_[15] = rank_, view_[9] = suit_
	view_[2] = rank_;
	view_[12] = rank_;
	view_[7] = suit_;
	
}

inline const wchar_t* card::get_view_element(int index) const
{
	return view_[index];
}

inline void card::display_full_card() const
{
	if (suit_ == heart || suit_ == diamond)
	{
		std::wcout << RED << top << vert_line << rank_ << L"  " << vert_line << L"\n"
			<< vert_line << L" " << suit_ << L" " << vert_line << L"\n"
			<< vert_line << L"  " << rank_ << vert_line << L"\n" << bot << RESET;
	}
	else
	{
		std::wcout << GREEN << top << vert_line << rank_ << L"  " << vert_line << L"\n"
			<< vert_line << L" " << suit_ << L" " << vert_line << L"\n"
			<< vert_line << L"  " << rank_ << vert_line << L"\n" << bot << RESET;
	}



}

inline void card::display_top_card() const
{
	if (suit_ == heart || suit_ == diamond)
	{
		std::wcout << RED << top << RESET;
	}
	else
	{
		std::wcout << GREEN << top << RESET;
	}
}

inline void card::display_r2_card() const
{
	if (suit_ == heart || suit_ == diamond)
	{
		std::wcout << RED << view_[1] << view_[2] << view_[3] << view_[4] << RESET;
	}
	else
	{
		std::wcout << GREEN << view_[1] << view_[2] << view_[3] << view_[4] << RESET;
	}
}


#endif
