/*
** init.h for rt in /home/rousse_3/rendu/MUL_rt/pokeball_the_origin
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Tue Mar 18 21:05:23 2014 rousse_3
** Last update Thu Mar 20 16:54:51 2014 rousse_3
*/

#ifndef		INIT_H_
# define	INIT_H_

void		my_free_ptr(t_ptr *ptr);
void		my_free_pic(t_pic *pic);
void		my_free_win(t_win *win, void *mlx_ptr);
t_col		*my_init_color(double red, double green , double blue);
void		my_set_color(t_col *color, double red, double green, double blue);
t_ptr		*my_init(void);
t_eye		*my_init_eye(double x, double y, double z, char *error);
t_eye		*my_set_vision(t_eye *eye, double x, double y, double z);
void		my_free_eye(t_eye *eye);
t_sc		*my_init_scene(void);

#endif
