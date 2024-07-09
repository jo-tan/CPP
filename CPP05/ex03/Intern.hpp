Because filling out forms is annoying enough, it would be cruel to ask our bureaucrats
to do this all day long. Fortunately, interns exist. In this exercise, you have to implement
the Intern class. The intern has no name, no grade, no unique characteristics. The only
thing the bureaucrats care about is that they do their job.
However, the intern has one important capacity: the makeForm() function. It takes
two strings. The first one is the name of a form and the second one is the target of the
form. It return a pointer to a Form object (whose name is the one passed as parameter)
whose target will be initialized to the second parameter.
It will print something like:
Intern creates <form>
If the form name passed as parameter doesn’t exist, print an explicit error message.

You must avoid unreadable and ugly solutions like using a if/elseif/else forest. This
kind of things won’t be accepted during the evaluation process. You’re not in Piscine
(pool) anymore. As usual, you have to test that everything works as expected.
For example, the code below creates a RobotomyRequestForm targeted on "Ben-
der":
{
Intern
Form*
someRandomIntern;
rrf;
rrf = someRandomIntern.makeForm("robotomy request", "Bender");
}