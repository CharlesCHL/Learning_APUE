

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define TIMESTRSIZE     1024
#define FMTSTRSIZE      1024

/**
 *
 *  -y: year
 *  -m: month
 *  -d: day
 *  -H: hour
 *  -M: minter
 *  -S: second
 *
**/



int main(int argc, char **argv)
{
    time_t stamp;
    struct tm *tm;
    char timestr[TIMESTRSIZE];
    char c;
    char fmtstr[FMTSTRSIZE];
    FILE*fp = stdout;


    stamp = time(NULL);
    tm = localtime(&stamp);
    fmtstr[0] = '\0';
    
    while (1)
    {
        c = getopt(argc, argv, "-H:MSy:md");
        if (c < 0)
            break;
        switch (c) 
        {
            case 1:
                if (fp != stdout)
                    break;
                fp = fopen(argv[optind-1], "w");
                if (fp == NULL)
                {
                    perror("fopen()");
                    fp = stdout;
                }
                break;
            case 'H':
                if (strcmp(optarg, "12") == 0)
                    strcat(fmtstr, "%I(%P) ");
                else if (strcmp(optarg, "24") == 0)
                    strcat(fmtstr, "%H ");
                else 
                    fprintf(stderr, "Invalid argument of H\n");
                break;
            case 'M':
                strcat(fmtstr, "%M ");
                break;
            case 'S':
                strcat(fmtstr, "%S ");
                break;
            case 'y':
                if (strcmp(optarg, "2") == 0)
                    strcat(fmtstr, "%y ");
                else if (strcmp(optarg, "4") == 0) 
                    strcat(fmtstr, "%Y ");
                else 
                    fprintf(stderr, "Invalid argument of y\n");
                break;
            case 'm':
                strcat(fmtstr, "%m ");
                break;
            case 'd':
                strcat(fmtstr, "%d ");
                break;
            default:
                break;
        }
    }

	strcat(fmtstr, "\n");
    strftime(timestr, TIMESTRSIZE, fmtstr, tm);
    fputs(timestr, fp);

    if (fp != stdout)
        fclose(fp);
    
    exit(0);

}


