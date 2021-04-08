/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 19:30:43 by hellnhell         #+#    #+#             */
/*   Updated: 2021/04/08 13:14:46 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    unlink_gl_sem(t_global *global)
{
    sem_unlink(global->sem_fork); 
    sem_unlink(global->sem_dead);
    sem_unlink(global->sem_print);
}

int init_philos(t_global *global)
{
    char    sem_name[200];
    int i;

    i = 0;
    unlink_gl_sem(global);
    global->mutex_forks = sem_open(global->sem_fork, O_CREAT, 0644, global->n_philo);
    global->mutex_dead = sem_open(global->sem_dead, O_CREAT, 0644, 0);
    global->mutex_print = sem_open(global->sem_print, O_CREAT, 0644, 1);
    while (i < global->n_philo)
    {
        global->philo[i].position = i;
        global->philo[i].eating = 0;
        global->philo[i].fork_r = (i + 1) % global->n_philo;
        global->philo[i].fork_l = i;
        global->philo[i].global = global;
      
        name("sem_philo", sem_name, i);
        sem_unlink(sem_name);
        global->philo[i].mutex = sem_open(sem_name, O_CREAT, 0644, 1);
        name("sem_philoeat", sem_name, i);
        sem_unlink(sem_name);
        global->philo[i].mutex_eat = sem_open(sem_name, O_CREAT, 0644, 1);
        i++;
    }
    return (0);
}
