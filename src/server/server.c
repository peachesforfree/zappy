#include "server.h"
#include "util.h"



int     main(int argc, char **argv)
{
    t_env   env;

    if (argc < 2 && !read_flags(argc, argv, &env))
    {
        server_usage();
        return (0);
    }
    return (0);
}