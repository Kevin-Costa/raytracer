/*
** my_rot_point.c for rt in /home/rousse_3/rendu/MUL_rt/pokeball_the_origin
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Wed Mar 19 13:08:22 2014 rousse_3
** Last update Wed Mar 19 13:14:08 2014 rousse_3
*/

#include	<stdlib.h>
#include	<math.h>
#include	"struct.h"
#include	"my_math.h"

void		my_rot_point(t_pt *point, double ang_x, double ang_y,
			      double ang_z)
{
  double	tmp;
  double	costmp;
  double	sintmp;

  if (point != NULL)
    {
      costmp = cos(ang_z);
      sintmp = sin(ang_z);
      tmp = point->x * costmp - point->y * sintmp;
      point->y = point->x * sintmp + point->y * costmp;
      point->x = tmp;
      costmp = cos(ang_y);
      sintmp = sin(ang_y);
      tmp = point->z * costmp - point->x * sintmp;
      point->x = point->z * sintmp + point->x * costmp;
      point->z = tmp;
      costmp = cos(ang_x);
      sintmp = sin(ang_x);
      tmp = point->y * costmp - point->z * sintmp;
      point->z = point->y * sintmp + point->z * costmp;
      point->y = tmp;
    }
}

void		my_irot_point(t_pt *point, double ang_x, double ang_y,
			      double ang_z)
{
  double	tmp;
  double	costmp;
  double	sintmp;

  if (point != NULL)
    {
      costmp = cos(ang_x);
      sintmp = sin(ang_x);
      tmp = point->y * costmp - point->z * sintmp;
      point->z = point->y * sintmp + point->z * costmp;
      point->y = tmp;
      costmp = cos(ang_y);
      sintmp = sin(ang_y);
      tmp = point->z * costmp - point->x * sintmp;
      point->x = point->z * sintmp + point->x * costmp;
      point->z = tmp;
      costmp = cos(ang_z);
      sintmp = sin(ang_z);
      tmp = point->x * costmp - point->y * sintmp;
      point->y = point->x * sintmp + point->y * costmp;
      point->x = tmp;
    }
}
