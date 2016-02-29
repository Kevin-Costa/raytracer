/*
** my_str_cmp.c for minishell2 in /home/rousse_3/rendu/PSU_2013_minishell2/src
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Thu Mar  6 15:57:02 2014 rousse_3
** Last update Sun Mar  9 00:31:28 2014 rousse_3
*/

#include	<stdlib.h>
#include	"lib.h"

int		my_str_cmp(char *str, char *str_bis)
{
  int		i;

  i = 0;
  if (str == NULL || str_bis == NULL)
    return (0);
  while (str[i] != '\0' && str_bis[i] != '\0')
    {
      if (str[i] != str_bis[i])
	return (0);
      i++;
    }
  if (str[i] == str_bis[i])
    return (1);
  return (0);
}

int		my_str_begin_cmp(char *str, char *str_bis)
{
  int		i;

  i = 0;
  while (str[i] != '\0' && str_bis[i] != '\0')
    {
      if (str[i] != str_bis[i])
	return (0);
      i++;
    }
  return (1);
}
