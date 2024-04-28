/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:47:54 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/28 10:16:35 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

	private:
		int					_raw;
		static const int	_fractionalBits = 8;

	public:

	/*	--- Orthodox Canonical Form	---	*/
		//	Default constructor			
		Fixed( void );

		//	Copy constructor
		Fixed(const Fixed& source);

		//	Copy assignment operator
		Fixed& operator=(const Fixed& source);

		//	Destructor
		~Fixed( void );

	/*	---	Constructor overloads -----	*/
		Fixed( int const intNbr );
		Fixed( float const floatNbr );
	
	/*	---	Operator overloads --------	*/
		// Fixed& operator<


	/*	--- Methods -------------------	*/
		int		getRawBits( void ) const;
		void	setRawBits( int const raw);

		float	toFloat( void ) const;
		int		toInt( void ) const;

};

std::ostream& operator<<( std::ostream& os, const Fixed& fixed_nbr );

#endif