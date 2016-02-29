/*
** my_strlen.c for minishell2 in /home/rousse_3/rendu/PSU_2013_minishell2/src
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Thu Mar  6 15:57:33 2014 rousse_3
** Last update Thu Mar  6 15:57:34 2014 rousse_3
*/

#include	<stdlib.h>
#include	"lib.h"

int		my_strlen(char *str)
{
  int		i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}
