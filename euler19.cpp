#include <iostream>
#include <vector>

using namespace std;

vector<int> monthdays = {
    /* JANUARY	*/ 31,
    /* FEBRUARY	*/ 28,
    /* MARCH	*/ 31,
    /* APRIL	*/ 30,
    /* MAY		*/ 31,
    /* JUNE		*/ 30,
    /* JULY		*/ 31,
    /* AUGUST	*/ 31,
    /* SEPTEMBER*/ 30,
    /* OCTOBER	*/ 31,
    /* NOVEMBER	*/ 30,
    /* DECEMBER	*/ 31};
bool printMatch = false;

bool isLeapYear(int y)
{
	if (y % 4 == 0) {
		if (y % 100 != 0) {
			return true;
		} else if (y % 400 == 0) {
			return true;
		}
	}
	return false;
}

int HowManySundays(int startDay, int startMonth, int startYear, int endDay,
		   int endMonth, int endYear)
{
	int firstWeekDay = 1;
	int firstMonth = 1;
	int firstYear = 1900;
	int curWeekDay = firstWeekDay;
	int sundays = 0;

	for (int year = firstYear; year <= endYear; year++) {
		if (isLeapYear(year) == 1) {
			monthdays[1] = 29;
		} else {
			monthdays[1] = 28;
		}
		for (int month = 1; month <= 12; month++) {

			for (int day = 1; day <= monthdays[month - 1]; day++) {

				if ((year == startYear && month >= startMonth &&
				     month <= endMonth && day >= startDay &&
				     day <= endDay) ||
				    (year >= startYear && year < endYear) ||
				    (year == endYear && month <= endMonth &&
				     day <= endDay)) {

					if (day == 1 && curWeekDay == 7) {
						if (printMatch == true) {
							cout << "day " << day
							     << "  \tmonth "
							     << month
							     << "  \tyear "
							     << year << "\n";
						}
						sundays++;
					}
				}

				curWeekDay++;
				if (curWeekDay > 7) {
					curWeekDay = 1;
				}
			}
		}
	}
	monthdays[1] = 28;

	return sundays;
}
// CUSTOM INPUT SYNTAX: START DAY, START MONTH, START YEAR, END DAY, END MONTH,
// END YEAR
int main(int argc, char *argv[])
{
	char choice;
	cout << "print matches?";
	choice = cin.get();
	if (choice == 'y') {
		cout << "YES\n";
		printMatch = true;

	} else {
		cout << "NO\n";
		printMatch = false;
	}
	int result{0};
	if (argc == 7) {
		result =
		    HowManySundays(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]),
				   atoi(argv[4]), atoi(argv[5]), atoi(argv[6]));
	} else {
		cout << "CUSTOM INPUT SYNTAX: START DAY, MONTH, YEAR, END DAY, "
			"MONTH, YEAR\nEXAMPLE: \"1 1 1901 31 12 2000\"\n";

		result = HowManySundays(1, 1, 1901, 31, 12, 2000);
	}
	cout << "RESULT: " << result << " sundays." << endl;

	return 0;
}
