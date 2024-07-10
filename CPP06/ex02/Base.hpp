Implement a Base class that has a public virtual destructor only. Create three empty
classes A, B and C, that publicly inherit from Base.


Implement the following functions:
Base * generate(void);
It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
to use anything you like for the random choice implementation.
void identify(Base* p);
It prints the actual type of the object pointed to by p: "A", "B" or "C".
void identify(Base& p);
It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
inside this function is forbidden.
Including the typeinfo header is forbidden.
Write a program to test that everything works as expected.


class Base{

    public:
        Base();
        virtual ~Base();
        Base * generate(void);
        void identify(Base *p);
        void identify(Base &p);
};