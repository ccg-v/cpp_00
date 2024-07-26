/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:25:11 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/24 21:13:25 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class	RobotomyRequestForm : public AForm {
	
	private:
	
		std::string	_target;

	public:

		/* --- Orthodox Canonical Form -------------------------------------- */

		//	Default constructor
		RobotomyRequestForm();
		//	Copy constructor
		RobotomyRequestForm(const RobotomyRequestForm & source);
		//	Copy assignment operator
		RobotomyRequestForm& operator=(const RobotomyRequestForm & source);
		//	Default destructor
		~RobotomyRequestForm();
		
		//	Parameterized constructor
		RobotomyRequestForm(const std::string & target);

	protected:

		/* --- Member functions --------------------------------------------- */
	
		void	performAction() const;
};

#endif