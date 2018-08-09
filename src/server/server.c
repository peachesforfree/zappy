#include "server.h"
#include "util.h"

void    print_flags(t_env *env)
{
    t_team *temp;

    temp = env->teams;
    printf("Port:%d\n", env->port);
    printf("width:%d\theight:%d\n", env->map.x, env->map.y);
    while (temp != NULL && temp->next != NULL)
    {
        printf("Teams:%s\n", temp->team_name);
        temp = temp->next;
    }
    printf("Max Clients:%d\n", env->authorized_clients);
    printf("Time:%d\n",env->time_unit);
}

int     main(int argc, char **argv)
{
    t_env   env;


    if (argc < 13 || !read_flags(argc, argv, &env))
    {
        printf("reading flags\n");
        server_usage();
        return (0);
    }
    print_flags(&env);
    return (0);
}