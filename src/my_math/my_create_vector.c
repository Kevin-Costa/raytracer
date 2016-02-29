/*
** my_create_vector.c for rt in /home/rousse_3/rendu/MUL_rt/pokeball_the_origin
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Tue Mar 18 23:50:25 2014 rousse_3
** Last update Tue Mar 18 23:52:29 2014 rousse_3
*/

#include	<stdlib.h>
#include	"struct.h"
#include	"macro.h"
#include	"lib.h"

t_vec		*my_create_vector(double x, double y, double z, char *error)
{
  t_vec		*vector;

  if ((vector = malloc(sizeof(t_pt))) == NULL)
    {
      my_putstr_error(error);
      my_putstr_error(MALLOC_FAIL);
      return (NULL);
    }
  vector->x = x;
  vector->y = y;
  vector->z = z;
  return (vector);
}

void		my_set_vector(t_vec *vector, double x, double y, double z)
{
  if (vector != NULL)
    {
      vector->x = x;
      vector->y = y;
      vector->z = z;
    }
}
