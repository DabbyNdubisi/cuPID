#ifndef PROJECTDETAILS_H
#define PROJECTDETAILS_H

#include "sidebarwidget.h"

// Subsystem dependencies
#include "DataAccessLayer/project.h"

#include <QWidget>

namespace Ui {
class ProjectDetails;
}

class ProjectDetails : public QWidget
{
    Q_OBJECT

public:
    ProjectDetails(QWidget *parent = 0);
    ~ProjectDetails();

    /*!
     *  @param: none
     *   @desc: all setup for this VC done here
     * @return: void
    */
    void viewWillAppear();

    /*!
     *  @param: none
     *   @desc: all clean up for this VC done here
     * @return: void
    */
    void viewWillDisappear();

    /*!
     *  @param: none
     *   @desc: set the current Project to be viewed
     * @return: void
    */
    void setProject(Project*);

signals:
    /*!
     *  @param: void
     *   @desc: A signal emitted when the registration button is clicked
     * @return: void
    */
    void registrationClicked();

    /*!
     *  @param: void
     *   @desc: A signal emitted when the start algorithm button is clicked
     * @return: void
    */
    void startAlgoClicked();

    /*!
     *  @param: void
     *   @desc: A signal emitted when the edit Project button is clicked
     * @return: void
    */
    void editProjectClicked();

private slots:
    void on_btnRegistration_clicked();
    void on_btnStartAlgo_clicked();
    void on_btnEditProject_clicked();
    void handleUserContextSwitch(DetailViewType);
    void userToViewProject();

private:
    Ui::ProjectDetails *ui;
    Project* project;
    bool isRegistered;
    QPushButton *btnRegister;

    void didSetProject();
    void updateUI();
};

#endif // PROJECTDETAILS_H
