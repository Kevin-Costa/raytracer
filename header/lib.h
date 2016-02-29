/*
** lib.h for minishell2 in /home/rousse_3/rendu/PSU_2013_minishell2/src
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Thu Mar  6 16:02:18 2014 rousse_3
** Last update Thu Mar  6 16:09:04 2014 rousse_3
*/

#ifndef		LIB_H_
# define	LIB_H_

# define	BUFF_SIZE	10

typedef struct	s_str
{
  char		c;
  struct s_str	*next;
}		t_str;

void		my_putchar(char c);
void		my_putchar_error(char c);
int		my_putstr(char *str);
int		my_putstr_error(char *str);
void		my_putnbr(int nbr);
int		my_strlen(char *str);
int		my_get_nbr(char *str);
int		my_get_nbr_base(char *str, char *base);
char		*my_strcat(char *str, char *str_bis);
int		my_str_cmp(char *str, char *str_bis);
int		my_str_begin_cmp(char *str, char *str_bis);
char		*my_str_cpy(char *str);
void		*xmalloc(int size, int flag);
char		*get_next_line(int fd);

#endif
