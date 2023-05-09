/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:15:46 by rphuyal           #+#    #+#             */
/*   Updated: 2023/04/24 17:32:08 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	decode_and_print_char(int sig, siginfo_t *info, void *context)
{
	static int	bit_count = 0;
	static char	current_char = 0;

	(void)context;
	if (sig == SIGUSR1)
		current_char |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		if (current_char == 0)
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR1);
		}
		else
			ft_printf("%c", current_char);
		current_char = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction	catcher;

	catcher.sa_sigaction = decode_and_print_char;
	catcher.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &catcher, NULL);
	sigaction(SIGUSR2, &catcher, NULL);
	ft_printf("\033[94mServer PID: %d\n\033[0m", getpid());
	ft_printf("Waiting for a message!\n");
	while (1)
		sleep(1);
}
