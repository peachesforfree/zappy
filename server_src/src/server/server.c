/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <sding@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 19:20:08 by sding             #+#    #+#             */
/*   Updated: 2018/08/29 19:20:09 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

/*
** Usage: ./server -p <port> -x <width> -y <height> 
**            -n <team> [<team>] [<team>] ... -c <nb> -t <t>
**  1 -p port number
**  3 -x world width
**  5 -y world height
**  7 -n team\_name\_1 team\_name\_2 ...
**  8 + nb -c number of clients authorized at the beginning of the game
**  10 + nb -t time unit divider (the greater t is, the faster the game will go)
*/

/*
** generate resource by randomize the map[y][x][res];
** method:
**  1. increase res 0 ~ 6 
**  2. while loop (fixed number of set) square root of map_x
**  3. while loop (fixed width + height times)
*/

void    generate_resource(void)
{
    int res;
    int count;

    res = 0;
    count = (int)sqrt(g_env.map_x) * (g_env.map_x + g_env.map_y);
    while (count-- > 0)
        while (res < 7)
            g_env.map[rand() % g_env.map_y][rand() % g_env.map_x][res++]++;
}


void    game_loop()
{
    generate_resource();
    //server_client(); // this will be a select loop

    // free struct(); // include t_team 
}

void    server_usage(void)
{
    printf("Usage: ./server -p <port> -x <width> -y <height> \
            -n <team> [<team>] [<team>] ... -c <nb> -t <t>\n");
    printf("-p port number\n-x world width\n-y world height\n");
    printf("-n team\\_name\\_1 team\\_name\\_2 ...\n");
    printf("-c number of clients authorized at the beginning of the game\n");
    printf("-t time unit divider \
            (the greater t is, the faster the game will go)\n");
}

int     main(int argc, char **argv)
{
    // t_env   env;

    // bzero(&g_env, sizeof(t_env);
    if (argc < 13 || !read_flags(argc, argv, &g_env))
    {
        printf("reading flags\n");
        server_usage();
        return (0);
    }
    game_loop();
    print_flags(&g_env);
    print_team(g_env.teams);
    return (0);
}
