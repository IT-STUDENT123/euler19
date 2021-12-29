#include <iostream>
#include <vector>

using namespace std;

vector<int> monthDays = {
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
bool WANT_TO_PRINT_MATCH = false;

bool isLeapYear(int y)
{
	if (y % 4 == 0) {
		if (y % 100 == 0 && y % 400 != 0) {
			return false;
		}
		return true;
	}
	return false;
}

void PrintMatch(int month, int year)
{
	if (WANT_TO_PRINT_MATCH == true) {
		cout << "year " << year << "  month " << month << "\n";
	}
}

int checkDay(int day, int month, int year, int curWeekDay)
{
	if (day == 1 && curWeekDay == 7) {
		PrintMatch(month, year);
		return 1;
	}
	return 0;
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
			monthDays[1] = 29;
		} else {
			monthDays[1] = 28;
		}
		for (int month = 1; month <= 12; month++) {

			for (int day = 1; day <= monthDays[month - 1]; day++) {
				if (day == 1) {
					if (year == startYear &&
					    startYear == endYear &&
					    month >= startMonth &&
					    month <= endMonth) {
						sundays +=
						    (checkDay(day, month, year,
							      curWeekDay));
					} else if (year == startYear &&
						   startYear != endYear) {
						if (month >= startMonth) {
							sundays += (checkDay(
							    day, month, year,
							    curWeekDay));
						}
					} else if (year > startYear &&
						   year < endYear) {
						sundays +=
						    (checkDay(day, month, year,
							      curWeekDay));
					} else if (year == endYear &&
						   startYear != endYear &&
						   month <= endMonth) {
						sundays +=
						    (checkDay(day, month, year,
							      curWeekDay));
					}
				}

				curWeekDay++;
				if (curWeekDay > 7) {
					curWeekDay = 1;
				}
			}
		}
	}
	monthDays[1] = 28;

	return sundays;
}

int main(int argc, char *argv[])
{
	char choice = 'n';
	cout << "print matches?[y/n]";
	choice = cin.get();

	if (choice == 'y') {
		WANT_TO_PRINT_MATCH = true;

	} else {
		WANT_TO_PRINT_MATCH = false;
	}
	int result{0};

	if (argc == 5) {
		cout << "Using custom input...\n";
		result = HowManySundays(1, atoi(argv[1]), atoi(argv[2]), 1,
					atoi(argv[3]), atoi(argv[4]));

	} else {
		cout << "CUSTOM INPUT SYNTAX: [START MONTH] [START YEAR] [END "
			"MONTH] [END YEAR]\nEXAMPLE: \"1 1901 12 2000\"\n";

		result = HowManySundays(1, 1, 1901, 31, 12, 2000);
	}
	cout << "RESULT: " << result << " sundays." << endl;

	return 0;
}
