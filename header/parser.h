/*
** parser.h for  in /home/zwertv_e/rendu/MUL_rt/pokeball_the_origin/header
** 
** Made by Elliott ZWERTVAEGHER
** Login   <zwertv_e@epitech.net>
** 
** Started on  Wed May 28 16:30:27 2014 Elliott ZWERTVAEGHER
** Last update Wed May 28 16:58:15 2014 Elliott ZWERTVAEGHER
*/

#ifndef PARSER_H_
# define PARSER_H_

# define	MAGIC_FLAG "rt_00"
# define	LIGHT_NAME "light"
# define	EYE_NAME "eye"
# define	START_SEP '{'
# define	END_SEP '}'

typedef struct	s_op
{
  char		*name;
  int		flag;
  char		*carac_name;
}		t_op;

t_op		*my_create_op();

#endif /* !PARSER_H_ */
