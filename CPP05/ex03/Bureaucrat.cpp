#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	// cout << "Bureaucrat default constructor called" << endl;

}

Bureaucrat::~Bureaucrat()
{
	// cout << "Bureaucrat destructor called" << endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &old_obj): _name(old_obj.getName())
{
	// cout << "Bureaucrat copy constructor called" << endl;
	this->_grade = old_obj.getGrade();
}

Bureaucrat::Bureaucrat(string name, int grade): _name(name)
{
	// cout << "Bureaucrat assignment constructor called" << endl;
	this->_grade = grade;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::setGrade(int grade)
{
	this->_grade = grade;
}

const string &Bureaucrat::getName(void) const
{
	return(this->_name);
}

// int	Bureaucrat::getExecGrade(void) const
// {
// 	return (this->_exec_grade);
// }

void	Bureaucrat::incrementGrade(void)
{
	try
	{
		if (this->_grade - 1 < 1)
			throw GradeTooHighException();
		else
			this->_grade--;
	}
	catch(exception &caught)
	{
		cout << caught.what() << endl;
	}
}

void	Bureaucrat::decrementGrade(void)
{
	try
	{
		if (this->_grade + 1 > 150)
			throw GradeTooLowException();
		else
			this->_grade++;
	}
	catch(const exception &e)
	{
		std::cerr << e.what() << endl;
	}
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade Too High");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade Too Low");
}

const char	*Bureaucrat::CannotExecute::what(void) const throw()
{
	return ("Couldn't execute, grade too low");
}

void		Bureaucrat::signForm(Form &name)
{	
	if (name.getSign() == false && this->_grade < name.getSignGrade())
	{
		cout << this->_name << " signed " << name.getName() << endl;
		name.setSigned(true);
	}
	else
		cout << this->_name << " couldn't sign " << name.getName() << " because ";
}

void		Bureaucrat::executeForm(Form const &form)
{
	try
	{
		if (form.getSign() == true && this->_grade < form.getSignGrade())
			cout << this->_name << " executed " << form.getName() << endl;
		else
			throw CannotExecute();
	}
	catch(exception &e)
	{
		cout << e.what() << endl;
	}
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &ref)
{
  	this->_grade = ref.getGrade();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &rhs)
{
    out << rhs.getName() << " grade <" << rhs.getGrade() << ">";
    return (out); 
}