/*
** my_normalize.c for rt in /home/rousse_3/rendu/MUL_rt/pokeball_the_origin
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Fri Mar 21 22:12:55 2014 rousse_3
** Last update Fri Mar 21 22:14:57 2014 rousse_3
*/

#include	<stdlib.h>
#include	"struct.h"
#include	"my_math.h"

void		my_normalize(t_vec *vec)
{
  double	norm;

  if (vec != NULL)
    {
      norm = my_norme(vec);
      vec->x /= norm;
      vec->y /= norm;
      vec->z /= norm;
    }
}
