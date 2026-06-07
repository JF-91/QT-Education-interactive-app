#include "ui/mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QString>

static QString loadQss(const QString &path)
{
    QFile file(path);
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        return QString::fromUtf8(file.readAll());
    }
    return {};
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setStyleSheet(
        loadQss(":/style/global.qss")
        + loadQss(":/style/buttons.qss")
        + loadQss(":/style/inputs.qss")
        + loadQss(":/style/tabs.qss")
    );

    MainWindow w;
    w.show();
    return a.exec();
}
