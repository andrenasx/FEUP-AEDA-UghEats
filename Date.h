#ifndef AEDA_UGHEATS_DATE_H
#define AEDA_UGHEATS_DATE_H

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public:
    //Metodos Set
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    //Metodos Get
    int getDay() const;
    int getMonth() const;
    int getYear() const;
};


#endif //AEDA_UGHEATS_DATE_H
