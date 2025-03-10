#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
#include "Bureaucrat.hpp"
class Form
{
	public:
		// Constructors
		Form(const Form &copy);
		Form(const std::string name, bool sign, const int grade_sign, const int grade_exec);

		// Destructor
		~Form();

		// Operators
		Form & operator=(const Form &assign);

		// Getters / Setters
		const std::string getName() const;
		bool getSign() const;
		void setSign(bool sign);
		int getGrade_sign() const;
		int getGrade_exec() const;
		void beSigned(Bureaucrat const &agent );


		// Exceptions
		class GradeTooLow : public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooHigh : public std::exception {
			virtual const char* what() const throw();
		};

	private:
		const std::string _name;
		bool _sign;
		const int _grade_sign;
		const int _grade_exec;

};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Form &object);

#endif