#include "projectlistwidget.h"
#include "projectcellwidget.h"
#include "Models/cupidsession.h"
#include "Models/cupidsession.h"

ProjectListWidget::ProjectListWidget(QWidget *parent) :
    QScrollArea(parent)
{
    projectList = NULL;
    projectCells = NULL;
    items = NULL;

    viewWillAppear();
}
ProjectListWidget::~ProjectListWidget()
{
    cleanUpList();
    delete items;
}

void ProjectListWidget::viewWillAppear()
{
    setUpList();
}

void ProjectListWidget::viewWillDisappear()
{
    cleanUpList();
}

void ProjectListWidget::cleanUpList()
{
    if(projectList != NULL)
    {
        Project *currentProjectInSession = CupidSession::getInstance()->getCurrentProject();
        for(int i = 0; i < listSize; i++)
        {
            if(currentProjectInSession != NULL && projectList[i] != currentProjectInSession)
                delete projectList[i];
        }
        delete [] projectList;
        projectList = NULL;
    }

    if(projectCells != NULL)
    {
        for(int i = 0; i < listSize; i++)
        {
            items->layout()->removeWidget(projectCells[i]);
            delete projectCells[i];
        }
        delete [] projectCells;
        projectCells = NULL;
    }

}

void ProjectListWidget::setUpList()
{
    /* Clean up first */
    cleanUpList();

    //TODO: Query DB here!!!



    //Debugger
    listSize = 20;
    projectList = new Project*[listSize];
    QString c = "Project Title";
    QString d = "This is the project description, i'm just adding content so it will look better. Description Description Description Description Description Description Description Description Description Description";

    for(int i=0; i<listSize; i++)
    {
       projectList[i] = new Project(c, d);
    }

    displayList();
}

void ProjectListWidget::displayList()
{
    /*
     * creates a widget with all of the projects in it as projectCellWidgets
     */
    if (projectList != NULL)
    {
        projectCells = new ProjectCellWidget*[listSize];
        if(items == NULL)
        {
            items = new QWidget;
            items->setLayout(new QVBoxLayout);
            this->setWidget(items);
            this->setLayout(new QHBoxLayout);
        }
        setWidgetResizable(true); //need this so the vertical scroll bar appears

        for(int i=0; i<listSize; i++)
        {
            ProjectCellWidget *cell = new ProjectCellWidget();
            cell->index = i;
            cell->getUi().lblTitle->setText(projectList[i]->getTitle());
            cell->getUi().lblDescription->setText(projectList[i]->getDescription());
            cell->getUi().lblNumRegistered->setText(QString::number(5) + " Students Registered");
            QObject::connect(cell, SIGNAL(cellSelected(int)), this, SLOT(viewProjectSelected(int)));

            projectCells[i] = cell;
            items->layout()->addWidget(cell);
        }

    }

}

void ProjectListWidget::viewProjectSelected(int index)
{
    CupidSession::getInstance()->deleteCurrentProject();
    CupidSession::getInstance()->setCurrentProject(projectList[index]);
    emit userToViewProject();
    viewWillDisappear();
}

void ProjectListWidget::handleUserContextSwitch(DetailViewType type)
{
    if (type == DiscoverProjets)
    {
        //entering view
        viewWillAppear();
    }
    else
    {
        //Leaving view
        viewWillDisappear();
    }
}
