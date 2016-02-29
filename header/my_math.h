/*
** my_math.h for rt in /home/rousse_3/rendu/MUL_rt/pokeball_the_origin
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Tue Mar 18 23:43:51 2014 rousse_3
** Last update Fri Mar 21 22:14:55 2014 rousse_3
*/

#ifndef		MY_MATH_H_
# define	MY_MATH_H_

t_pt		*my_create_point(double x, double y, double z, char *error);
t_vec		*my_create_vector(double x, double y, double z, char *error);
void		my_set_point(t_pt *point, double x, double y, double z);
void		my_set_vector(t_vec *vector, double x, double y, double z);
double		my_scalaire(t_vec *u, t_vec *v);
double		my_norme(t_vec *u);
t_vec		*my_produit_vectoriel(t_vec *u, t_vec *v, char *error);
void		my_rot_vector(t_vec *vec, double ang_x, double ang_y,
			      double ang_z);
void		my_irot_vector(t_vec *vec, double ang_x, double ang_y,
			       double ang_z);
void		my_rot_point(t_pt *point, double ang_x, double ang_y,
			      double ang_z);
void		my_irot_point(t_pt *point, double ang_x, double ang_y,
			       double ang_z);
void		my_translate_point(t_pt *point, double x, double y, double z);
void		my_normalize(t_vec *vec);

# define	PI 3.14159265359

#endif
