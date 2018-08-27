/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sding <sding@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:50:07 by sding             #+#    #+#             */
/*   Updated: 2018/08/14 17:06:21 by sding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

typedef struct	s_cmd
{
	char		*cmd;
	int			delay_time;
	void		(*func)();
}				t_cmd;

/*
****************************************
** this is the dispatch table in cmd.c *
****************************************
* * the sign o -> is the note that the function has been handled

t_cmd	g_cmd[] =
{
	{"advance", 7, cmd_advance},			// advance one square
o	{"right", 7, cmd_right},				// turn right 90 degrees
o	{"left", 7, cmd_left},					// turn left 90 degrees
	{"see", 7, cmd_see},					// see
o	{"inventory", 1, cmd_inventory},		// inventory
	{"take", 7, cmd_take},					// take an object
	{"put", 7, cmd_put},					// put down an object
	{"kick", 7, cmd_kick},					// kick a player from the square
	{"braodcast", 7, cmd_broadcast},		// broadcast
	{"incantation", 300, cmd_incantation},	// begin the incantation
	{"fork", 42, cmd_fork},					// fork a player
	{"connect_nbr", 0, cmd_connect_nbr},	// know the number of unused connections by the team

	//{"", , cmd_death},// deadth -> clear out the queue and FD_CLR fd_sets;
	{NULL, 0, NULL},
}
*****************************************
*/

#endif
