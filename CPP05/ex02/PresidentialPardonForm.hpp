/*?*/
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
    std::string _target;

    PresidentialPardonForm();

public:
    PresidentialPardonForm( const std::string& target );
    PresidentialPardonForm( const PresidentialPardonForm& src );
    ~PresidentialPardonForm();

    PresidentialPardonForm& operator=( const PresidentialPardonForm& rhs );
    
    void execute( const Bureaucrat& executor ) const;
};

#endif // PRESIDENTIALPARDONFORM_HPP

/*aForm*/
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	
	private:
		std::string	_target;

	public:
		/* Constructors & Destructors */
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm);
		~PresidentialPardonForm(void);

		/* Functions */
		virtual void	executeRequirements(Bureaucrat const &executor) const;

		/* Overloaded operators */
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &presidentialPardonForm);
	
};

#endif