#include "cupidwindow.h"

// Subsystem dependencies
#include "UserAuthentication/loginform.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
<<<<<<< Updated upstream
=======
    QFile file("../cuPID/Stylesheets/style.qss");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        a.setStyleSheet(file.readAll());
        file.close();
    }
>>>>>>> Stashed changes

    LoginForm cuPIDLoginForm;
    cuPIDWindow cuPIDWindow;

    //connect login dialog with main cuPID window
    QObject::connect(&cuPIDLoginForm, SIGNAL(loginAccepted()),
                     &cuPIDWindow, SLOT(acceptUserLogin()));
    QObject::connect(&cuPIDWindow, SIGNAL(userLoggedOut()),
                     &cuPIDLoginForm, SLOT(promptUserLogin()));

    cuPIDLoginForm.show();

    return a.exec();
}
