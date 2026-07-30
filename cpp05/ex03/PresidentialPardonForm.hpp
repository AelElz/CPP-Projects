#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <string>

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
        virtual void performAction() const;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string _target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
        ~PresidentialPardonForm();
};

#endif