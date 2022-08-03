#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

using std::cout;
using std::endl;
using std::string;
using std::exception;

class Form ;

class Bureaucrat
{
	private:
		string _name;
		int		_grade;
		int		_exec_grade;

	public:
		Bureaucrat(string name, int grade, int exec);
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &old_obj);
		const string	&getName(void) const;
		int				getGrade(void) const;
		int				getExec(void) const;
		void			setGrade(int grade);
		void			incrementGrade(void);
		void			decrementGrade(void);
		void			signForm(Form &name);
		void			executeForm(Form const &form);

		class	GradeTooHighException : public exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

		class	GradeTooLowException : public exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

		class	CannotExecute : public exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

		
};

std::ostream &operator << (std::ostream &out, Bureaucrat const &rhs);

#endif