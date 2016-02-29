/*
** my_translate_point.c for rt in /home/rousse_3/rendu/MUL_rt/pokeball_the_origin
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Thu Mar 20 21:36:11 2014 rousse_3
** Last update Fri Mar 21 17:52:29 2014 rousse_3
*/

#include	<stdlib.h>
#include	"struct.h"

void		my_translate_point(t_pt *point, double x, double y, double z)
{
  if (point != NULL)
    {
      point->x += x;
      point->y += y;
      point->z += z;
    }
}
