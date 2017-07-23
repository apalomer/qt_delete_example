#include <QtGui/QApplication>
#include "buttonstack.h"

int main(int argc, char** argv)
{

    QApplication app (argc, argv);
    ButtonStack bs;
    bs.show();
    return app.exec();
}
