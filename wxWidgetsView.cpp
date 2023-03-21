#include "wxWidgetsView.hpp"

#define ck_ENTER 13

MyFrame::MyFrame() : wxFrame(nullptr, wxID_ANY, "Simple From")
{
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT);

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);
    SetupForm();

    CreateStatusBar();

    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}

void MyFrame::LinkPresenter(Presenter* presenter)
{
    this->presenter = presenter;
}


void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
        "About Hello World", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnEnterDown(wxKeyEvent& event)
{
    //wxMessageBox(wxString::Format("KeyDown: %i\n", (int)event.GetKeyCode()));
    //std::cout << "Key "<< (int)event.GetKeyCode() <<" has been pressed down" << std::endl;
    if (event.GetKeyCode() == ck_ENTER)
    {
        if (!presenter)
        {
            std::cout << "ERROR::MyFrame::presenter is nullptr" << std::endl;
            exit(-1);
        }
        if (event.GetEventObject() == modelName)
        {
            presenter->change_model_name(modelName->GetValue().ToStdString());
        }
        else if (event.GetEventObject() == modelVersionMajor)
        {
            size_t version;
            try
            {
                version = std::stoi(modelVersionMajor->GetValue().ToStdString());
                presenter->change_model_version_major(version);
            }
            catch (std::invalid_argument const& ex)
            {
                std::cout << "std::invalid_argument::what(): " << ex.what() << std::endl;
            }
        }
        else if (event.GetEventObject() == modelVersionMinor)
        {
            size_t version;
            try
            {
                version = std::stoi(modelVersionMinor->GetValue().ToStdString());
                presenter->change_model_version_minor(version);
            }
            catch (std::invalid_argument const& ex)
            {
                std::cout << "std::invalid_argument::what(): " << ex.what() << std::endl;
            }
        }

    }
    event.Skip();
}

void MyFrame::OnRefreshButton(wxCommandEvent& event)
{
    presenter->show_model_details();
}

void MyFrame::ResfreshModelInfo(const std::string modelName, const size_t modelVersionMajor, const size_t modelVersionMinor)
{
    std::string concatenated = modelName + std::to_string(modelVersionMajor) + "." + std::to_string(modelVersionMinor);
    modelInformation->ChangeValue(concatenated);
}


void MyFrame::SetupForm()
{
    wxPanel* panel = new wxPanel(this);

    wxStaticText* nameLabel = new wxStaticText(panel, wxID_ANY, "Model name:");
    modelName = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(FromDIP(400), wxDefaultSize.GetHeight()));

    wxStaticText* versionMajorLabel = new wxStaticText(panel, wxID_ANY, "Version major:");
    modelVersionMajor = new wxTextCtrl(panel, wxID_ANY);

    wxStaticText* versionMinorLabel = new wxStaticText(panel, wxID_ANY, "Version minor:");
    modelVersionMinor = new wxTextCtrl(panel, wxID_ANY);

    modelInformation = new wxTextCtrl(panel, ID_INFORMATION);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    wxWindow::SetMinSize(wxSize(400, 400));

    sizer->Add(nameLabel, 0, wxEXPAND | wxALL, FromDIP(3));
    sizer->Add(modelName, 0, wxEXPAND | wxALL, FromDIP(3));
    sizer->Add(versionMajorLabel, 0, wxEXPAND | wxALL, FromDIP(3));
    sizer->Add(modelVersionMajor, 0, wxEXPAND | wxALL, FromDIP(3));
    sizer->Add(versionMinorLabel, 0, wxEXPAND | wxALL, FromDIP(3));
    sizer->Add(modelVersionMinor, 0, wxEXPAND | wxALL, FromDIP(3));

    refreshButton = new wxButton(panel, ID_REFRESH_BUTTON, wxT("Refresh"), wxDefaultPosition, wxDefaultSize, 0);
    sizer->Add(refreshButton, 0, wxEXPAND | wxALL, FromDIP(3));

    sizer->Add(modelInformation, 0, wxEXPAND | wxALL, FromDIP(3));

    panel->SetSizer(sizer);

    wxBoxSizer* overallSizer = new wxBoxSizer(wxVERTICAL);
    overallSizer->Add(panel);
    this->SetSizer(overallSizer);

    modelName->Bind(wxEVT_CHAR_HOOK, &MyFrame::OnEnterDown, this);
    modelVersionMajor->Bind(wxEVT_CHAR_HOOK, &MyFrame::OnEnterDown, this);
    modelVersionMinor->Bind(wxEVT_CHAR_HOOK, &MyFrame::OnEnterDown, this);
    refreshButton->Bind(wxEVT_BUTTON, &MyFrame::OnRefreshButton, this);

}

