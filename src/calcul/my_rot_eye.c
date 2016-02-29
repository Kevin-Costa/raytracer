/*
** my_rot_eye.c for rt in /home/rousse_3/rendu/MUL_rt/pokeball_the_origin
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Tue Mar 25 23:28:37 2014 rousse_3
** Last update Tue Mar 25 23:41:50 2014 rousse_3
*/

#include	<stdlib.h>
#include	"struct.h"
#include	"my_math.h"

void		my_rot_eye(t_eye *eye, double angle_x, double angle_y, double angle_z)
{
  my_rot_vector(eye->v_vision, angle_x, angle_y, angle_z);
  my_rot_point(eye->center, angle_x, angle_y, angle_z);
}

void		my_irot_eye(t_eye *eye, double angle_x, double angle_y, double angle_z)
{
  my_irot_vector(eye->v_vision, -angle_x, -angle_y, -angle_z);
  my_irot_point(eye->center, -angle_x, -angle_y, -angle_z);
}
