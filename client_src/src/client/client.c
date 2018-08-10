#include "client.h"
#include <stdio.h>

//  Usage: ./client -n <team> -p <port> [-h <hostname>]
//      -n team\_name
//  -p port
//  -h name of the host, by default it'll be localhost

int     print_usage(void)
{
    printf("\nUsage: ./client -n <team> -p <port> [-h <hostname>]\n");
    printf("-n team\\_name\t");
    printf("-p port\n");
    printf("-h name of the host, by default it'll be localhost\n\n");
    return (0);
}

void    test_print_flags(t_env *env)
{
    printf("-n %s\t-p %d\t-h %s\n", env->team_name, env->port, env->hostname);
}

int     main(int argc, char **argv)
{
    t_env env;

    if (!read_flags(argc, argv, &env))
        return (print_usage());
    
    test_print_flags(&env);

    return (0);
}