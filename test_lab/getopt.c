#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int opt;
    printf("argc : %d\n", argc);
    int i;
    printf("====================================\n");
    for (i = 0 ; i < argc ; i++)
    {
        printf("argv[%d] : %s\n", i, argv[i]);
    }
    printf("====================================\n");
    printf("Start getopt\n");
    while ((opt = getopt(argc, argv, "f:o")) != -1)
    {
        switch (opt) {
            case 'f' :
                printf("option -f arg:%s\n", optarg);
                break;
            case 'o' :
                printf("option -o\n");
                break;
            case '?' :
            default  :
                printf("usage\n");
                break;

        }
    }
    while (optind < argc)
    {
        printf("optind(%d): %s\n", optind, argv[optind++]);
    }
    printf("====================================\n");
    for (i = 0 ; i < argc ; i++)
    {
        printf("argv[%d] : %s\n", i, argv[i]);
    }
    printf("====================================\n");

}
