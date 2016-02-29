/*
** my_parse.c for  in /home/zwertv_e/rendu/MUL_rt/pokeball_the_origin/parser
** 
** Made by Elliott ZWERTVAEGHER
** Login   <zwertv_e@epitech.net>
** 
** Started on  Wed May 28 15:16:03 2014 Elliott ZWERTVAEGHER
** Last update Fri May 30 13:19:58 2014 Elliott ZWERTVAEGHER
*/

#include	<stdio.h> // TEMP
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"parser.h"
#include	"struct.h"
#include	"lib.h"

int		my_check_magic(int fd)
{
  char		*line;

  line = get_next_line2(fd);
  if (line == NULL)
    return (1);
  while (line != NULL && (my_str_cmp(line, "\0") || strncmp(line, "//", 2) == 0))
    {
      printf("line: %s-\n", line);
      if (strncmp(line, "//", 2) == 0)
	printf("Commentaire ignoré: \"%s\"\n", line);
      free(line);
      line = get_next_line2(fd);
    }
  printf("line: %s--\n", line);
  if (line == NULL)
    return (1);
  if (!my_str_cmp(line, MAGIC_FLAG))
    {
      free(line);
      return (1);
    }
  if (line != NULL)
    free(line);
  return (0);
}

t_sc		*my_parse(char *path)
{
  t_sc		*result;
  t_op		*op_tab;
  int		fd;

  printf("Loading...\n");
  if ((op_tab = my_create_op()) == NULL)
    return (NULL);
  printf("OP_TAB loaded !\n");
  printf("Object list :\n");
  int i = 0;
  while (op_tab[i].name != NULL)
    {
      printf("-> %s\n", op_tab[i].name);
      i++;
    }
  if ((fd = open(path, O_RDONLY)) == -1)
    return (NULL);
  printf("File \"%s\" loaded !\n", path);
  if (my_check_magic(fd) != 0)
    return (NULL);
  printf("Magic is OK !\n");
  /*result = my_load_objects(fd, op_tab);*/
  printf("File LOADED :DDDD\n");
  return (NULL);
}
