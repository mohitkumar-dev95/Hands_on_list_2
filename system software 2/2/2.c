/*
======================================================================================
Name        : 02
Author      : Mohit Kumar
Description : Print system resource limits using getrlimit system call
======================================================================================
*/

#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit l;

    getrlimit(RLIMIT_CPU, &l);
    if (l.rlim_cur == RLIM_INFINITY) printf("CPU time: Soft=Unlimited ");
    else printf("CPU time: Soft=%ld ", (long)l.rlim_cur);
    if (l.rlim_max == RLIM_INFINITY) printf("Hard=Unlimited\n");
    else printf("Hard=%ld\n", (long)l.rlim_max);

    getrlimit(RLIMIT_FSIZE, &l);
    if (l.rlim_cur == RLIM_INFINITY) printf("File size: Soft=Unlimited ");
    else printf("File size: Soft=%ld ", (long)l.rlim_cur);
    if (l.rlim_max == RLIM_INFINITY) printf("Hard=Unlimited\n");
    else printf("Hard=%ld\n", (long)l.rlim_max);

    getrlimit(RLIMIT_DATA, &l);
    if (l.rlim_cur == RLIM_INFINITY) printf("Data size: Soft=Unlimited ");
    else printf("Data size: Soft=%ld ", (long)l.rlim_cur);
    if (l.rlim_max == RLIM_INFINITY) printf("Hard=Unlimited\n");
    else printf("Hard=%ld\n", (long)l.rlim_max);

    return 0;
}

/*
======================================================================================
output:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim 2.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 2.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ /a.out
bash: /a.out: No such file or directory
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
CPU time: Soft=Unlimited Hard=Unlimited
File size: Soft=Unlimited Hard=Unlimited
Data size: Soft=Unlimited Hard=Unlimited
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ 
======================================================================================
*/
