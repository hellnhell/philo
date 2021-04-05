/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:53:05 by hellnhell         #+#    #+#             */
/*   Updated: 2021/04/05 19:30:55 by hellnhell        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <string.h>

typedef struct s_philos
{
    int             position;
    int             eating;
    int             fork_l;
    int             fork_r;
    int             eat_count_philo;
    u_int64_t       limit;
    u_int64_t       last_eat;
    struct s_global *global;
    pthread_mutex_t mutex;
    pthread_mutex_t mutex_eat;    
}             t_philos;

typedef struct s_global
{
    int             n_philos;
    int             n_eats;
    int             eat_count;
    u_int64_t       t_eat;
    u_int64_t       t_sleep;
    u_int64_t       t_die;
    u_int64_t       start;
    t_philos        *philos;
    pthread_mutex_t *mutex_forks; 
    pthread_mutex_t mutex_print;
    pthread_mutex_t mutex_dead;
}              t_global;


int         ft_strlen(char *str);
void	    ft_putnbr(int nb);
int         ft_atoi(const char *s);
int         main(int argc, char **argv);
int         init_philos(t_global *global);
int         start_threads(t_global *global);
void        *routine(void *philo_void);
void        *dead(void *philo_void);
void        life(t_philos *philos);
void        count(void *global_v);
u_int64_t   gettime(void);
int         print_ms(t_philos *philos, char *str, int n);
int         free_global(t_global *global);

#endif