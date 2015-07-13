/*
** verify_args.h for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/server/incs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Mon Jun  1 13:32:56 2015 François De Matos
** Last update Wed Jul  8 16:05:18 2015 Guillaume Bovier-Lapierre
*/

#ifndef		VERIFY_ARGS_H_
# define	VERIFY_ARGS_H_

int             opt(t_serv *serv, int ac, char **av);
int             print_error_serv(int *bool);
int             find_opt(char *buff);
int		verify_args(int, char**, t_serv*);

int             opt_p(t_serv *serv, char **av, int *i);
int             opt_x(t_serv *serv, char **av, int *i);
int             opt_y(t_serv *serv, char **av, int *i);
int             opt_n(t_serv *serv, char **av, int *i);
int             opt_c(t_serv *serv, char **av, int *i);
int             opt_t(t_serv *serv, char **av, int *i);

#endif		/* !VERIFY_ARGS_H_ */
