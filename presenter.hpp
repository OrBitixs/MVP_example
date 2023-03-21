#pragma once

#include "presenter.fwd.hpp"
#include "model.fwd.hpp"
#include "view.fwd.hpp"
#include "wxWidgetsView.fwd.hpp"

class Presenter
{
private:
	Model* model = nullptr;
	View* view = nullptr;
	MyFrame* myFrame = nullptr;
public:
	void loop();
	void link_model(Model* model);
	void link_view(View* view);	
	void link_myFrame(MyFrame* myFrame);
	void print_model_details() const;
	void change_model_name(const std::string new_name);
	void change_model_version_major(const size_t model_version_major);
	void change_model_version_minor(const size_t model_version_minor);
	//void change_model_details(const std::string model_name, const size_t model_version_major, const size_t model_version_minor) const;
};