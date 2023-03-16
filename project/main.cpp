#include<iostream>
#include<cstring>
using namespace std;
class date {
public:
	date(int y = 1900, int m = 1, int d = 1) {
		year = y;
		month = m;
		day = d;
	}
	date(const string& s) {
		year = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0');
		month = (s[5] - '0') * 10 + s[6] - '0';
		day = (s[8] - '0') * 10 + s[9] - '0';
	}

private:
	int year, month, day;

public:
	void set(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}
	bool isLeapYear() {

		if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))return 0;
		else return 1;



	}
	bool isValid() {
		if (day > 31 || day < 1 || month>12 || month < 1)return 0;
		else {
			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
				if (day == 31)return 1;
			}
			else {
				if (day == 31)return 0;

			}
			if (month == 2) {
				if (day == 30)return 0;
				if (day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)))return 0;

			}
			return 1;

		}
	}


	int toInt() {
		long long m;
		return	m = year * 10000 + month * 100 + day;
	}


	date lastday() {
		date a;
		if (day ==1) {
			if (month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11) {
				a.day = 31;
				a.month = month - 1;
				a.year = year;
			}
			else {
				if (month == 3) {
					bool i;
					i = isLeapYear();
					if (i) {
						a.day = 29;
						a.month = month - 1;
						a.year = year;
					}
					else
					{
						a.day = 28;
						a.month = month - 1;
						a.year = year;
					}
				}

				if (month == 1) {
					a.day = 31;
					a.month = 12;
					a.year = year - 1;


				}





			}
		}
		else {
			a.day = day - 1;
			a.month = month;
			a.year = year;
		}
		return a;
	}

	date nextday() {
		date a;
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) {
			if (day == 31) {
				a.day = 1;
				a.month = month + 1;
				a.year = year;
			}
			else {
				a.day = day + 1;
				a.month = month;
				a.year = year;
			}
		}
		if (month == 12) {
			if (day == 31) {
				a.day = 1;
				a.month = 1;
				a.year = year + 1;
			}
			else {
				a.day = day + 1;
				a.month = month;
				a.year = year;
			}
		}
		if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day == 30) {
				a.day = 1;
				a.month = month + 1;
				a.year = year;
			}
			else {
				a.day = day + 1;
				a.month = month;
				a.year = year;
			}
		}
		if (month == 2) {
			int i;
			i = isLeapYear();
			if (i) {
				if (day == 29) {
					a.day = 1;
					a.month = 3;
					a.year = year;
				}
				else {
					a.day = day + 1;
					a.month = month;
					a.year = year;
				}
			}
			else {
				if (day == 28) {
					a.day = 1;
					a.month = 3;
					a.year = year;
				}
				else {
					a.day = day + 1;
					a.month = month;
					a.year = year;
				}

			}
		}return a;

	}



	void print() {
		cout << year << "//" << month << "//" << day << endl;

	}
	int getYear() {
		return year;
	}
	int getMonth() {
		return month;
	}
	int getDay() {
		return day;
	}
	void setYear(int y) {
		year = y;
	}
	void setMonth(int y) {
		month = y;
	}
	void setDay(int y) {
		day = y;
	}
	int compare(int a, int b) {
		if (a > b)return 1;
		if (a == b)return 0;
		if (a <b)return -1;

	}
	int compare(const date& d) {
		if (year == d.year) {
			if (month == d.month) {

				if (day == d.day)return 0;
				else {
					return compare(day, d.day);
				}

			}
			else {
				return compare(month, d.month);
			}

		}
		else { return compare(year, d.year); }
	}

};
int main() {
class	date c,d;
cout << "默认的时间";
cout << d.getYear() << ' ' << d.getMonth() << ' ' << d.getDay() << endl; 
string s= "2000-12-11";
	date b(s);
	cout << "字符串输入的时间"<<b.getYear() << ' ' << b.getMonth() << ' ' << b.getDay() << endl;
	b.set(2000, 11, 8);
	cout << "void set设置的时间" << b.getYear() << ' ' << b.getMonth() << ' ' << b.getDay() << endl;
	cout << "是否为有效日期" << b.isValid() << endl;
	cout << "判断当前对象是否闰年" << b.isLeapYear() << endl;
	cout << "把当前对象日期转换成一个整数" << b.toInt() << endl;
	c = b.lastday();
	cout << "返回当前对象的前一天日期" << c.toInt() << endl;
	c = b.nextday();
	cout << "返回当前对象的后一天日期" << c.toInt() << endl;
	cout << "打印日期"  << endl;
	b.print();
	cout << "返回当前对象的year值,返回当前对象的month值,返回当前对象的day值" << b.getYear() << b.getMonth() << b.getDay() << endl;
	c.setYear(5200); c.setMonth(12);
	c.setDay(14);
	cout << "用void 函数赋值后c的值" << c.getYear() << c.getMonth() << c.getDay() << endl;
	cout<<"比较大小"<<b.compare(c);

}