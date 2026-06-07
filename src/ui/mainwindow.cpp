#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "PdfViewerWidget.h"
#include "../core/DocumentManager.h"

#include <QAction>
#include <QFileDialog>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_pdfViewer(new PdfViewerWidget(this))
    , m_documentManager(new DocumentManager())
{
    ui->setupUi(this);
    setupUi();
    setupMenu();
}

void MainWindow::setupUi()
{
    setWindowTitle("Interactive Educational Reader");
    resize(1200, 800);

    setCentralWidget(m_pdfViewer);
}

void MainWindow::setupMenu()
{
    QMenu* fileMenu = menuBar()->addMenu("File");

    QAction* openAction = fileMenu->addAction("Open PDF...");
    connect(openAction, &QAction::triggered, this, &MainWindow::openPdf);

    QAction* exitAction = fileMenu->addAction("Exit");
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
            "No se pudo abrir el archivo PDF."
        );
        return;
    }

    m_pdfViewer->setDocument(m_documentManager->document());
}

MainWindow::~MainWindow()
{
    delete ui;
}
