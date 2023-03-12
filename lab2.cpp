// lab2.cpp : Defines the entry point for the application.
//
#include <iostream>
#include <string>

#include "lab2.h"
#include "model.hpp"
#include "presenter.hpp"
#include "view.hpp"

int main()
{
	Model model("model1", 1, 10);
	Presenter presenter;
	View view;

	presenter.link_model(&model);
	presenter.link_view(&view);

	presenter.loop();
	

	//std::cout << "model: " << model.get_model_name() << "\nversion: " << model.get_model_version_major() << "." << model.get_model_version_minor() << std::endl;

	return 0;
}
