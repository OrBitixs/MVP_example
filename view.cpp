#include <string>
#include <iostream>
#include <limits>

#include "view.hpp"
#include "presenter.hpp"

View::View() = default;

const std::string View::get_command() const
{
	std::string command;
	std::cin >> command;
	return command;
}

void View::display_info(const std::string model_name, const size_t model_version_major, const size_t model_version_minor) const
{
	std::cout << "model name: " << model_name << "\tmodel version: " << model_version_major << "." << model_version_minor << std::endl;
}

const std::string View::get_new_model_name() const
{
	std::cout << "Input new model name" << std::endl;
	std::string model_name;
	std::cin >> model_name;

	return model_name;
}

const size_t View::get_new_model_version_major() const
{
	std::cout << "Input new model version major" << std::endl;
	size_t model_version_major;
	model_version_major = View::input_integer();

	return model_version_major;
}

const size_t View::get_new_model_version_minor() const
{
	std::cout << "Input new model version minor" << std::endl;
	size_t model_version_minor;
	model_version_minor = View::input_integer();

	return model_version_minor;
}

void View::command_not_recognised() const
{
	std::cout << "Command is not recognised" << std::endl;
}

const size_t View::input_integer() const
{
	std::string input_str;
    size_t input_int;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, input_str);

    while(std::cin.fail() || std::cin.eof() || input_str.find_first_not_of("0123456789") != std::string::npos) {

        std::cout << input_str << " is not an integer" << std::endl;

        if( input_str.find_first_not_of("0123456789") == std::string::npos) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }

        std::getline(std::cin, input_str);
    }

    input_int = std::stoi(input_str);
    return input_int;
}