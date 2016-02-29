/*
** my_putchar.c for minishell2 in /home/rousse_3/rendu/PSU_2013_minishell2/src
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Thu Mar  6 15:56:07 2014 rousse_3
** Last update Thu Mar  6 15:56:08 2014 rousse_3
*/

#include	<unistd.h>
#include	"lib.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putchar_error(char c)
{
  write(2, &c, 1);
}
