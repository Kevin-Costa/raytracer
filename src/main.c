/*
** main.c for rt in /home/rousse_3/rendu/MUL_rt/pokeball_the_origin
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Tue Mar 18 20:34:16 2014 rousse_3
** Last update Wed May 28 17:11:33 2014 Elliott ZWERTVAEGHER
*/

#include	<stdlib.h>
#include	"mlx.h"
#include	"struct.h"
#include	"macro.h"
#include	"lib.h"
#include	"init.h"
#include	"calc.h"

int		my_expose(t_ptr *ptr)
{
  mlx_put_image_to_window(ptr->mlx, ptr->win->ptr, ptr->pic->ptr, 0, 0);
  return (0);
}

int		my_key(int key, t_ptr *ptr)
{
  if (key == EXIT_KEY)
    {
      my_free_ptr(ptr);
      exit(1);
    }
  return (0);
}

int		main(int ac, char **av)
{
  t_ptr		*ptr;
  t_col		*color;
  t_sc		*scene;

  if (ac > 1)
    my_parse(av[1]);
  (void)av;
  if (ac != 1)
    my_putstr_error(ARG_ERROR);
  if ((ptr = my_init()) == NULL)
    {
      my_putstr_error(INIT_ERROR);
      return (EXIT_ERROR);
    }
  if ((color = my_init_color(0, 0, 0)) == NULL)
    {
      my_putstr_error(INIT_ERROR);
      return (EXIT_ERROR);
    }
  if ((scene = my_init_scene()) == NULL)
    return (EXIT_ERROR);
  my_fill_image(ptr->pic, color, scene);
  mlx_expose_hook(ptr->win->ptr, &my_expose, ptr);
  mlx_key_hook(ptr->win->ptr, &my_key, ptr);
  mlx_loop(ptr->mlx);
  return (SUCCESS);
}
