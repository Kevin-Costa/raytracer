/*
** my_putstr.c for minishell2 in /home/rousse_3/rendu/PSU_2013_minishell2/src
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Thu Mar  6 15:56:37 2014 rousse_3
** Last update Thu Mar  6 15:56:38 2014 rousse_3
*/

#include	<stdlib.h>
#include	"lib.h"

int		my_putstr(char *str)
{
  int		i;

  if (str == NULL)
    return (-1);
  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return (1);
}

int		my_putstr_error(char *str)
{
  int		i;

  if (str == NULL)
    return (-1);
  i = 0;
  while (str[i] != '\0')
    {
      my_putchar_error(str[i]);
      i++;
    }
  return (1);
}
