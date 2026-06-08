//
// Created by sircraft-gaming on 6/6/26.
//

#ifndef EDUCATIONINTERACTIVEAPP_PDFVIEWERWIDGET_H
#define EDUCATIONINTERACTIVEAPP_PDFVIEWERWIDGET_H

#include <QFileDialog>
#include <QWidget>

class QPdfDocument;
class QPdfView;

class PdfViewerWidget: public QWidget
{
    Q_OBJECT
public:
    explicit PdfViewerWidget(QWidget* parent = nullptr);

    void setDocument(QPdfDocument* document);

private slots:
    void previousPage();
    void nextPage();
    void updateNavigationButtons();
private:
    void goToPage(int page);
    
    QPdfView* m_pdfView;
    QPushButton* m_previousButton;
    QPushButton* m_nextButton;

    int m_currentPage;
};


#endif // EDUCATIONINTERACTIVEAPP_PDFVIEWERWIDGET_H
