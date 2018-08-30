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
    print_flags(&g_env);
    print_team(g_env.teams);
    return (0);
}
