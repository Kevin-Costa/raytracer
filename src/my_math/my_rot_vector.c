/*
** my_rot_vector.c for rt in /home/rousse_3/rendu/MUL_rt/pokeball_the_origin
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Wed Mar 19 12:57:25 2014 rousse_3
** Last update Wed Mar 19 13:14:10 2014 rousse_3
*/

#include	<stdlib.h>
#include	<math.h>
#include	"struct.h"
#include	"my_math.h"

void		my_rot_vector(t_vec *vec, double ang_x, double ang_y,
			      double ang_z)
{
  double	tmp;
  double	costmp;
  double	sintmp;

  if (vec != NULL)
    {
      costmp = cos(ang_z);
      sintmp = sin(ang_z);
      tmp = vec->x * costmp - vec->y * sintmp;
      vec->y = vec->x * sintmp + vec->y * costmp;
      vec->x = tmp;
      costmp = cos(ang_y);
      sintmp = sin(ang_y);
      tmp = vec->z * costmp - vec->x * sintmp;
      vec->x = vec->z * sintmp + vec->x * costmp;
      vec->z = tmp;
      costmp = cos(ang_x);
      sintmp = sin(ang_x);
      tmp = vec->y * costmp - vec->z * sintmp;
      vec->z = vec->y * sintmp + vec->z * costmp;
      vec->y = tmp;
    }
}

void		my_irot_vector(t_vec *vec, double ang_x, double ang_y,
			      double ang_z)
{
  double	tmp;
  double	costmp;
  double	sintmp;
  if (vec != NULL)
    {
      costmp = cos(ang_x);
      sintmp = sin(ang_x);
      tmp = vec->y * costmp - vec->z * sintmp;
      vec->z = vec->y * sintmp + vec->z * costmp;
      vec->y = tmp;
      costmp = cos(ang_y);
      sintmp = sin(ang_y);
      tmp = vec->z * costmp - vec->x * sintmp;
      vec->x = vec->z * sintmp + vec->x * costmp;
      vec->z = tmp;
      costmp = cos(ang_z);
      sintmp = sin(ang_z);
      tmp = vec->x * costmp - vec->y * sintmp;
      vec->y = vec->x * sintmp + vec->y * costmp;
      vec->x = tmp;
    }
}
