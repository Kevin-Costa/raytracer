/*
** get_next_line.c for minishell2 in /home/rousse_3/rendu/PSU_2013_minishell2/src
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Thu Mar  6 15:55:39 2014 rousse_3
** Last update Fri May 30 13:16:37 2014 rousse_3
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"lib.h"

static t_str	*add_in_list(t_str *my_list, char c)
{
  t_str		*new_element;
  t_str		*tmp;

  if ((new_element = malloc(sizeof(t_str))) == NULL)
    return (NULL);
  new_element->c = c;
  new_element->next = NULL;
  if (my_list == NULL)
    return (new_element);
  tmp = my_list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new_element;
  return (my_list);
}

static int	check_list(t_str *my_list)
{
  t_str		*tmp;

  tmp = my_list;
  while (tmp != NULL)
    {
      if (tmp->c == '\n' || tmp->c == '\0')
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

static int	str_size(t_str *my_list)
{
  t_str		*tmp;
  int		i;

  tmp = my_list;
  i = 0;
  while (tmp != NULL)
    {
      if (tmp->c == '\n' || tmp->c == '\0')
	return (i);
      tmp = tmp->next;
      i++;
    }
  return (i);
}

static char	*list_to_str(t_str **my_list)
{
  t_str		*tmp;
  char		*str;
  int		i;

  i = 0;
  if ((*my_list) == NULL)
    return (NULL);
  if ((str = malloc(sizeof(char) * (str_size(*my_list) + 1))) == NULL)
    return (NULL);
  while ((*my_list) != NULL && (*my_list)->c != '\n' && (*my_list)->c != '\0')
    {
      tmp = (*my_list);
      str[i++] = (*my_list)->c;
      (*my_list) = (*my_list)->next;
      free(tmp);
    }
  str[i] = '\0';
  if ((*my_list) != NULL)
    {
      tmp = (*my_list);
      (*my_list) = (*my_list)->next;
      free(tmp);
    }
  return (str);
}

char		*get_next_line(int fd)
{
  static t_str	*my_list;
  char		buffer[BUFF_SIZE];
  int		val;
  int		i;

  i = 0;
  while (i < BUFF_SIZE)
    buffer[i++] = 0;
  if ((val = read(fd, buffer, BUFF_SIZE)) < 0)
    return (NULL);
  if (val == 0)
    return (list_to_str(&my_list));
  i = 0;
  while (i < val)
    my_list = add_in_list(my_list, buffer[i++]);
  if (check_list(my_list))
    return (list_to_str(&my_list));
  return (get_next_line(fd));
}
