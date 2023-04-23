/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:15:49 by rphuyal           #+#    #+#             */
/*   Updated: 2023/04/23 20:11:39 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	encode_and_send_sig(pid_t server_pid, int w_time, int c)
{
	int	shift;

	shift = 8;
	while (shift--)
	{
		if (c & (1 << shift))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(w_time);
	}
}

void	send_message(pid_t server_pid, char *message)
{
	int	wait_time;

	if (ft_strlen(message) > 100)
		wait_time = 300;
	else
		wait_time = 100;
	while (*message)
		encode_and_send_sig(server_pid, wait_time, *message++);
	encode_and_send_sig(server_pid, wait_time, *message);
	ft_printf("\033[94mWaiting for server responce!\033[0m ");
	while (wait_time)
	{
		ft_printf(".");
		sleep(1);
		wait_time /= 100;
	}
	ft_printf("\n\033[91mServer didn't respond in time!\n\033[0m");
	ft_printf("Make sure the server pid was correct!\n");
	exit(0);
}

void	server_response(int sig)
{
	(void)sig;
	ft_printf("\033[0;32mSent successful! Server responded with 👍\n\033[0m");
	exit(0);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
	{
		ft_printf("\033[91mWrong number of arguments!\n\033[0m");
		ft_printf("\033[93mCorrect: ./client [ServerPID] [Message]\n\033[0m");
		return (0);
	}
	server_pid = ft_atoi(argv[1]);
	if (ft_strlen(ft_itoa(server_pid)) < ft_strlen(argv[1]))
		return (ft_printf("\033[91mInvalid Server PID!\n\033[0m") - 29);
	signal(SIGUSR1, server_response);
	send_message(server_pid, argv[2]);
	return (0);
}


