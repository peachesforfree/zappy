#include "util.h"
#include "data_structures.h"
#include <stding.h>

void    server_usage(void)
{
    printf("Usage: ./server -p <port> -x <width> -y <height> -n <team> [<team>] [<team>] ... -c <nb> -t <t>\n");
    printf("-p port number\n-x world width\n-y world height\n");
    printf("-n team\\_name\\_1 team\\_name\\_2 ...\n");
    printf("-c number of clients authorized at the beginning of the game\n");
    printf("-t time unit divider (the greater t is, the faster the game will go)\n");
}

t_team  *team_struct_new(char *name, int number, t_team *next)
{
    t_team  *structure;

    structure = (t_team)malloc(sizeof(t_team));
    bzero(structure, sizeof(t_team));

    if (name != NULL)
        structure->team_name = strdup(name);
    if (number > 0)
        structure->team_number = number;
    if (next != NULL)
        structure->next_team = next;
    return (structure);
}

char    *args[] = {"-p","-x","-y","-n","-c","-t"};

int     number(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0'))
        if (isdigit(str[i]))
            i++;
        else
            return (0);
}

int    set_value(char flg, int i, t_env *env)
{
    int number;

    if (m == 0 || m == 1 || m == 2 || m == 4 || m == 5)
        if (number(flg))
            number = atoi(flg[i + 1]);
        else:
            return (0);
    if (m == 0)
        env->port = number;
    if (m == 1)
        env->map->x = number;
    if (m == 2)
        env->map->y = number;
    if (m == 3)
        env->teams = team_struct_new(flg, 0, env->teams);
    if (m == 4)
        env->client_number = number;
    if (m == 5)
        env->time_unit = number;
}

int     read_flags(int argc, char **argv, t_env *env)
{
    int i;
    int m;

    i = 1;
    while (i < argc)
    {
        m = 0;
        while (m < 6)
        {
            if (!strcmp(argv[i], args[m]) && argv[i + 1])
                if (!set_value(argv[i + 1], m, env))
                    printf("Argument invalid:%s\n", argv[i]):
                    return (0);
            m++:
        }
        i++;
    }
    return (1);
}