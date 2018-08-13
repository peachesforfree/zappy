#ifndef DATA_STRUCTURES_H
# define DATA_STRUCTURES_H

/*
 *world width and height - stored in t_map map
 * team names - stored in team_stats
 * clients authorized - 
 * 
*/




typedef struct      s_team
{
    int             team_number;
    char            *team_name;
    void            *next;
}                   t_team;

typedef struct      s_client
{
    int             socket;
    t_team          *team_stats;
}                   t_client;

typedef struct      s_players
{
    t_client *client;
    t_team   *team;
    int             food;
    int             level;
}                   t_players;

typedef struct          s_cell
{
    int                 linemate;
    int                 deraumere;
    int                 sibur;
    int                 mendiane;
    int                 phiras;
    int                 thystame;
    t_players    **players;
}                       t_cell;

typedef struct      s_map
{
    int             x;
    int             y;
    t_cell   **cell;

}                   t_map;

typedef struct          s_env
{
    int                 port;
    int                 authorized_clients;
    int                 time_unit;
    t_map               map;
    t_players    *players;
    t_team       *teams;
}                       t_env;

#endif