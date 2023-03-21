#pragma once

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "wxWidgetsView.fwd.hpp"
#include "presenter.fwd.hpp"
#include "presenter.hpp"

class MyFrame : public wxFrame
{
public:
    MyFrame();

    void LinkPresenter(Presenter* presenter);

private:
    Presenter* presenter;

    wxTextCtrl* modelName;
    wxTextCtrl* modelVersionMajor;
    wxTextCtrl* modelVersionMinor;
    wxTextCtrl* modelInformation;


    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnEnterDown(wxKeyEvent& event);

    void SetupForm();

};

enum
{
    ID_ENTER_DOWN = 1,
    ID_INFORMATION = 2
};

