/*
** my_strcat.c for minishell2 in /home/rousse_3/rendu/PSU_2013_minishell2/src
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Thu Mar  6 15:56:49 2014 rousse_3
** Last update Thu Mar  6 15:56:50 2014 rousse_3
*/

#include	<stdlib.h>
#include	"lib.h"

char		*my_strcat(char *str, char *str_bis)
{
  int		size;
  int		size_bis;
  int		j;
  char		*str_return;

  size = my_strlen(str);
  size_bis = my_strlen(str_bis);
  j = 0;
  if ((str_return = malloc(sizeof(char) * (size + size_bis + 1))) == NULL)
    return (NULL);
  while (j < size)
    {
      str_return[j] = str[j];
      j++;
    }
  j = 0;
  while (j < size_bis)
    {
      str_return[j + size] = str_bis[j];
      j++;
    }
  str_return[j + size] = '\0';
  return (str_return);
}
