/*
** struct.h for rt in /home/rousse_3/rendu/MUL_rt/pokeball_the_origin
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Tue Mar 18 20:47:42 2014 rousse_3
** Last update Thu Mar 20 13:12:33 2014 rousse_3
*/

#ifndef		STRUC_H_
# define	STRUC_H_

typedef struct	s_win
{
  void		*ptr;
  int		size_x;
  int		size_y;
  char		*name;
}		t_win;

typedef struct	s_pic
{
  void		*ptr;
  int		size_x;
  int		size_y;
  int		bpp;
  int		size_line;
  int		endian;
  char		*data;
}		t_pic;

typedef struct	s_ptr
{
  void		*mlx;
  t_win		*win;
  t_pic		*pic;
}		t_ptr;

typedef struct	s_col
{
  double	red;
  double	green;
  double	blue;
}		t_col;

typedef struct	s_pt
{
  double	x;
  double	y;
  double	z;
}		t_pt;

typedef struct	s_vec
{
  double	x;
  double	y;
  double	z;
}		t_vec;

typedef struct	s_eye
{
  t_pt		*center;
  t_vec		*v_vision;
}		t_eye;

typedef struct	s_list
{
  struct s_list	*prev;
  int		flag;
  t_pt		*center;
  double	*carac;
  t_col		*color;
  double	angle_x;
  double	angle_y;
  double	angle_z;
  struct s_list	*next;
}		t_list;

typedef struct s_lig
{
  struct s_lig	*prev;
  t_pt		*pt;
  t_col		*color;
  struct s_lig	*next;
}		t_lig;

typedef struct	s_sc
{
  t_list	*obj;
  t_lig		*light;
  t_eye		*eye;
}		t_sc;

#endif
