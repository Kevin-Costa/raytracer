/*
** my_init_scene.c for rt in /home/rousse_3/rendu/MUL_rt/pokeball_the_origin
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Wed Mar 19 17:43:11 2014 rousse_3
** Last update Tue Mar 25 23:45:31 2014 rousse_3
*/

#include	<stdlib.h>
#include	"struct.h"
#include	"macro.h"
#include	"lib.h"
#include	"my_math.h"
#include	"init.h"

static void	my_set_angle(t_list *list, double angle_x,
			     double angle_y, double angle_z)
{
  if (list != NULL)
    {
      list->angle_x = angle_x;
      list->angle_y = angle_y;
      list->angle_z = angle_z;
    }
}

static t_list	*my_init_list(char *error)
{
  t_list	*list;

  /* SPHERE 1 */
  if ((list = malloc(sizeof(t_list))) == NULL)
    {
      my_putstr_error(error);
      my_putstr_error(MALLOC_FAIL);
      return (NULL);
    }
  if ((list->carac = malloc(sizeof(double) * 2)) == NULL)
    {
      my_putstr_error(error);
      my_putstr_error(MALLOC_FAIL);
      return (NULL);
    }
  list->prev = NULL;
  list->carac[0] = 1;
  list->carac[1] = 5;
  list->flag = SPHERE;
  if ((list->center = my_create_point(-5, 10, -10,
				      "my_init_list : center : ")) == NULL)
    return (NULL);
  list->color = my_init_color(125, 210, 90);
  my_set_angle(list, 0, 0, 0);
  /* SPHERE 2 */
  if ((list->next = malloc(sizeof(t_list))) == NULL)
    {
      my_putstr_error(error);
      my_putstr_error(MALLOC_FAIL);
      return (NULL);
    }
  list->next->prev = list;
  list = list->next;
  if ((list->carac = malloc(sizeof(double) * 2)) == NULL)
    {
      my_putstr_error(error);
      my_putstr_error(MALLOC_FAIL);
      return (NULL);
    }
  list->carac[0] = 1;
  list->carac[1] = 10;
  list->flag = SPHERE;
  if ((list->center = my_create_point(0, 5, 6,
  				      "my_init_list : center : ")) == NULL)
    return (NULL);
  list->color = my_init_color(47, 63, 238);
  my_set_angle(list, 0, 0, 0);
  /* PLAN */
  if ((list->next = malloc(sizeof(t_list))) == NULL)
    {
      my_putstr_error(error);
      my_putstr_error(MALLOC_FAIL);
      return (NULL);
    }
  list->next->prev = list;
  list = list->next;
  if ((list->carac = malloc(sizeof(double))) == NULL)
    {
      my_putstr_error(error);
      my_putstr_error(MALLOC_FAIL);
      return (NULL);
    }
  list->carac[0] = 0;
  list->flag = PLAN;
  if ((list->center = my_create_point(0, -6, 0,
  				      "my_init_list : center : ")) == NULL)
    return (NULL);
  list->color = my_init_color(255, 255, 122);
  my_set_angle(list, 0, 0, PI / 12);
  /* CYLINDRE */
  if ((list->next = malloc(sizeof(t_list))) == NULL)
    {
      my_putstr_error(error);
      my_putstr_error(MALLOC_FAIL);
      return (NULL);
    }
  list->next->prev = list;
  list = list->next;
  if ((list->carac = malloc(sizeof(double) * 2)) == NULL)
    {
      my_putstr_error(error);
      my_putstr_error(MALLOC_FAIL);
      return (NULL);
    }
  list->carac[0] = 1;
  list->carac[1] = 1;
  list->flag = CYLINDER;
  if ((list->center = my_create_point(24, 0, 10,
  				      "my_init_list : center : ")) == NULL)
    return (NULL);
  list->color = my_init_color(255, 255, 122);
  my_set_angle(list,  PI / 3, 0, 0);
  /* FIN */
  list->next = NULL;
  while (list->prev != NULL)
    list = list->prev;
  return (list);
}

static t_lig	*my_init_light(char *error)
{
  t_lig		*light;

  if ((light = malloc(sizeof(t_lig))) == NULL)
    {
      my_putstr_error(error);
      my_putstr_error(MALLOC_FAIL);
      return (NULL);
    }
  light->prev = NULL;
  if ((light->pt = my_create_point(-50, 50, -50,
				      "my_init_light : center : ")) == NULL)
    return (NULL);
  if ((light->color = my_init_color(255, 255, 255)) == NULL)
      return (NULL);
  if ((light->next = malloc(sizeof(t_lig))) == NULL)
    {
      my_putstr_error(error);
      my_putstr_error(MALLOC_FAIL);
      return (NULL);
    }
  light->next->prev = light;
  light = light->next;
  if ((light->pt = my_create_point(50, 50, -50,
				      "my_init_light : center : ")) == NULL)
    return (NULL);
  if ((light->color = my_init_color(255, 255, 255)) == NULL)
      return (NULL);
  light->next = NULL;
  while (light->prev != NULL)
    light = light->prev;
  return (light);
}

t_sc		*my_init_scene(void)
{
  t_sc		*scene;

  if ((scene = malloc(sizeof(t_sc))) == NULL)
    {
      my_putstr_error("My_init_scene : ");
      my_putstr_error(MALLOC_FAIL);
      return (NULL);
    }
  if ((scene->eye = my_init_eye(X_EYE, Y_EYE, Z_EYE, "My_init_scene : eye : ")) == NULL)
    return (NULL);
  if (my_set_vision(scene->eye, 0, 0, 0) == NULL)
    {
      my_putstr_error("My_init_scene v_vison : ");
      my_putstr_error(MALLOC_FAIL);
      return (NULL);
    }
  if ((scene->obj = my_init_list("My_init_scene : list : ")) == NULL)
    return (NULL);
  if ((scene->light = my_init_light("My_init_scene : light : ")) == NULL)
    return (NULL);
  return (scene);
}
