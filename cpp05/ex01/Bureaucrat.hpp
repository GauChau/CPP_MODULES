#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Form;

class Bureaucrat
{
	public:
		// Constructors
		Bureaucrat();
		Bureaucrat(const std::string Name, int grade);
		Bureaucrat(const Bureaucrat &copy);

		// Destructor
		~Bureaucrat();

		// Operators
		Bureaucrat & operator=(const Bureaucrat &assign);

		// Members
		const std::string	getName() const;
		int					getGrade() const;
		void	grade_plus();
		void	grade_minus();
		void	signForm(Form &form) const;

		// Exceptions
		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw();
		};

	private:
		const std::string	_Name;
		int			_grade;

};

std::ostream & operator<<(std::ostream &stream, const Bureaucrat &object);

#endif