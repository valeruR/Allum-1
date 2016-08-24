/*
** allum.h for allum in /home/valeru_r/rendu/Prog_Elem/Allum-1/CPE_2015_Allum1
** 
** Made by valeru_r
** Login   <valeru_r@MrWest>
** 
** Started on  Tue Feb  9 16:56:53 2016 valeru_r
** Last update Wed Jun  1 21:26:29 2016 Reever Valerus
*/

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>

# ifndef ALLUM_H_
#  define ALLUM_H_

# ifndef READ_SIZE
#  define READ_SIZE 1
# endif

typedef struct		s_get
{
  int			i;
  int			l;
  int			entier;
  int			c;
}			t_get;

typedef struct          s_read
{
  char                  *str;
  int                   r;
  int                   t;
  int                   u;
  int                   i;
  int			g;
}                       t_read;

typedef struct		s_game
{
  int			i;
  int			u;
  int			c;
  int			a;
  int			v;
}			t_game;

typedef struct		s_main
{
  int			u;
  int			j;
  char			*s;
  char			*t;
  int			*tab;
}			t_main;

void		my_putchar(char c);
int		my_putstr(char *str);
int		my_strlen(char *str);
int		my_getnbr(char *str);
int		my_put_nbr(int nb);

int		*tab_line();
int		end_tab(int *tab);
void		print_game(int *tab);
int		main_function(int *tab, char *s);
int		main_function2(int *tab, char *s, int line);
char		*get_next_line(int fd);
void		print_opponent(int *tab);
void		player_moves(int u, int j);

# endif /* !ALLUM_H_ */
