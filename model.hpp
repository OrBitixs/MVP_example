#pragma once

#include <string>

#include "model.fwd.hpp"

class Model
{
private:
	std::string model_name;
	size_t model_version_major;
	size_t model_version_minor;

public:
	explicit Model(std::string name, size_t version_major, size_t version_minor);

	void set_model_name(const std::string new_model_name);
	void set_model_version_major(const size_t new_version_major);
	void set_model_version_minor(const size_t new_version_minor);

	const std::string get_model_name() const;
	const size_t get_model_version_major() const;
	const size_t get_model_version_minor() const;
};