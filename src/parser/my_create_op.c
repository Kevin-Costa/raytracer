/*
** my_create_op.c for  in /home/zwertv_e/rendu/MUL_rt/pokeball_the_origin/parser
** 
** Made by Elliott ZWERTVAEGHER
** Login   <zwertv_e@epitech.net>
** 
** Started on  Wed May 28 16:36:34 2014 Elliott ZWERTVAEGHER
** Last update Wed May 28 17:22:18 2014 Elliott ZWERTVAEGHER
*/

#include	<stdlib.h>
#include	"macro.h"
#include	"parser.h"
#include	"struct.h"

t_op		*my_create_op()
{
  t_op		*res;

  if ((res = malloc(sizeof(t_op) * 4)) == NULL)
    return (NULL);
  res[0].name = "sphere";
  res[0].flag = SPHERE;
  res[0].carac_name = "rayon";
  res[1].name = "plan";
  res[1].flag = PLAN;
  res[1].carac_name = "";
  res[2].name = "cylindre";
  res[2].flag = CYLINDER;
  res[2].carac_name = "rayon";
  res[3].name = NULL;
  return (res);
}
