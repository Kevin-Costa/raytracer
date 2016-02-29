/*
** my_lumo.c for rt in /home/rousse_3/rendu/MUL_rt/pokeball_the_origin
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Sun Mar 23 18:42:02 2014 rousse_3
** Last update Tue Mar 25 23:42:22 2014 rousse_3
*/

#include	<stdlib.h>
#include	"struct.h"
#include	"macro.h"
#include	"init.h"
#include	"my_math.h"
#include	"calc.h"

static t_vec	*my_get_sphere_normal(const t_eye *eye, const t_list *obj)
{
  t_vec		*normal;

  if (eye == NULL)
    return (NULL);
  if ((normal = my_create_vector(eye->center->x,
				 eye->center->y, eye->center->z,
				 "My_get_sphere_normal : my_init_vector "))
      == NULL)
    return (NULL);
  my_rot_vector(normal, obj->angle_x, obj->angle_y, obj->angle_z);
  my_normalize(normal);
  return (normal);
}

static t_vec	*my_get_cylindre_normal(const t_eye *eye, const t_list *obj)
{
  t_vec		*normal;

  if (eye == NULL)
    return (NULL);
  if ((normal = my_create_vector(eye->center->x,
				 0 , eye->center->z,
				 "My_get_sphere_normal : my_init_vector "))
      == NULL)
    return (NULL);
  my_rot_vector(normal, obj->angle_x, obj->angle_y, obj->angle_z);
  my_normalize(normal);
  return (normal);
}

static t_vec	*my_get_plan_normal(const t_eye *eye, const t_list *obj)
{
  t_vec		*normal;

  if (eye == NULL)
    return (NULL);
  if ((normal = my_create_vector(0, 1, 0,
				 "My_get_plan_normal : my_init_vector "))
      == NULL)
    return (NULL);
  my_rot_vector(normal, obj->angle_x, obj->angle_y, obj->angle_z);
  my_normalize(normal);
  return (normal);
}

t_eye		*my_init_lum_eye(const t_eye *eye, const double k,
				 const t_pt *spot)
{
  t_eye		*new_eye;

  if ((new_eye = my_init_eye(eye->center->x + k * eye->v_vision->x,
			     eye->center->y + k * eye->v_vision->y,
			     eye->center->z + k * eye->v_vision->z,
			     "my_init_lum_eye : my_init_eye :")) == NULL)
    return (NULL);
  my_set_vision(new_eye, spot->x - new_eye->center->x,
		spot->y - new_eye->center->y, spot->z - new_eye->center->z);
  my_normalize(new_eye->v_vision);
  return (new_eye);
}

double		my_calc_cos(const t_list *obj, t_eye *old_eye,
			    const double k, const t_pt *spot)
{
  t_vec		*(*ptr[3])(const t_eye*, const t_list *obj);
  t_vec		*normal;
  double	my_cos;
  t_eye		*eye;

  ptr[SPHERE] = &my_get_sphere_normal;
  ptr[PLAN] = &my_get_plan_normal;
  ptr[CYLINDER] = &my_get_cylindre_normal;
  my_translate_point(old_eye->center, -obj->center->x,
		     -obj->center->y, -obj->center->z);
  my_rot_eye(old_eye, obj->angle_x, obj->angle_y, obj->angle_z);
  eye = my_init_lum_eye(old_eye, k, spot);
  normal = ptr[obj->flag](eye, obj);
  my_cos = my_scalaire(normal, eye->v_vision);
  my_irot_eye(old_eye, obj->angle_x, obj->angle_y, obj->angle_z);
  my_translate_point(old_eye->center, obj->center->x,
		     obj->center->y, obj->center->z);
  if (my_cos < 0.1)
    my_cos = 0.1;
  if (my_cos > 1)
    my_cos = 1;
  return (my_cos);
}

