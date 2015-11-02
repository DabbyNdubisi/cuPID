#include "user.h"

User::User(QString& firstName, QString& lastName, QString& userName, int id)
{
  this->firstName = firstName;
  this->lastName = lastName;
  this->userName = userName;
  this->id = id;
}

User::~User()
{

}

QString& User::getFirstName()
{
  return firstName;
}

QString& User::getLastName()
{
  return lastName;
}

QString& User::getUserName()
{
  return userName;
}

void User::setFirstName(QString& newFirstName)
{
  firstName = newFirstName;
}

void User::setLastName(QString& newLastName)
{
  lastName = newLastName;
}

void User::setUserName(QString& newUserName)
{
  userName = newUserName;
}

void User::setUserId(int newID)
{
    id = newID;
}

int User::getUserId()
{
    return id;
}

UserType User::getUserType()
{
    return userType;
}

void User::setUserType(UserType t)
{
    userType = t;
}

int User::getNumberOfProjectsAssociated()
{
    return myProjects.size();
}

void User::addProjectToUser(Project* project)
{
    myProjects.append(project);
}


void User::removeProjectFromUser(Project* project)
{
    int index = myProjects.indexOf(project);

    if (index != -1)
    {
        myProjects.remove(index);
    }
}

QVector<Project *>& User::getProjectsAssociated(){
    return myProjects;
}

bool User::containsProject(Project *project)
{
    // Instead of checking contains, we should check if the project IDs are the same.
    // Same project may be malloc'd by project list and User's projects
    int i;
    for(i=0;i<myProjects.size();++i)
    {
        if(myProjects.value(i)->getProjectId() == project->getProjectId())
        {
            return true;
        }
    }
}
