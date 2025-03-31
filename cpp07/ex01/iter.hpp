/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:58:14 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/31 15:14:13 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename A>
void iter(A* ar_arr, unsigned long len, void (*func)(A&))
{
	for(unsigned long i =0; i<len; i++)
	{
		func(ar_arr[i]);
	}
}