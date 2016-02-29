/*
** my_str_cpy.c for minishell2 in /home/rousse_3/rendu/PSU_2013_minishell2/src
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Thu Mar  6 15:57:16 2014 rousse_3
** Last update Thu Mar  6 15:57:18 2014 rousse_3
*/

#include	<stdlib.h>
#include	"lib.h"

char		*my_str_cpy(char *str)
{
  int		i;
  char		*str_return;

  i = my_strlen(str);
  if ((str_return = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  while (str[i] != '\0')
    {
      str_return[i] = str[i];
      i++;
    }
  str_return[i] = '\0';
  return (str_return);
}
