#include "studentuser.h"
#include "projectpartnerprofile.h"
#include "project.h"

StudentUser::StudentUser(QString& fName, QString& lName, QString& userName):
    User(fName, lName, userName)
{
    profile = NULL;
    userType = Student;
    pppIDForFetch = 0;
}

StudentUser::~StudentUser()
{
    if(profile != NULL)
    {
        delete profile;
        profile = NULL;
    }
}

void StudentUser::setFetchIDForPPP(int fetchID)
{
    pppIDForFetch = fetchID;
}

int StudentUser::getFetchIDForPPP()
{
    return pppIDForFetch;
}

ProjectPartnerProfile* StudentUser::getProfile()
{
    if(profile == NULL)
    {
        return NULL;
    }
    return profile;
}
