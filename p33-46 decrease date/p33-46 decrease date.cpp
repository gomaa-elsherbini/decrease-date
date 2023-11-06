#include <iostream>
#include <ctime>
using namespace std;



enum enInterval { OneDay, TenDays, OneWeek, TenWeeks, OneMonth, FiveMonths, OneYear, TenYears, OneDecade, TenDecades, OneCentury, OneMelinium };

struct stDate
{
    short day;
    short month;
    short year;
};

short readNumber(string msg)
{
    short num;

    cout << msg;
    cin >> num;

    return num;
}

stDate readStDate()
{
    stDate Date;

    Date.day = readNumber("Please Enter a Day ");
    Date.month = readNumber("Please Enter a Month ");
    Date.year = readNumber("Please Enter a Year ");

    return Date;
}

bool isLeapYear(short year)
{
    return (year % 400 == 0 || ((year % 4 == 0) && (year % 100 != 0)));
}

short numberOfDaysInMonth(short year, short month)
{
    if (month == 2)
    {
        if (isLeapYear(year))
            return  29;
        else
            return  28;
    }

    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return  31;

    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;

    else
        return 0;
}

short numberOfDaysInYear(short year)
{
    return isLeapYear(year) ? 366 : 365;
}

bool isDate1BeforeDate2(stDate Date1, stDate Date2)
{
    //return (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? ((Date1.month < Date2.month) ? true : ((Date1.month == Date2.month) ? ((Date1.day < Date2.day) ? true : false) : false)) : false);
    return (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? true : (Date1.month == Date2.month ? (Date1.day < Date2.day) : false)) : false);
}

bool isDayIsLastDay(stDate Date)
{
    return Date.day == numberOfDaysInMonth(Date.year, Date.month);
}

bool isMonthIsLastMonth(stDate Date)
{
    return Date.month == 12;
}

stDate decreaseDateByOneDay(stDate Date)
{
    if (Date.day==1)
    {
        if (Date.month == 1)
        {
            Date.day = 31;
            Date.month = 12;
            Date.year--;
        }
        else
        {
            Date.month--;
            Date.day = numberOfDaysInMonth(Date.year, Date.month);
        }
    }
    else
        Date.day--;
    
    return Date;
}

stDate decreaseDateByXDays(stDate Date, short numberDays)
{
    for (short day = 1; day <= numberDays; day++)
        Date = decreaseDateByOneDay(Date);
    
    return Date;
}

stDate decreaseDateByOneWeek(stDate Date)
{
    return decreaseDateByXDays(Date, 7);
}

stDate decreaseDateByXWeeks(stDate Date, short numberWeeks)
{
    for (short week = 1; week <= numberWeeks; week++)
        Date = decreaseDateByOneWeek(Date);
    
    return Date;
}

stDate decreaseDateByOneMonth(stDate Date)
{
    if (Date.month == 1) 
    {
        Date.month = 12;
        Date.year--;
    }
    else
        Date.month--;
    
    short monthDays= numberOfDaysInMonth(Date.year, Date.month);
    Date.day = (Date.day > monthDays)? monthDays : Date.day;

    return Date;
}

stDate decreaseDateByXMonths(stDate Date, short numberMonths)
{
    for (short month = 1; month <= numberMonths; month++)
       Date = decreaseDateByOneMonth(Date);
    
    return Date;
}

stDate decreaseDateByOneYear(stDate Date)
{
    Date.year--;
    return Date;
}

stDate decreaseDateByXYears(stDate Date, short numberOfYears)
{
    for (short year = 1; year <= numberOfYears; year++)
        Date = decreaseDateByOneYear(Date);
    
    return Date;
}

stDate decreaseDateByXYearsFaster(stDate Date, short numberOfYears)
{
    Date.year -= numberOfYears;
    return Date;
}

stDate decreaseDateByOneDecade(stDate Date)
{
    Date.year -= 10;
    return Date;
}
       
stDate decreaseDateByXDecades(stDate Date, short numberDecades)
{
    for (short decade = 1; decade <= numberDecades; decade++)
        Date = decreaseDateByOneDecade(Date);

    return Date;
}
       
stDate decreaseDateByXDecadesFaster(stDate Date, short numberOfDecades)
{
    Date.year -= numberOfDecades * 10;
    return Date;
}
       
stDate decreaseDateByOneCentury(stDate Date)
{
    Date.year -= 100;
    return Date;
}
       
stDate decreaseDateByOneMilinium(stDate Date)
{
    Date.year -= 1000;
    return Date;
}





int main()
{
    stDate Date1, Date2;

    cout << "\nPlease Enter your date1\n\n";
    Date1 = readStDate();
    cout << "\n Date After \n";


    Date2 = decreaseDateByOneDay(Date1);
    cout << "01- decrease One day is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    
    Date2 = decreaseDateByXDays(Date2, 10);
    cout << "02- decrease 10 days is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    //
    Date2 = decreaseDateByOneWeek(Date2);
    cout << "03- decrease One week is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    //
    Date2 = decreaseDateByXWeeks(Date2, 10);
    cout << "04- decrease Ten weeks is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    
    Date2 = decreaseDateByOneMonth(Date2);
    cout << "05- decrease One Month is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    //
    Date2 = decreaseDateByXMonths(Date2, 5);
    cout << "06- decrease Five Months is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    //
    Date2 = decreaseDateByOneYear(Date2);
    cout << "07- decrease One Year is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    //
    Date2 = decreaseDateByXYears(Date2, 10);
    cout << "08- decrease Ten Years is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    //
    Date2 = decreaseDateByXYearsFaster(Date2, 10);
    cout << "08- decrease Ten Years (faster) is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    //
    Date2 = decreaseDateByOneDecade(Date2);
    cout << "10- decrease One Decade is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    
    Date2 = decreaseDateByXDecades(Date2, 10);
    cout << "11- decrease Ten Decades is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    
    Date2 = decreaseDateByXDecadesFaster(Date2, 10);
    cout << "09- decrease Ten Decades (faster) is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    
    Date2 = decreaseDateByOneCentury(Date2);
    cout << "13- decrease One Century is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    
    Date2 = decreaseDateByOneMilinium(Date2);
    cout << "14- decrease One Melinium is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;


    /*Date2 = increaseDate(Date1, enInterval::OneDay);
    cout << "01- Adding One day is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    Date2 = increaseDate(Date2, enInterval::TenDays);
    cout << "02- Adding 10 days is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    Date2 = increaseDate(Date2, enInterval::OneWeek);
    cout << "03- Adding One week is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    Date2 = increaseDate(Date2, enInterval::TenWeeks);
    cout << "04- Adding Ten weeks is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    Date2 = increaseDate(Date2, enInterval::OneMonth);
    cout << "05- Adding One Month is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    Date2 = increaseDate(Date2, enInterval::FiveMonths);
    cout << "06- Adding Five Months is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    Date2 = increaseDate(Date2, enInterval::OneYear);
    cout << "07- Adding One Year is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    Date2 = increaseDate(Date2, enInterval::TenYears);
    cout << "08- Adding Ten Years is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    Date2 = increaseDate(Date2, enInterval::TenYears);
    cout << "09- Adding Ten Years (Faster) is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    Date2 = increaseDate(Date2, enInterval::OneDecade);
    cout << "10- Adding One Decade is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    Date2 = increaseDate(Date2, enInterval::TenDecades);
    cout << "11- Adding Ten Decades is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    Date2 = increaseDate(Date2, enInterval::TenDecades);
    cout << "12- Adding Ten Decades (faster) is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    Date2 = increaseDate(Date2, enInterval::OneCentury);
    cout << "13- Adding One Century is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;
    Date2 = increaseDate(Date2, enInterval::OneMelinium);
    cout << "14- Adding One Melinium is: " << Date2.day << "/" << Date2.month << "/" << Date2.year << endl;*/
    system("pause>0");
    return main();
}