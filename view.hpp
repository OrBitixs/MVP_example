#pragma once

#include <string>

#include "view.fwd.hpp"
#include "presenter.fwd.hpp"

class View
{
private:
	Presenter* presenter = nullptr;
public:
	explicit View();
	const std::string get_command() const;
	void display_info(const std::string model_name, const size_t model_version_major, const size_t model_version_minor) const;
	const std::string get_new_model_name() const;
	const size_t get_new_model_version_major() const;
	const size_t get_new_model_version_minor() const;
	void command_not_recognised() const;
	const size_t input_integer() const;
};