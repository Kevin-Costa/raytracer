/*
** my_getnbr.c for minishell2 in /home/rousse_3/rendu/PSU_2013_minishell2/src
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Thu Mar  6 15:55:53 2014 rousse_3
** Last update Sun Mar  9 01:32:49 2014 rousse_3
*/

#include	<stdlib.h>
#include	"lib.h"

static int	my_nbr(char c, char *base)
{
  int		i;

  i = 0;
  while (base[i] != '\0')
    {
      if (c == base[i])
	return (i);
      i++;
    }
  return (0);
}

int		my_get_nbr(char *str)
{
  return (my_get_nbr_base(str, "0123456789"));
}

int		my_get_nbr_base(char *str, char *base)
{
  int		size;
  int		nbr;
  int		i;
  int		sign;

  if (str == NULL || base == NULL)
    return (-1);
  size = my_strlen(base);
  nbr = 0;
  sign = 1;
  i = 0;
  if (str[0] == '-')
    {
      sign = -1;
      i = 1;
    }
  if (str[0] == '+')
    i++;
  while (str[i] != '\0')
    {
      nbr = nbr * size + my_nbr(str[i], base);
      i++;
    }
  return (sign * nbr);
}
