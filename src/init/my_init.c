/*
** my_init.c for rtv1 in /home/rousse_3/rendu/MUL_2013_rtv1
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Thu Mar 13 18:29:19 2014 rousse_3
** Last update Fri Mar 21 17:53:00 2014 rousse_3
*/

#include	<stdlib.h>
#include	"mlx.h"
#include	"lib.h"
#include	"struct.h"
#include	"macro.h"
#include	"init.h"

static t_win	*my_init_window(char *name, void *mlx_ptr, int x, int y)
{
  t_win		*win;

  if ((win = malloc(sizeof(t_win))) == NULL)
    return (NULL);
  if ((win->ptr = mlx_new_window(mlx_ptr, x, y, name)) == NULL)
    {
      free(win);
      return (NULL);
    }
  win->size_x = x;
  win->size_y = y;
  win->name = my_str_cpy(name);
  return (win);
}

static t_pic	*my_init_picture(void *mlx_ptr, int x, int y)
{
  t_pic		*pic;

  if ((pic = malloc(sizeof(t_pic))) == NULL)
    return (NULL);
  if ((pic->ptr = mlx_new_image(mlx_ptr, x, y)) == NULL)
    {
      free(pic);
      return (NULL);
    }
  pic->size_x = x;
  pic->size_y = y;
  pic->data = mlx_get_data_addr(pic->ptr, &(pic->bpp),
				&(pic->size_line), &(pic->endian));
  if (pic->data == NULL)
    {
      free(pic->ptr);
      free(pic);
      return (NULL);
    }
  return (pic);
}

t_ptr		*my_init(void)
{
  t_ptr		*ptr;

  if ((ptr = malloc(sizeof(t_ptr))) == NULL)
    return (NULL);
  if ((ptr->mlx = mlx_init()) == NULL)
    {
      free(ptr);
      return (NULL);
    }
  if ((ptr->win = my_init_window(W_NAME, ptr->mlx, W_SIZE_X,
				 W_SIZE_Y)) == NULL)
    {
      free(ptr->mlx);
      free(ptr);
      return (NULL);
    }
  if ((ptr->pic = my_init_picture(ptr->mlx, W_SIZE_X, W_SIZE_Y)) == NULL)
    {
      my_free_win(ptr->win, ptr->mlx);
      free(ptr->mlx);
      free(ptr);
      return (NULL);
    }
  return (ptr);
}
