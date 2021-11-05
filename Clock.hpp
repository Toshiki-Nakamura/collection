#ifndef CLOCK_HPP
# define CLOCK_HPP

#include <iostream>
#include <string>

class Clock {
private:
	int hour;
	int min;
	int sec;
public:
	Clock(int h, int m, int s) : hour(h), min(m), sec(s)
	{shift();};
	Clock() : hour(0), min(0), sec(0) {};
	~Clock() {};
	Clock(const Clock &cpy) {*this = cpy;};
	Clock&	operator=(const Clock &src) {
		if (this == &src)
			return *this;
		this->hour = src.hour;
		this->min = src.min;
		this->sec = src.sec;
		return *this;
	};
	void	shift(void)
	{
		if (this->sec >= 60) {
			this->min += (this->sec / 60);
			this->sec %= 60;
		} else if (this->sec < 0) {
			int minus = this->sec * -1;
			this->sec = 60 - minus;
			this->min -= 1;
		}
		if (this->min >= 60) {
			this->hour += (this->min / 60);
			this->min %= 60;
		} else if (this->min < 0) {
			int minus = this->min * -1;
			this->min = 60 - minus;
			this->hour -= 1;
		}
	};
	void	increase_min(int n) {
		this->min += n;
		shift();
	};
	void	decrease_min(int m) {
		int h = 0;
		if (m >= 60) {
			h = m / 60;
			m = m % 60;
		}
		this->min -= m;
		decrease_hour(h);
		shift();
	};
	void	increase_sec(int n) {
		this->sec += n;
		shift();
	};
	void	decrease_sec(int s) {
		int m = 0;
		if (s >= 60) {
			m = s / 60;
			s = s % 60;
		}
		this->sec -= s;
		decrease_min(m);
		shift();
	};

	void	increase_hour(int n) {this->hour += n;};
	void	decrease_hour(int n) {this->hour -= n;};

	void	set_hour(int n) {this->hour = n;};
	void	set_min(int n) {this->min = n;};
	void	set_sec(int n) {this->sec = n;};

	int		get_hour(void) const {return this->hour;};
	int		get_min(void) const {return this->min;};
	int		get_sec(void) const {return this->sec;};

	std::string	to_str(std::string time) {
		char s[1024] = "";
		if (time == "H")
			sprintf(s, "%02d", this->hour);
		if (time == "M")
			sprintf(s, "%02d", this->min);
		if (time == "S")
			sprintf(s, "%02d", this->sec);
		std::string ans(s);
		return ans;
	};
};

std::ostream& operator<<(std::ostream& stream, const Clock& c) {
	char s[1024] = "";
	sprintf(s, "%02d:%02d:%02d", c.get_hour(), c.get_min(), c.get_sec());
	std::string ret(s);
	stream << ret;
	return stream;
};

#endif
