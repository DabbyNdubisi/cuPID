#ifndef PROFILEWIDGET_H
#define PROFILEWIDGET_H

#include "cupidslider.h"
#include "ui_profilewidget.h"
#include "sidebarwidget.h"
#include "codingwidget.h"

//  Subsystem dependencies
#include "DataAccessLayer/projectpartnerprofile.h"

#include <QWidget>


namespace Ui {
class ProfileWidget;
}

class ProfileWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileWidget(QWidget *parent = 0);
    ~ProfileWidget();

    Ui::ProfileWidget& getUI();

    /*!
     *       @param: none
     *        @desc: all setup that needs to be done
     *               before this object appears on screen to the user.
     *      @return: void
     */
    void viewWillAppear();

    /*!
     *       @param: none
     *        @desc: all cleanup that needs to be done before
     *               this view leaves the screen
     *      @return: void
     */
    void viewWillDisappear();

    /*
     * All of the custom sliders required for User Coding and technical knowledge
     */
    CupidSlider* sliderUserOO;
    CupidSlider* sliderUserUI;
    CupidSlider* sliderUserScripting;
    CupidSlider* sliderUserDB;
    CupidSlider* sliderUserDesignPatterns;
    CupidSlider* sliderUserDataStructures;
    CupidSlider* sliderUserComputerSecurity;
    CupidSlider* sliderUserSoftwareDocumentation;
    CupidSlider* sliderUserNetworkComputing;
    CupidSlider* sliderUserVersionControl;
    CupidSlider* sliderUserWebDevelopment;

    /*
     * All of the custom sliders required for Teammate Coding and technical knowledge
     */
    CupidSlider* sliderTeammateOO;
    CupidSlider* sliderTeammateUI;
    CupidSlider* sliderTeammateScripting;
    CupidSlider* sliderTeammateDB;
    CupidSlider* sliderTeammateDesignPatterns;
    CupidSlider* sliderTeammateDataStructures;
    CupidSlider* sliderTeammateComputerSecurity;
    CupidSlider* sliderTeammateSoftwareDocumentation;
    CupidSlider* sliderTeammateNetworkComputing;
    CupidSlider* sliderTeammateVersionControl;
    CupidSlider* sliderTeammateWebDevelopment;

    int numBoxSelected;

    CodingWidget codingWidget;

    void enableDisableCheckBoxes();
    void setUpDefault();

    /*!
     *  @param: none
     *   @desc: checks to see if all work ethics are selected
     * @return: bool
    */
    bool checkWorkEthicSelected();

    /*!
     *  @param: none
     *   @desc: after successful save, the checkboxes are locked
     * @return: none
    */
    void lockWorkEthicCheckboxes();

    /*!
     *  @param: none
     *   @desc: check if the UI elements of the personal profile form has been filled in
     * @return: bool
    */
    bool checkPersonalSectionCompleted();

    /*!
     *  @param: none
     *   @desc: check if the UI elements of the teammate profile form has been filled in
     * @return: bool
    */
    bool checkTeammateSectionCompleted();

signals:
    void userToEditPPP();
    void userToSavePPP();
    void userToCreatePPP();
    void userToLeavePPP();
    void userToViewPPP();
    void userToSubmitCodingQuestion();

private:
    void didSetProfile();

private slots:

    void on_btnSave_clicked();

    void on_btnEditPPP_clicked();

    void on_btnCreatePPP_clicked();

    void on_chkHardworking_clicked();

    void on_chkFlexible_clicked();

    void on_chkImpulsive_clicked();

    void on_chkHumour_clicked();

    void on_chkEfficient_clicked();

    void on_chkProactive_clicked();

    void on_chkOrganized_clicked();

    void on_chkDependable_clicked();

    void handleUserContextSwitch(DetailViewType);

    void on_btnSaveCoding_clicked();

private:
    Ui::ProfileWidget *ui;

};

#endif // PROFILEWIDGET_H
