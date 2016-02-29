/*
** normal.c for rt in /home/rousse_3/rendu/MUL_rt/pokeball_the_origin
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Sun Mar 23 18:32:33 2014 rousse_3
** Last update Tue Mar 25 23:19:05 2014 rousse_3
*/

#include	<stdlib.h>
#include	<math.h>
#include	"struct.h"
#include	"macro.h"
#include	"init.h"
#include	"my_math.h"
#include	"calc.h"

static void	my_apply_color(t_col *color, const double my_cos,
			       const t_list *obj)
{
  color->red += obj->color->red * my_cos;
  color->green += obj->color->blue * my_cos;
  color->blue += obj->color->blue * my_cos;
}

static int	my_get_color(t_col *color, t_list *tmp,
			     const t_sc *scene, const double k)
{
  t_lig		*light;
  t_eye		*new_eye;
  double	my_cos;
  t_col		*color_tmp;
  int		n;

  if (color == NULL || tmp == NULL || scene == NULL)
    return (-1);
  light = scene->light;
  new_eye = my_init_lum_eye(scene->eye, k, light->pt);
  color_tmp = my_init_color(0, 0, 0);
  n = 0;
  while (light != NULL && ++n)
    {
      if (my_check_ombre(light->pt, scene->obj, tmp, new_eye) == -1)
      	my_cos = 0.1;
      else
	  my_cos = my_calc_cos(tmp, scene->eye, k, light->pt);
      my_apply_color(color_tmp, my_cos, tmp);
      light = light->next;
    }
  my_set_color(color, color_tmp->red / n, color_tmp->green / n,
	       color_tmp->blue / n);
  return (0);
}

int     	my_get_pixel(t_col *color, t_sc *scene, t_list *obj)
{
  t_list	*tmp;
  double	(*ptr[3])(const t_list*, t_eye*);
  double	k;
  double	k_tmp;

  if (color == NULL || scene == NULL || obj == NULL)
    return (1);
  ptr[SPHERE] = &calc_sphere;
  ptr[PLAN] = &calc_plan;
  ptr[CYLINDER] = &calc_cylindre;
  k = -1;
  tmp = NULL;
  while (obj != NULL)
    {
      k_tmp = ptr[obj->flag](obj, scene->eye);
      if ((k_tmp > 0 && k_tmp < k && k > 0) || k < 0)
	{
	  k = k_tmp;
	  tmp = obj;
	}
      obj = obj->next;
    }
  if (k < 0)
    my_set_color(color, 125, 125, 125);
  else
    /* my_set_color(color, tmp->color->red, tmp->color->green, tmp->color->blue); */
    my_get_color(color, tmp, scene, k);
  return (0);
}
