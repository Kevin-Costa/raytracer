/*
** my_init_eye.c for rt in /home/rousse_3/rendu/MUL_rt/pokeball_the_origin
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Wed Mar 19 13:17:01 2014 rousse_3
** Last update Wed Mar 19 13:26:49 2014 rousse_3
*/

#include	<stdlib.h>
#include	"struct.h"
#include	"macro.h"
#include	"my_math.h"
#include	"lib.h"

t_eye		*my_init_eye(double x, double y, double z, char *error)
{
  t_eye		*eye;
  char		*tmp;

  if ((eye = malloc(sizeof(t_eye))) == NULL)
    {
      my_putstr_error(error);
      my_putstr_error(MALLOC_FAIL);
      return (NULL);
    }
  tmp = my_strcat(error, "init_point ");
  if ((eye->center = my_create_point(x, y, z, tmp)) == NULL)
    {
      free(tmp);
      return (NULL);
    }
  free(tmp);
  return (eye);
}

t_eye		*my_set_vision(t_eye *eye, double x, double y, double z)
{
  if (eye == NULL)
    return (NULL);
  if ((eye->v_vision = my_create_vector(x, y, z, "my_set_vision ")) == NULL)
    return (NULL);
  return (eye);
}
