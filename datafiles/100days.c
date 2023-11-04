

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define TIMESTRSIZE     1024

int main(void)
{
    time_t stamp;
    struct tm *tm;
    char timestr[TIMESTRSIZE];

    stamp = time(NULL);
    tm= localtime(&stamp);
    strftime(timestr, TIMESTRSIZE,\
             "Now: %Y-%m-%d", tm);

    puts(timestr);
    
/**
 *  初始想法
    stamp += 100*24*3600;
    tm= localtime(&stamp);
    strftime(timestr, TIMESTRSIZE,\
             "after 100 days: %Y-%m-%d", tm);
**/ 

    tm->tm_mday += 100;
    mktime(tm);
    strftime(timestr, TIMESTRSIZE,\
             "after 100 days: %Y-%m-%d", tm);

    puts(timestr);

    exit(0);
}


