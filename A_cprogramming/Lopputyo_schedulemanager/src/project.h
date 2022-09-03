#ifndef _PROJECT__H_
#define _PROJECT__H_

#endif //! _PROJECT__H_
typedef struct meeting Meeting;

struct meeting
{
    char* description;
    int month;
    int day;
    int hour;
    Meeting* next;
};