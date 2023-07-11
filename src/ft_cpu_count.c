/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_file_name (file name is useless too)          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42header-remover <whatever@example.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by file history     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cpu_count.h"

#ifdef _WIN32
# include <windows.h>
#else
# include <unistd.h>
#endif

#ifdef _WIN32

t_err	ft_cpu_count(int *out)
{
	SYSTEM_INFO	sysInfo;

	GetSystemInfo(&sysInfo);
	*out = sysInfo.dwNumberOfProcessors;
	return (false);
}

#elif defined(_SC_NPROCESSORS_ONLN)

t_err	ft_cpu_count(int *out)
{
	const long cpuCount = sysconf(_SC_NPROCESSORS_ONLN);

	if (cpuCount < 0)
		return true;
	*out = (int)cpuCount;
	return (false);
}

#else

t_err	ft_cpu_count(int *out)
{
	(void)out;
	return (true);
}

#endif
