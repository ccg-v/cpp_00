/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:18:40 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/21 13:29:47 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

//	Default constructor
Form::Form () : _formName("Default"), _isSigned(false), _gradeToSign(100),
				_gradeToExecute(50) {
	std::cout << "Default form constructor called" << std::endl;
}

//	Copy constructor
Form::Form ( const Form& source ) : _formName(source._formName),
	_isSigned(source._isSigned), _gradeToSign(source._gradeToSign),
	_gradeToExecute(source._gradeToExecute) {
	*this = source;
}

//	Copy assignment operator
Form &Form::operator=( const Form& source ) {
	if (this != &source)
	{
		// this->_formName = source._formName;
		this->_isSigned = source._isSigned;
		// this->_gradeToSign = source._gradeToSign;
		// this->_gradeToExecute = source._gradeToExecute;
	}
	return (*this);
}

//	Default destructor
Form::~Form () {
	std::cout << "Form " << getFormName() << " destroyed by default destructor"
			  << std::endl;
}

// Parameterized constructor
Form::Form(const std::string& formName, const int gradeToSign, const int gradeToExecute)
    : _formName(formName), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    std::cout << "Form parameterized constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}


/* --- Getters ------------------------------------------------------------- */

const std::string	&Form::getFormName () const {
	return _formName;
}

bool	Form::getIsSigned () const {
	return _isSigned;
}

int	Form::getGradeToSign () const {
	return _gradeToSign;
}

int	Form::getGradeToExecute() const {
	return _gradeToExecute;
}

/* --- Member functions ---------------------------------------------------- */	

void	Form::beSigned ( Bureaucrat bureaucrat ) {
	if (_isSigned == true)
		throw IsAlreadySignedException();
	if (bureaucrat.getGrade() > getGradeToSign())
		throw GradeTooLowException();
	_isSigned = true;
}

//	Exceptions
const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

const char* Form::IsAlreadySignedException::what() const throw() {
    return "Form is already signed";
}

//	Insertion operator (<<) overload
std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "\tForm " << f.getFormName() << ", Signed: " << f.getIsSigned()
       << ", Grade to Sign: " << f.getGradeToSign()
       << ", Grade to Execute: " << f.getGradeToExecute();
    return os;
}