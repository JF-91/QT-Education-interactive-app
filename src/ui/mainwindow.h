#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class DocumentManager;
class PdfViewerWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    void setupUi();
    void setupMenu();

    Ui::MainWindow *ui;
    std::unique_ptr<DocumentManager> m_documentManager;
    PdfViewerWidget* m_pdfViewer = nullptr; // owned by Qt parent (centralwidget)

private slots:
    void openPdf();
};
#endif // MAINWINDOW_H
