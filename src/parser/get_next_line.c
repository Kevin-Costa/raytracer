/*
** get_next_line.c for get_next_line in /home/pruvos_m/rendu/PSU_2013_42sh/src
** 
** Made by Mael PRUVOST
** Login   <pruvos_m@epitech.net>
** 
** Started on  Fri May 23 16:35:03 2014 Mael PRUVOST
** Last update Fri May 30 13:20:22 2014 Elliott ZWERTVAEGHER
*/

#include	<unistd.h>
#include	<stdlib.h>

static int	my_cnl(char *stack)
{
  int		i;

  i = 0;
  while (stack[i] != '\0')
    {
      if (stack[i] == '\n')
	return (1);
      i++;
    }
  return (0);
}

static char	*my_fill_stack(char *stack, char *buff)
{
  int		slen;
  int		blen;
  char		*new_stack;

  slen = my_strlen(stack);
  blen = my_strlen(buff);
  if ((new_stack = malloc(sizeof(char) * (slen + blen + 1))) == NULL)
    return (NULL);
  slen = 0;
  while (stack[slen] != '\0')
    {
      new_stack[slen] = stack[slen];
      slen++;
    }
  blen = 0;
  while (buff[blen] != '\0')
    {
      new_stack[slen + blen] = buff[blen];
      blen++;
    }
  new_stack[slen + blen] = '\0';
  free(stack);
  return (new_stack);
}

static char	*my_move_stack(char *stack, int index)
{
  int		i;

  if (index == 0)
    {
      i = 0;
      while (stack != NULL && stack[i] != '\0')
	{
	  stack[i] = stack[i + 1];
	  i++;
	}
    }
  else if (index == 1)
    {
      if (stack != NULL)
	free(stack);
    }
  return (NULL);
}

static char	*my_put_result(char *stack)
{
  char		*result;
  int		i;

  i = 0;
  while (stack[i] != '\n' && stack[i] != '\0')
    i++;
  if (i == 0 && stack[i] == '\0')
    {
      free(stack);
      return (NULL);
    }
  if ((result = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  result[i] = '\0';
  while (i > 0)
    {
      i--;
      result[i] = stack[i];
    }
  while (stack[0] != '\n' && stack[0] != '\0')
    my_move_stack(stack, 0);
  if (stack[0] == '\n')
    my_move_stack(stack, 0);
  return (result);
}

char		*get_next_line2(const int fd)
{
  static char	buff[4097];
  static char	*stack = NULL;
  char		*result;
  int		rlen;

  rlen = 4096;
  if (stack == NULL)
    {
      if ((stack = malloc(sizeof(char) * 4097)) == NULL)
	return (NULL);
      stack[0] = '\0';
    }
  while (!my_cnl(stack) && rlen > 0)
    {
      if ((rlen = read(fd, buff, 4096)) == 0)
	return (my_move_stack(stack, 1));
      (rlen == -1) ? (buff[0] = '\n') : (buff[rlen] = '\0');
      rlen = (rlen == -1) ? (1) : (rlen);
      buff[rlen] = '\0';
      if ((stack = my_fill_stack(stack, buff)) == NULL)
	return (NULL);
    }
  result = my_put_result(stack);
  return (result);
}
