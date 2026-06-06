#include "ui/mainwindow.h"

#include <QApplication>
#include <QFile>

static QString loadQss(const QString &path)
{
    QFile file(path);
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        const QString content = file.readAll();
        file.close();
        return content;
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
    return QApplication::exec();
}
