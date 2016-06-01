#ifndef DATE_H
#define	DATE_H
#include <string>

class Date {
    private:
        int month;
        int day;
        std::string year;
    public:
        Date();
        void setMonth(int);
        void setDay(int);
        void setYear(std::string);
        int getMonth()const;
        int getDay()const;
        std::string getYear()const;
        void prntMonth();
        void slashForm();
        void cmaForm();
        void mlaForm();
        class EmpClass{};
};

#endif	/* DATE_H */
