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
    void ResfreshModelInfo(const std::string modelName, const size_t modelVersionMajor, const size_t modelVersionMinor);

private:
    Presenter* presenter;

    wxTextCtrl* modelName;
    wxTextCtrl* modelVersionMajor;
    wxTextCtrl* modelVersionMinor;
    wxTextCtrl* modelInformation;
    wxButton* refreshButton;


    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnEnterDown(wxKeyEvent& event);
    void OnRefreshButton(wxCommandEvent& event);

    void SetupForm();

};

enum
{
    ID_ENTER_DOWN = 1,
    ID_INFORMATION = 2,
    ID_REFRESH_BUTTON = 3
};

