#include "sidebarwidget.h"

SideBarWidget::SideBarWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SideBarWidget)
{
    ui->setupUi(this);


    viewWillAppear();

}

SideBarWidget::~SideBarWidget()
{
    delete ui;
}

void SideBarWidget::viewWillAppear()
{

}

Ui::SideBarWidget* SideBarWidget::getUI()
{
    return ui;
}


void SideBarWidget::on_btnProfile_clicked()
{
    emit profileClicked();
}

void SideBarWidget::on_btnSettings_clicked()
{
    emit settingsClicked();
}

void SideBarWidget::on_btnLogOut_clicked()
{
    emit logOutClicked();
}