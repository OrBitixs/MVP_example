#pragma once

#include <iostream>
#include <string>

#include "lab2.h"
#include "model.hpp"
#include "presenter.hpp"
#include "view.hpp"
#include "wxWidgetsView.hpp"

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};

wxIMPLEMENT_APP_CONSOLE(MyApp);

bool MyApp::OnInit()
{

	Model* model = new Model("model1", 1, 10);
	Presenter* presenter = new Presenter();
	View* view = new View();
	
	
	presenter->link_model(model);
	presenter->link_view(view);


	MyFrame* frame = new MyFrame();

	presenter->link_myFrame(frame);
	frame->LinkPresenter(presenter);

	bool GUI = false;
	if (wxApp::argc > 1)
	{
		if (wxApp::argv[1] == "gui")
		{
			GUI = true;
		}
	}

	if (GUI)
	{
		frame->Show(true);
		SetTopWindow(frame);
	}
	else
	{
		presenter->loop();
	}

	return true;
}



//int main()
//{
//	Model model("model1", 1, 10);
//	Presenter presenter;
//	View view;
//
//
//	presenter.link_model(&model);
//	presenter.link_view(&view);
//
//	presenter.loop();
//	
//
//	//std::cout << "model: " << model.get_model_name() << "\nversion: " << model.get_model_version_major() << "." << model.get_model_version_minor() << std::endl;
//
//	return 0;
//}

