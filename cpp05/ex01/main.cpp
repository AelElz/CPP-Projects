#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    // 1. Create a form and show its initial state
    std::cout << "--- 1. New form ---" << std::endl;
    try
    {
        Form taxForm("Tax Form", 50, 40);
        std::cout << taxForm << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // 2. Invalid form grades
    std::cout << std::endl << "--- 2. Invalid form grades ---" << std::endl;
    try
    {
        Form bad("Bad Form", 0, 40);      // sign grade too high
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    try
    {
        Form bad("Bad Form", 50, 200);    // exec grade too low
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // 3. A weak bureaucrat fails to sign
    std::cout << std::endl << "--- 3. Grade too low to sign ---" << std::endl;
    try
    {
        Form taxForm("Tax Form", 50, 40);
        Bureaucrat jim("Jim", 90);        // 90 is worse than 50
        std::cout << jim << std::endl;
        jim.signForm(taxForm);
        std::cout << taxForm << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // 4. A strong bureaucrat signs successfully
    std::cout << std::endl << "--- 4. Successful signing ---" << std::endl;
    try
    {
        Form taxForm("Tax Form", 50, 40);
        Bureaucrat ana("Ana", 30);        // 30 is better than 50
        std::cout << ana << std::endl;
        ana.signForm(taxForm);
        std::cout << taxForm << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // 5. Exact match on the required grade
    std::cout << std::endl << "--- 5. Exact grade match ---" << std::endl;
    try
    {
        Form taxForm("Tax Form", 50, 40);
        Bureaucrat sam("Sam", 50);        // exactly 50, should pass
        sam.signForm(taxForm);
        std::cout << taxForm << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}