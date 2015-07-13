/*
** lib.h for zappy in /home/de-mat_a/rendu/PSU_2014_zappy/server/libs
** 
** Made by François De Matos
** Login   <de-mat_a@epitech.net>
** 
** Started on  Mon Jun  1 16:46:29 2015 François De Matos
** Last update Wed Jul  8 16:05:44 2015 Guillaume Bovier-Lapierre
*/

#ifndef		LIB_H_
# define	LIB_H_

#include	<sys/select.h>
#include	<sys/time.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<time.h>
#include	<math.h>

#define		SQR(x)		x * x

int		get_fd(int, fd_set*);
void		exit_mess(int, char*);
void		exit_mess_close(int, char*, int);
int		distance(int, int, int, int);
char		*my_strcat(char*, char*);

#endif		/* !LIB_H_ */
