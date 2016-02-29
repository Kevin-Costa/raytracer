/*
** calc.h for rt in /home/rousse_3/rendu/MUL_rt/pokeball_the_origin
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Thu Mar 20 16:53:23 2014 rousse_3
** Last update Tue Mar 25 23:31:20 2014 rousse_3
*/

#ifndef		CALCUL_H_
# define	CALCUL_H_

int		my_fill_image(t_pic *img, t_col *color, t_sc *scene);
double		calc_sphere(const t_list *obj, t_eye *eye);
double		calc_plan(const t_list *obj, t_eye *eye);
double		calc_cylindre(const t_list *obj, t_eye *eye);
int     	my_get_pixel(t_col *color, t_sc *scene, t_list *obj);
t_eye		*my_init_lum_eye(const t_eye *eye, const double k,
				 const t_pt *spot);
double		my_calc_cos(const t_list *obj, t_eye *old_eye, const double k,
			    const t_pt *spot);
int		my_check_ombre(const t_pt *spot, t_list *obj,
			       const t_list *tmp, t_eye *eye);
void		my_rot_eye(t_eye *eye, double angle_x, double angle_y, double angle_z);
void		my_irot_eye(t_eye *eye, double angle_x, double angle_y, double angle_z);

#endif
