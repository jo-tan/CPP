a Form class. It has:
• A constant name.
• A boolean indicating whether it is signed (at construction, it’s not).
• A constant grade required to sign it.
• And a constant grade required to execute it.
All these attributes are private, not protected.
The grades of the Form follow the same rules that apply to the Bureaucrat. Thus,
the following exceptions will be thrown if a form grade is out of bounds:
Form::GradeTooHighException and Form::GradeTooLowException.
Same as before, write getters for all attributes and an overload of the insertion («)
operator that prints all the form’s informations.

Add also a beSigned() member function to the Form that takes a Bureaucrat as
parameter. It changes the form status to signed if the bureaucrat’s grade is high enough
(higher or egal to the required one). Remember, grade 1 is higher than grade 2.
If the grade is too low, throw a Form::GradeTooLowException.
Lastly, add a signForm() member function to the Bureaucrat. If the form got signed,
it will print something like:
<bureaucrat> signed <form>
Otherwise, it will print something like:
<bureaucrat> couldn’t sign <form> because <reason>.
Implement and turn in some tests to ensure everything works as expected.