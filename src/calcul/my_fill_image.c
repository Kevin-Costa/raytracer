/*
** my_fill_image.c for rt in /home/rousse_3/rendu/MUL_rt/pokeball_the_origin/src/calcul
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Thu Mar 20 15:23:16 2014 rousse_3
** Last update Sun Mar 23 18:59:11 2014 rousse_3
*/

#include	<stdlib.h>
#include	<math.h>
#include	"struct.h"
#include	"macro.h"
#include	"my_math.h"
#include	"calc.h"

static void	my_pixel_put_to_img(int x, int y, t_pic *img, t_col *color)
{
  int		nb;

  if (img != NULL && color != NULL)
    {
      nb = x * img->bpp / 8 + y * img->size_line;
      img->data[nb] = color->blue;
      img->data[nb + 1] = color->green;
      img->data[nb + 2] = color->red;
      img->data[nb + 3] = 0;
    }
}

int		my_fill_image(t_pic *img, t_col *color, t_sc *scene)
{
  int		y;
  int		x;

  if (img == NULL || color == NULL || scene == NULL)
    return (0);
  y = 0;
  while (y < img->size_x)
    {
      x = 0;
      while (x < img->size_y)
	{
	  my_set_vector(scene->eye->v_vision,
			img->size_y / 2 - x, img->size_x / 2 - y,
			img->size_x / 2 / tan (25 * PI / 180));
	  my_get_pixel(color, scene, scene->obj);
	  my_pixel_put_to_img(x, y, img, color);
	  x++;
	}
      y++;
    }
  free(color);
  return (0);
}
