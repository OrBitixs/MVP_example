#include <iostream>

#include "presenter.hpp"
#include "view.hpp"
#include "model.hpp"
#include "wxWidgetsView.hpp"

#define EXIT "exit"
#define DISPLAY "display"
#define EDIT_NAME "edit_name"
#define EDIT_VERSION_MAJOR "edit_version_major"
#define EDIT_VERSION_MINOR "edit_version_minor"


void Presenter::loop()
{
	if (!view)
	{
		std::cout << "ERROR::Presenter::view is nullptr";
	}
	else
	{
		while (true)
		{
			std::cout << "enter command\npossible commands: [" << EXIT << "|" << DISPLAY << "|" << EDIT_NAME << "|" << EDIT_VERSION_MAJOR << "|" << EDIT_VERSION_MINOR <<"]" << std::endl;
			const std::string command = view->get_command();

			if (command == EXIT)
			{
				exit(0);
			}
			else if (command == DISPLAY)
			{
				view->display_info(model->get_model_name(), model->get_model_version_major(), model->get_model_version_minor());
			}
			else if (command == EDIT_NAME)
			{
				model->set_model_name(view->get_new_model_name());
			}
			else if (command == EDIT_VERSION_MAJOR)
			{
				model->set_model_version_major(view->get_new_model_version_major());
			}
			else if (command == EDIT_VERSION_MINOR)
			{
				model->set_model_version_minor(view->get_new_model_version_minor());
			}
			else
			{
				view->command_not_recognised();
				continue;
			}
		}
	}
}

void Presenter::link_model(Model* model)
{
	this->model = model;
}

void Presenter::link_view(View* view)
{
	this->view = view;
}

void Presenter::link_myFrame(MyFrame* myFrame)
{
	this->myFrame = myFrame;
}


void Presenter::print_model_details() const
{
	if (!view)
	{
		std::cout << "ERROR::Presenter::view is nullptr";
	}
	else
	{
		view->display_info(model->get_model_name(), model->get_model_version_major(), model->get_model_version_minor());
	}
}

void Presenter::show_model_details() const
{
	myFrame->ResfreshModelInfo(model->get_model_name(), model->get_model_version_major(), model->get_model_version_minor());
}

void Presenter::change_model_name(const std::string model_name)
{
	if (!model)
	{
		std::cout << "ERROR::Presenter::model is nullptr" << std::endl;
	}
	else
	{
		std::cout << "new model name:\t" << model_name << std::endl;
		model->set_model_name(model_name);
	}
}

void Presenter::change_model_version_major(const size_t model_version_major)
{
	if (!model)
	{
		std::cout << "ERROR::Presenter::model is nullptr";
	}
	else
	{
		std::cout << "new model version major:\t" << model_version_major<< std::endl;
		model->set_model_version_major(model_version_major);
	}
}

void Presenter::change_model_version_minor(const size_t model_version_minor)
{
	if (!model)
	{
		std::cout << "ERROR::Presenter::model is nullptr";
	}
	else
	{
		std::cout << "new model version minor:\t" << model_version_minor << std::endl;
		model->set_model_version_minor(model_version_minor);
	}

}


