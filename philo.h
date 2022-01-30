/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 02:53:19 by klaarous          #+#    #+#             */
/*   Updated: 2022/01/20 09:17:28 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

#include "includes/libft/libft.h"

/*
The program should take the following arguments: number_of_philosophers time_to_die
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
◦number_of_philosophers: is the number of philosophers and also the number
of forks.
◦time_to_die: is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’
milliseconds after starting their last meal or the beginning of the simulation,
it dies.
◦time_to_eat: is in milliseconds and is the time it takes for a philosopher to
eat. During that time they will need to keep the two forks.
◦time_to_sleep: is in milliseconds and is the time the philosopher will spend
sleeping.
◦number_of_times_each_philosopher_must_eat: argument is optional, if all
philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the
simulation will stop. If not specified, the simulation will stop only at the death
of a philosopher.
*/

typedef struct s_data_philos
{
    unsigned int time_to_die;
    unsigned int time_to_eat;
    unsigned int time_to_sleep;
    unsigned int number_eat;
    unsigned int time_last_eat;
    unsigned int index_philo;
    unsigned int nbr_philos;
    pthread_mutex_t *forks_mutex;
}               t_data_philos;


#endif

/*


void wait_for_fork(t_data_philos *data_philos,int index_philo)
{
    struct timeval current_time;

    printf("nb fork : %d\n",data_philos->number_forks);
    while (data_philos->number_forks <= 0)
    {
        printf("Aaaaa\n");
        gettimeofday(&current_time, NULL);
        is_philo_die(data_philos->philos[index_philo].time_last_eat,data_philos->time_to_die,index_philo);
    }
}
*/