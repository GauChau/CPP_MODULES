#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include <string>
#include "Bureaucrat.hpp"

class AForm
{
	public:
		// Constructors
		AForm(const AForm &copy);
		AForm(const std::string name, bool sign, const int grade_sign, const int grade_exec);

		// Destructor
		virtual ~AForm()=0;

		// Operators
		AForm & operator=(const AForm &assign);

		// Getters / Setters
		const std::string getName() const;
		bool getSign() const;
		void setSign(bool sign);
		int getGrade_sign() const;
		int getGrade_exec() const;
		void beSigned(Bureaucrat const &agent );
		void execute(Bureaucrat const & executor) const;
		virtual void FormAction(void) = 0;


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
std::ostream & operator<<(std::ostream &stream, const AForm &object);

#endif