/*
** my_init_color.c for rt in /home/rousse_3/rendu/MUL_rt/pokeball_the_origin
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Thu Mar 20 13:22:08 2014 rousse_3
** Last update Thu Mar 20 13:25:23 2014 rousse_3
*/

#include	<stdlib.h>
#include	"struct.h"

t_col		*my_init_color(double red, double green, double blue)
{
  t_col		*color;

  if ((color = malloc(sizeof(t_col))) == NULL)
    return (NULL);
  color->red = red;
  color->green = green;
  color->blue = blue;
  return (color);
}

void		my_set_color(t_col *color, double red, double green, double blue)
{
  if (color != NULL)
    {
      color->red = red;
      color->green = green;
      color->blue = blue;
    }
}
