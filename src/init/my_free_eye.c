/*
** my_free_eye.c for rt in /home/rousse_3/rendu/MUL_rt/pokeball_the_origin
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Wed Mar 19 13:27:55 2014 rousse_3
** Last update Wed Mar 19 13:28:40 2014 rousse_3
*/

#include	<stdlib.h>
#include	"struct.h"

void		my_free_eye(t_eye *eye)
{
  free(eye->center);
  free(eye->v_vision);
  free(eye);
}
