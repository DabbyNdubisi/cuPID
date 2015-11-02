#include "projectdetails.h"
#include "ui_projectdetails.h"
#include "Models/cupidsession.h"
#include "Models/user.h"
#include <QPushButton>
#include "Models/administratoruser.h"
#include "Models/studentuser.h"
#include "editteamconfigurationsdialog.h"
#include "Repository/storage.h"
#include <QDebug>
#include "QMessageBox"
#include "Models/projectpartnerprofile.h"

ProjectDetails::ProjectDetails(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectDetails)
{
    ui->setupUi(this);
    this->project = NULL;

    // Retrieve the project data and populate them into the view
    viewWillAppear();

    // Flag to know if the currentUser is registered in this project
    isRegistered = false;
}

ProjectDetails::~ProjectDetails()
{
    delete ui;
}


void ProjectDetails::didSetProject()
{
    updateUI();
}

void ProjectDetails::updateUI()
{
    if(project != NULL)
    {
        // Fill the form with all information from project
        ui->txtProjDescription->setText(project->getDescription());
        ui->txtProjTitle->setText(project->getTitle());
        ui->lblRegisteredStudents->setText(QString::number(project->getNumberOfRegisteredUsers()) + " Students Registered in this Project");
    }
}

void ProjectDetails::viewWillAppear()
{
    //  check what kind of user we are and make the nessesary changes to the UI
    if (dynamic_cast<AdministratorUser *>(CupidSession::getInstance()->getCurrentUser()))
    {
        ui->btnRegistration->setHidden(true);
        ui->btnEditProject->setHidden(false);
        ui->btnStartAlgo->setHidden(false);
    }
    else if (dynamic_cast<StudentUser *>(CupidSession::getInstance()->getCurrentUser()))
    {
        ui->btnRegistration->setHidden(false);
        ui->btnEditProject->setHidden(true);
        ui->btnStartAlgo->setHidden(true);
        if(((StudentUser *)CupidSession::getInstance()->getCurrentUser())->isRegisteredInProject(project))
        {
            ui->btnRegistration->setText(tr("Unregister"));
            isRegistered = true;
        }
    }

    updateUI();
}

void ProjectDetails::viewWillDisappear()
{
    project = NULL;
}

void ProjectDetails::on_btnRegistration_clicked()
{
    StudentUser* currentUser = (StudentUser *)CupidSession::getInstance()->getCurrentUser();

    if(currentUser->getFetchIDForPPP() == 0)
    {
        // Notify StudentUser that they don't have a PPP
        // We need to pull in PPP as soon as we log in.
        QMessageBox messageBox;
        messageBox.warning(0,"Registration failed","Please create a profile before you register!");
        messageBox.setFixedSize(500,200);
        return;
    }

    QVector<Project*> projects;
    projects.append(project);

    if(isRegistered)
    {

        // Unregister this student
        if(Storage::defaultStorage().executeActionForProject(unregisteredFromProject,*currentUser,projects))
        {
            // Error occured
            qDebug() << "UnRegistration failed";
            QMessageBox messageBox;
            messageBox.critical(0,"Error","Sorry, an error has occured while saving your request!");
            messageBox.setFixedSize(500,200);
        }
        else
        {
            // Refresh the current UI
            qDebug() << "UnRegistration Successful";
            project->unRegisterPPP(currentUser->getProfile());
            ui->btnRegistration->setText(tr("Register"));
            isRegistered = false;
            updateUI();
            QMessageBox messageBox;
            messageBox.information(0,"Success","You're now unregistered from this project!");
            messageBox.setFixedSize(500,200);
        }
    }
    else
    {
        if(Storage::defaultStorage().executeActionForProject(registeredInProject,*currentUser, projects))
        {
            // Error occured
            qDebug() << "Registration failed";
            QMessageBox messageBox;
            messageBox.critical(0,"Error","Sorry, an error has occured while saving your request!");
            messageBox.setFixedSize(500,200);
        }
        else
        {
            qDebug() << "Registration Successful";
            project->registerPPP(currentUser->getProfile());
            ui->btnRegistration->setText(tr("Unregister"));
            isRegistered = true;
            updateUI();
            QMessageBox messageBox;
            messageBox.information(0,"Success","You're now registered in this project!");
            messageBox.setFixedSize(500,200);
        }
    }

    emit registrationClicked();
}



void ProjectDetails::userToViewProject()
{
    this->project = CupidSession::getInstance()->getCurrentProject();
    if(project != NULL)
        didSetProject();

    viewWillAppear();
}

void ProjectDetails::on_btnStartAlgo_clicked()
{
    // Start the matching algorithm
    emit startAlgoClicked();
}

void ProjectDetails::on_btnEditProject_clicked()
{
    EditTeamConfigurationsDialog dialog(this);
    dialog.getUi().teamSizeSpinBox->setValue(project->getProjectConfiguration(TeamSize).getValue());
    dialog.exec();
    if(dialog.result() == QDialog::Accepted)
    {
        int newTeamConfiguration =  dialog.getUi().teamSizeSpinBox->value();
        project->changeConfiguration(Configuration(TeamSize, newTeamConfiguration));
        QVector<Project*> projects;
        projects.append(project);

        //Save Configurations
        if(Storage::defaultStorage().executeActionForProject(updatedProject, *(CupidSession::getInstance()->getCurrentUser()), projects) != 0)
        {
            // update error
            qDebug() << "Error occured on update" + project->getProjectId();
            QMessageBox messageBox;
            messageBox.critical(0,"Error","An error occured while attempting to fufill your request");
            messageBox.setFixedSize(500,200);
        }
        else
        {
            // notify update succeeded
            qDebug() << "Success";
            QMessageBox messageBox;
            messageBox.information(0,"Success","Your project has been successfulyl updated!");
            messageBox.setFixedSize(500,200);
        }
    }
}

void ProjectDetails::handleUserContextSwitch(DetailViewType type)
{
    if (type == ProjectDetailType)
    {
        //entering view
        viewWillAppear();
    }
    else
    {
        //leaving view
        viewWillDisappear();
    }
}
