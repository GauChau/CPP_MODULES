#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm( RobotomyRequestForm const & src );
		~RobotomyRequestForm();

		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );
		void	FormAction(void)const;

	private:
		std::string _target;

};

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i );

#endif /* ******************************************* RobotomyRequestForm_H */