/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 02:43:17 by klaarous          #+#    #+#             */
/*   Updated: 2022/01/20 10:22:03 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int is_number_pos(char *number_in_str)
{
    int number;

    number = ft_atoi(number_in_str);
    if (number < 0)
    {
        perror("arg not valide");
        exit(1);
    }
    return ((unsigned int)number);
}

pthread_mutex_t *init_forks_mutex(int number_forks)
{
    int i;
    pthread_mutex_t *forks_mutex;

    forks_mutex = malloc(sizeof(pthread_mutex_t) * number_forks);
    i = 0;
    while (i < number_forks)
    {
        pthread_mutex_init(forks_mutex + i,NULL);
        i++;
    }
    return forks_mutex;
}

void destroy_forks_mutex(pthread_mutex_t *forks_mutex,int number_forks)
{
    int i;

    i = 0;
    while (i < number_forks)
    {
        pthread_mutex_destroy(forks_mutex + i);
        i++;
    }
}



t_data_philos *initialize_data_philos(int nbr_philos,char **argv)
{
    int i;
    struct timeval current_time;
    t_data_philos *data_philos;
    pthread_mutex_t *forks_mutex;

    data_philos = malloc(sizeof(t_data_philos) * nbr_philos);
    forks_mutex = init_forks_mutex(nbr_philos);
    gettimeofday(&current_time, NULL);
    i = -1;
    while (++i < nbr_philos)
    {
        data_philos[i].time_to_die    = is_number_pos(argv[2]) * 1000;
        data_philos[i].time_to_eat    = is_number_pos(argv[3]) * 1000;
        data_philos[i].time_to_sleep  = is_number_pos(argv[4]) * 1000;
        data_philos[i].forks_mutex = forks_mutex;
        data_philos[i].nbr_philos = nbr_philos;
    }
    return data_philos;
}

int     is_philo_die(int last_time_eat,int time_to_die,int index_philo)
{
    struct timeval current_time;

    gettimeofday(&current_time, NULL);
    //printf("\ncurrent_time = %d lasttime_eat = %d  in ms = %d\n",current_time.tv_usec,last_time_eat,(current_time.tv_usec - last_time_eat));
    if ((current_time.tv_usec - last_time_eat) >= time_to_die)
    {
        printf("philo number : %d die \n",index_philo);
        exit (1);
    }
}

void*   routine(void *arg)
{
    t_data_philos *data_philos;
    struct timeval current_time;
    int index_philo;
    data_philos = (t_data_philos *)arg;
    
    index_philo = data_philos ->index_philo;
    pthread_mutex_lock(data_philos->forks_mutex + index_philo);
    pthread_mutex_lock(data_philos->forks_mutex + ((index_philo + 1) % data_philos->nbr_philos));
    is_philo_die(data_philos->time_last_eat,data_philos->time_to_die,index_philo);
    data_philos->time_last_eat  = current_time.tv_usec;
    printf("philo number : %d  eat\n",index_philo);
    usleep(data_philos ->time_to_eat);
    pthread_mutex_unlock(data_philos->forks_mutex + index_philo);
    pthread_mutex_unlock(data_philos->forks_mutex + ((index_philo + 1) % data_philos->nbr_philos));
    printf("philo number : %d finish eat\n",index_philo);
    printf("philo number : %d sleep\n",index_philo);
    usleep(data_philos->time_to_sleep);
}

void create_philosephers(t_data_philos *data_philos,int nbr_philos)
{
    int i;
    pthread_t t_philosephers[nbr_philos];
    struct timeval current_time;

    i = 0;
    while (i < nbr_philos)
    {
        data_philos[i].index_philo = i;
        pthread_create(t_philosephers + i,NULL,routine,&data_philos[i]);
        gettimeofday(&current_time,NULL);
        data_philos[i].time_last_eat = current_time.tv_usec;
        i++;
    }
    i = -1;
    while (++i < nbr_philos)
        pthread_join(t_philosephers[i],NULL);
    destroy_forks_mutex(data_philos[0].forks_mutex,nbr_philos);
    //free(data_philos);
}

int main(int ac,char **argv)
{
    t_data_philos *data_philos;
    int nbr_philos;
    int i;
    if (ac == 5)
    {
        nbr_philos = is_number_pos(argv[1]);
        data_philos =  initialize_data_philos(nbr_philos,argv);
        create_philosephers(data_philos,nbr_philos);
        // i = 0;
        // while (i < nbr_philos)
        // {
        //     printf("time die : %ld\n",data_philos[i].time_to_die);
        //     printf("time eat : %ld\n",data_philos[i].time_to_eat);
        //     printf("time sleep : %ld\n",data_philos[i].time_to_sleep);
        //     printf("number eat : %ld\n",data_philos[i].number_eat);
        //     printf("******************************************\n\n");
        //     //printf(" time last eat : %ld\n",data_philos.philos[i].time_last_eat);
        //     i++;
        // }
    }
    return (0);
}