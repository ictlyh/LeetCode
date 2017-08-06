#include <iostream>
#include <string>

#define HAAB_DAYS_PER_YEAR 365
#define HAAB_DAYS_PER_MONTH 20
#define HAAB_MONTHS 19
#define TZOLKIN_DAYS_PER_YEAR 260
#define TZOLKIN_DAYS_PER_MONTH 20
#define TZOLKIN_MONTHS 13

using namespace std;

/*
 * Wrong Answer.
 */

string day_name_of_tzolkin[] = { \
  "ahau", "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik",\
  "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib",\
  "caban", "eznab", "canac" };

int getIntMonth(string month) {
  int m = 0;
  if(month == string("pop"))
    m = 1;
  else if(month == string("no"))
    m = 2;
  else if(month == string("zip"))
    m = 3;
  else if(month == string("zotz"))
    m = 4;
  else if(month == string("tzec"))
    m = 5;
  else if(month == string("xul"))
    m = 6;
  else if(month == string("yoxkin"))
    m = 7;
  else if(month == string("mol"))
    m = 8;
  else if(month == string("chen"))
    m = 9;
  else if(month == string("yax"))
    m = 10;
  else if(month == string("zac"))
    m = 11;
  else if(month == string("ceh"))
    m = 12;
  else if(month == string("mac"))
    m = 13;
  else if(month == string("kankin"))
    m = 14;
  else if(month == string("muan"))
    m = 15;
  else if(month == string("pax"))
    m = 16;
  else if(month == string("koyab"))
    m = 17;
  else if(month == string("cumhu"))
    m = 18;
  else if(month == string("uayet"))
    m = 19;
  return m;
}

void haabToTzolkin(int day, string month, int year) {
  int totalDay = HAAB_DAYS_PER_YEAR * year
    + (getIntMonth(month) - 1) * HAAB_DAYS_PER_MONTH
    + day + 1;
  int tyear = totalDay / TZOLKIN_DAYS_PER_YEAR;
  totalDay %= TZOLKIN_DAYS_PER_YEAR;
  int tmonth, tday;
  if(totalDay == 0) {
    tmonth = TZOLKIN_MONTHS;
    tday = 0;
  } else {
    tmonth = totalDay % TZOLKIN_MONTHS;
    if(tmonth == 0) tmonth = TZOLKIN_MONTHS;
    tday = totalDay % TZOLKIN_DAYS_PER_MONTH;
  }
  cout << tmonth << " " << day_name_of_tzolkin[tday] << " " << tyear << endl;
}

int main() {
  int n, day, year;
  string sday, month, syear;
  cin >> n;
  cout << n << endl;
  while(n--) {
    cin >> sday >> month >> syear;
    sday.erase(sday.size() - 1);
    day = (int)strtod(sday.c_str(), NULL);
    year = (int)strtod(syear.c_str(), NULL);
    haabToTzolkin(day, month, year);
  }
  return 0;
}