/*
** my_free.c for rt in /home/rousse_3/rendu/MUL_rt/pokeball_the_origin
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Tue Mar 18 20:57:01 2014 rousse_3
** Last update Tue Mar 18 21:26:58 2014 rousse_3
*/

#include	<stdlib.h>
#include	"mlx.h"
#include	"struct.h"
#include	"init.h"

void		my_free_win(t_win *win, void *mlx_ptr)
{

  mlx_destroy_window(mlx_ptr, win->ptr);
  free(win->name);
  free(win);
}

void		my_free_pic(t_pic *pic)
{
  free(pic->ptr);
  free(pic);
}

void		my_free_ptr(t_ptr *ptr)
{
  my_free_win(ptr->win, ptr->mlx);
  my_free_pic(ptr->pic);
  free(ptr->mlx);
  free(ptr);
}
