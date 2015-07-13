/*
** verify_args.h for zappy in /home/limagn_v/rendu/PSU_2014_zappy/client/incs
** 
** Made by Valentin Limagne
** Login   <limagn_v@epitech.net>
** 
** Started on  Mon Jun 15 14:59:02 2015 Valentin Limagne
** Last update Wed Jul  8 15:56:25 2015 Guillaume Bovier-Lapierre
*/

#ifndef         VERIFY_ARGS_H_
# define        VERIFY_ARGS_H_

int             opt(t_client *client, int ac, char **av);
int             print_error_serv(int *bool);
int             find_opt(char *buff);
int             verify_args(int, char**, t_client*);
int             opt_p(t_client *client, char **av, int *i);
int             opt_n(t_client *client, char **av, int *i);
int             opt_h(t_client *client, char **av, int *i);

#endif          /* !VERIFY_ARGS_H_ */
