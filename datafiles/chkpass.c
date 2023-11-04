

#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>
#include <unistd.h>
#include <shadow.h>


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage...\n");
        exit(1);
    }

    char *input_pass;
    input_pass = getpass("PassWord:");

    struct spwd *shadowline;
    shadowline = getspnam(argv[1]);

    char *setting;
    setting = crypt_gensalt();  iinit
    /**
     * crypt_gensalt()函数用来生成crypt()函数的第二个参数
     * 教程时间太过久远，没有讲到这个函数
    **/

    char* crypted_pass;
    crypted_pass = crypt(input_pass, shadowline->sp_pwdp);

    if (strcmp(shadowline->sp_pwdp, crypted_pass) == 0)
    {
        puts("OK\n");
    }
    else {
        puts("failed\n");
    }
    exit(0);
}



