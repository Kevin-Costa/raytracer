/*
** my_op_vector.c for rt in /home/rousse_3/rendu/MUL_rt/pokeball_the_origin
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Tue Mar 18 23:53:48 2014 rousse_3
** Last update Wed Mar 19 00:00:34 2014 rousse_3
*/

#include	<stdlib.h>
#include	<math.h>
#include	"struct.h"
#include	"my_math.h"

double		my_scalaire(t_vec *u, t_vec *v)
{
  if (u == NULL || v == NULL)
    return (0);
  return (u->x * v->x + u->y * v->y + u->z * v->z);
}

double		my_norme(t_vec *u)
{
  if (u == NULL)
    return (0);
  return (sqrt(my_scalaire(u, u)));
}

t_vec		*my_produit_vectoriel(t_vec *u, t_vec *v, char *error)
{
  double	x;
  double	y;
  double	z;

  x = u->y * v->z - v->y * u->z;
  y = v->x * u->z - u->x * v->z;
  z = u->x * v->y - v->x * u->y;
  return (my_create_vector(x, y, z, error));
}
