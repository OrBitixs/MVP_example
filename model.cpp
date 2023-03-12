#include "model.hpp"

#include <string>

Model::Model(std::string name, size_t version_major, size_t version_minor) : model_name(name), model_version_major(version_major), model_version_minor(version_minor)
{	}


void Model::set_model_name(const std::string new_model_name)
{
	model_name = new_model_name;
}
void Model::set_model_version_major(const size_t new_version_major)
{
	model_version_major = new_version_major;
}

void Model::set_model_version_minor(const size_t new_version_minor)
{
	model_version_minor = new_version_minor;
}


const std::string Model::get_model_name() const
{
	return model_name;
}
const size_t Model::get_model_version_major() const
{
	return model_version_major;
}

const size_t Model::get_model_version_minor() const
{
	return model_version_minor;
}
