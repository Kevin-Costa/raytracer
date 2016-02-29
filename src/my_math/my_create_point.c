/*
** my_create_point.c for rt in /home/rousse_3/rendu/MUL_rt/pokeball_the_origin
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Tue Mar 18 23:43:54 2014 rousse_3
** Last update Tue Mar 18 23:53:11 2014 rousse_3
*/

#include	<stdlib.h>
#include	"struct.h"
#include	"macro.h"
#include	"lib.h"

t_pt		*my_create_point(double x, double y, double z, char *error)
{
  t_pt		*point;

  if ((point = malloc(sizeof(t_pt))) == NULL)
    {
      my_putstr_error(error);
      my_putstr_error(MALLOC_FAIL);
      return (NULL);
    }
  point->x = x;
  point->y = y;
  point->z = z;
  return (point);
}

void		my_set_point(t_pt *point, double x, double y, double z)
{
  if (point != NULL)
    {
      point->x = x;
      point->y = y;
      point->z = z;
    }
}
