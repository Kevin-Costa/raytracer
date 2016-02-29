/*
** my_figure.c for rt in /home/rousse_3/rendu/MUL_rt/pokeball_the_origin
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Sun Mar 23 18:23:38 2014 rousse_3
** Last update Tue Mar 25 23:33:26 2014 rousse_3
*/

#include	<stdlib.h>
#include	<math.h>
#include	"struct.h"
#include	"my_math.h"
#include	"calc.h"

static void	my_get_sol(const double delta, const double b,
			   const double a, double sol[2])
{
  double	s;
  double	k_1;
  double	k_2;

  s = sqrt(delta);
  k_1 = (- b + s) / (2 * a);
  k_2 = (- b - s) / (2 * a);
  if (k_1 < 0 || (k_2 > 0 && k_2 < k_1))
    {
      sol[0] = k_2;
      sol[1] = k_1;
    }
  else
    {
      sol[0] = k_1;
      sol[1] = k_2;
    }
}

double		calc_sphere(const t_list *obj, t_eye *eye)
{
  double	a;
  double	b;
  double	c;
  double	sol[2];

  if (obj == NULL || eye == NULL)
    return (-1);
  my_translate_point(eye->center, -obj->center->x, -obj->center->y,
		     -obj->center->z);
  my_rot_eye(eye, obj->angle_x, obj->angle_y, obj->angle_z);
  a = pow(eye->v_vision->x, 2) + pow(eye->v_vision->y, 2)
    + pow(eye->v_vision->z, 2);
  b= 2 * (eye->v_vision->x * eye->center->x + eye->v_vision->y *
	  eye->center->y + eye->v_vision->z * eye->center->z);
  c = pow(eye->center->x, 2) + pow(eye->center->y, 2)
    + pow(eye->center->z, 2) - pow(obj->carac[1], 2);
  my_irot_eye(eye, obj->angle_x, obj->angle_y, obj->angle_z);
  my_translate_point(eye->center, obj->center->x, obj->center->y,
		     obj->center->z);
  if (b * b - 4 * a * c >= 0)
    {
      my_get_sol(b * b - 4 * a * c, b, a, sol);
      return (sol[0]);
    }
  return (-1);
}

double		calc_cylindre(const t_list *obj, t_eye *eye)
{
  double	a;
  double	b;
  double	c;
  double	sol[2];

  if (obj == NULL || eye == NULL)
    return (-1);
  my_translate_point(eye->center, -obj->center->x, -obj->center->y,
		     -obj->center->z);
  my_rot_eye(eye, obj->angle_x, obj->angle_y, obj->angle_z);
  a = pow(eye->v_vision->x, 2) + pow(eye->v_vision->z, 2);
  b= 2 * (eye->v_vision->x * eye->center->x + eye->v_vision->z * eye->center->z);
  c = pow(eye->center->x, 2) + pow(eye->center->z, 2) - pow(obj->carac[1], 2);
  my_irot_eye(eye, obj->angle_x, obj->angle_y, obj->angle_z);
  my_translate_point(eye->center, obj->center->x, obj->center->y,
		     obj->center->z);
  if (b * b - 4 * a * c >= 0)
    {
      my_get_sol(b * b - 4 * a * c, b, a, sol);
      return (sol[0]);
    }
  return (-1);
}

double		calc_plan(const t_list *obj, t_eye *eye)
{
  double	sol;

 if (obj == NULL || eye == NULL)
    return (-1);
  my_translate_point(eye->center, -obj->center->x, -obj->center->y,
		     -obj->center->z);
  my_rot_eye(eye, obj->angle_x, obj->angle_y, obj->angle_z);
  if (eye->v_vision->y < 0.00001 && eye->v_vision->y > -0.00001 && eye->center->y != 0)
    sol = -1;
  else if (eye->v_vision->y < 0.00001 && eye->v_vision->y > -0.00001)
    sol = 0,00001;
  else
    sol = - eye->center->y / eye->v_vision->y;
  my_irot_eye(eye, obj->angle_x, obj->angle_y, obj->angle_z);
  my_translate_point(eye->center, obj->center->x, obj->center->y,
		     obj->center->z);
  return (sol);
}
