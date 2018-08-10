#include "client.h"

//  Usage: ./client -n <team> -p <port> [-h <hostname>]
//      -n team\_name
//  -p port
//  -h name of the host, by default it'll be localhost

int     print_usage(void)
{
    printf("Usage: ./client -n <team> -p <port> [-h <hostname>]\n");
    printf("-n team\\_name\t");
    printf("-p port\n");
    printf("-h name of the host, by default it'll be localhost\n");
    return (0);
}

int     main(int argc, char **argv)
{
    t_env env;

    if (argc < 5 || !read_flags(argc, argv, &env))
        return (print_usage());

    return (0);
}