#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class PdfViewerWidget;
class DocumentManager;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    void setupUi();
    void setupMenu();
    void openPdf();

    Ui::MainWindow *ui;

    PdfViewerWidget* m_pdfViewer;
    std::unique_ptr<DocumentManager> m_documentManager;
};
#endif // MAINWINDOW_H
