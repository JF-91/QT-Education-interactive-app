#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "PdfViewerWidget.h"
#include "core/DocumentManager.h"

#include <QAction>
#include <QFileDialog>
#include <QFileInfo>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_documentManager(std::make_unique<DocumentManager>())
{
    ui->setupUi(this);
    setupUi();
    setupMenu();
}

void MainWindow::setupUi()
{
    setWindowTitle(tr("Interactive Educational Reader"));
    resize(1200, 800);

    m_pdfViewer = new PdfViewerWidget(ui->centralwidget);

    auto* layout = new QVBoxLayout(ui->centralwidget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(m_pdfViewer);
}

void MainWindow::setupMenu()
{
    QMenu* fileMenu = menuBar()->addMenu(tr("File"));

    QAction* openAction = fileMenu->addAction(tr("Open PDF..."));
    connect(openAction, &QAction::triggered, this, &MainWindow::openPdf);

    QAction* exitAction = fileMenu->addAction(tr("Exit"));
    connect(exitAction, &QAction::triggered, this, &QWidget::close);
}

void MainWindow::openPdf()
{
    const QString filePath = QFileDialog::getOpenFileName(
        this,
        "Open PDF",
        QString(),
        "PDF files (*.pdf)"
    );

    if (filePath.isEmpty()) {
        return;
    }

    const bool loaded = m_documentManager->loadDocument(filePath);

    if (!loaded) {
        QMessageBox::warning(
            this,
            "Error",
            "it ist not possible to open the PDF file."
        );
        return;
    }

    m_pdfViewer->setDocument(m_documentManager->document());

    const QString fileName = QFileInfo(filePath).fileName();
    setWindowTitle(tr("Interactive Educational Reader - %1").arg(fileName));
}

MainWindow::~MainWindow()
{
    delete ui;
}
