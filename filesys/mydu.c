

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <glob.h>
#include <string.h>

#define PATHSIZE    1024


static int path_noloop(const char* path)
{
    char* pos;
    pos = strrchr(path, '/');
    if (pos == NULL)
        exit(1);
    if (strcmp(pos + 1, ".") == 0 || strcmp(pos + 1, "..") == 0)
        return 0;
    return 1;
}

static int64_t mydu(const char* path)
{
    struct stat statres;
    char nextpath[PATHSIZE];
    glob_t globres;


    if (lstat(path, &statres) != 0)
    {
        perror("lstat()");
        exit(1);
    }

    if (!S_ISDIR(statres.st_mode))
        return statres.st_blocks;

    strncpy(nextpath, path, PATHSIZE);
    strcat(nextpath, "/*");

    glob(nextpath, 0, NULL, &globres);


    strncpy(nextpath, path, PATHSIZE);
    strcat(nextpath, "/.*");

    glob(nextpath, GLOB_APPEND, NULL, &globres); 


    int64_t sum = 0;

    for (int i = 0; i < globres.gl_pathc; i++)
    {
        if (path_noloop(globres.gl_pathv[i]))
            sum += mydu(globres.gl_pathv[i]);
    }
    
    globfree(&globres);
    
    sum += statres.st_blocks;

    return sum;

}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage...\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++)
    {
        printf("%lld\t%s\n", mydu(argv[i]) / 2, argv[i]);
    }


    exit(0);


}



