/*
** lib.h for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/client/libs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Fri Jun 12 01:10:46 2015 François De Matos
** Last update Wed Jul  8 15:53:19 2015 Guillaume Bovier-Lapierre
*/

#ifndef		LIB_H_
# define	LIB_H_

#include	<sys/select.h>
#include	<sys/time.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>

int		get_fd(int, fd_set*);
void		exit_mess(int, char*);
void		exit_mess_close(int, char*, int);

#endif		/* !LIB_H_ */
