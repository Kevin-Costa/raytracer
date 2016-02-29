/*
** my_ombre.c for rt in /home/rousse_3/rendu/MUL_rt/pokeball_the_origin
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Sun Mar 23 19:00:03 2014 rousse_3
** Last update Tue Mar 25 23:16:36 2014 rousse_3
*/

#include	<stdlib.h>
#include	"struct.h"
#include	"macro.h"
#include	"init.h"
#include	"calc.h"

int		my_check_ombre(const t_pt *spot, t_list *obj, const t_list *tmp,
			       t_eye *eye)
{
  double	(*ptr[3])(const t_list*, t_eye*);
  double	k;

  my_set_vision(eye, spot->x - eye->center->x, spot->y - eye->center->y,
		spot->z - eye->center->z);
  ptr[SPHERE] = &calc_sphere;
  ptr[PLAN] = &calc_plan;
  ptr[CYLINDER] = &calc_cylindre;
  while (obj != NULL)
    {
      if (obj != tmp)
  	{
  	  k = ptr[obj->flag](obj, eye);
  	  if (k > 0 && k <= 1)
  	    return (-1);
  	}
      obj = obj->next;
    }
  return (0);
}
