/*
** my_putnbr.c for minishell2 in /home/rousse_3/rendu/PSU_2013_minishell2/src
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Thu Mar  6 15:56:20 2014 rousse_3
** Last update Thu Mar  6 15:56:21 2014 rousse_3
*/

#include	"lib.h"

static int	my_putnbr_r(int nbr)
{
  if (nbr == 0)
    return (0);
  else
    my_putnbr_r(nbr / 10);
  my_putchar(nbr % 10 + '0');
  return (0);
}

void		my_putnbr(int nbr)
{
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = -1 * nbr;
    }
  if (nbr != 0)
    my_putnbr_r(nbr);
  else
    my_putchar('0');
}
