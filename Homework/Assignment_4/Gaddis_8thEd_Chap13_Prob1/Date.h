
#ifndef DATE_H
#define	DATE_H

class Date {
private:
    int month;
    int day;
    int year;
public:
    Date();
    void setMonth(int);
    void setDay(int);
    void setYear(int);
    int getMonth()const;
    int getDay()const;
    int getYear()const;
    void prntMonth();
    void slashForm();
    void cmaForm();
    void mlaForm();
};

#endif	/* DATE_H */

