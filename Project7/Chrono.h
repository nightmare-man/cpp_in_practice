#pragma once
#include <iostream>
namespace Chrono {
	enum class Month
	{
		jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
	};
	class Date {
	public:
		class Invalid{};
		Date(int y, Month m, int d);
		//列表初始化只用写在定义而不用写在声明
		Date();//默认初始化 拷贝初始化
		int day()const { return d; }//成员函数的const后缀表示不修改成员
		Month month()const { return m; }
		int year() const { return y; }
		void add_day(int n);
		void add_month(int n);
		void add_yeaer(int n);
	private:
		int y;
		Month m;
		int d;
	};
	bool is_date(int y, Month m, int d);
	bool leapyear(int y);//判断闰年
	bool operator==(const Date& a ,const Date& b);
	bool operator!=(const Date& a, const Date& b);
	std::ostream& operator<<(std::ostream& os, const Date& d);
	std::istream& operator>>(std::istream& is, Date& dd);
}


