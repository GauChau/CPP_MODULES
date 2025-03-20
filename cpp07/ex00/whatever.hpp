/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:58:14 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/20 12:19:11 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename S>
void swap(S &x, S &y)
{
	S buf;
	buf = x;
	x = y;
	y = buf;
}

template <typename T>
T min(T x, T y)
{
	if (x<y)
		return (x);
	else
		return (y);
}

template <typename T>
T max(T x, T y)
{
	if (x > y)
		return (x);
	else
		return (y);
}