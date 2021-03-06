#ifndef AEDA_UGHEATS_TIME_H
#define AEDA_UGHEATS_TIME_H

#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Date.h"
#include "../utils.h"

using namespace std;

class Time {
private:
    int hour;
    int min;
    int sec;
    Date date;
public:
    /**
     * Default Constructor.
     */
    Time() = default;

    /**
     * Constructor of a Time from the hour, minutes and seconds given.
     */
    Time(int hour, int min, int sec);

    /**
     * Constructor of a Time object with non-null date
     */
    Time(int hour, int min, int sec, Date date);

    /**
     * Constructor of a Time object from a time_t type
     * @param time
     */
    Time(const time_t &time);

    /** Constructor of a Time from a given time in the format of a string.
     * @param time_str is what you want to transform in a Time.
     */
    Time(string time_str);


    //Metodos Set

    /** Sets the hour of a Time.
     * @param hour is the parameter you want the new Time to have.
     */
    void setHour(int hour);

    /** Sets the minutes of a Time.
     * @param min is the parameter you want the new Time to have.
     */
    void setMin(int min);

    /** Sets the seconds of a Time.
     * @param hour is the parameter you want the new Time to have.
     */
    void setSec(int sec);

    /**
     * Sets the Date of a Time object.
     * @param date is the parameter you want the new Time to have.
     */
    void setDate(Date date);

    /**
     * Sets the time (hours, minutes, seconds) of a Time object, not altering the date.
     * @param time
     */
    void setTime(Time time);


    //Metodos Get

    /**
     * @return the Time's hour.
     */
    int getHour() const;

    /**
     * @return the Time's minutes.
     */
    int getMin() const;

    /**
     * @return the Time's seconds.
     */
    int getSec() const;

    /**
     * @return the Date object in the Time object
     */
    Date getDate() const;


    //Other Methods

    /** Displays the Time in a nice format.
     * @param out is the ostream.
     * @param time is the Time you want to display.
     */
    friend ostream& operator<<(ostream& out, const Time &time);

    /** Compares two times.
     * @param t is the Time to compare to.
     */
    bool operator<(const Time &t);

    /** Compares two times.
     * @param t is the Time to compare to.
     */
    bool operator>(const Time &t);

    /** Compares two times.
     * The times are equal if the hour, min and sec are the same.
     * @param t is the Time to compare to.
     */
    bool operator==(const Time &t);

    /** Adds a given amount of minutes to a Time oject.
     * @param min is the amount of minutes to add.
     * @return the resulting Time object.
     */
    Time addtime(int min);
};


#endif //AEDA_UGHEATS_TIME_H
