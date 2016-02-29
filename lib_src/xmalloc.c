/*
** xmalloc.c for minishell2 in /home/rousse_3/rendu/PSU_2013_minishell2/src
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Thu Mar  6 15:57:56 2014 rousse_3
** Last update Thu Mar  6 16:01:01 2014 rousse_3
*/

#include	<stdlib.h>

void		*xmalloc(int size, int flag)
{
  void		*ptr;

  if (flag == 1)
    return (NULL);
  if ((ptr = malloc(size)) == NULL)
    return (NULL);
  return (ptr);
}
