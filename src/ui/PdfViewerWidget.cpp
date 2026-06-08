//
// Created by sircraft-gaming on 6/6/26.
//

#include "PdfViewerWidget.h"

#include <QPdfView>
#include <QVBoxLayout>
#include  <QPushButton>
#include <QHBoxLayout>
#include <QPdfDocument>
#include <QPdfPageNavigator>

PdfViewerWidget::PdfViewerWidget(QWidget* parent)
    : QWidget(parent)
    , m_pdfView(new QPdfView(this))
    , m_previousButton(new QPushButton("previous", this))
    , m_nextButton(new QPushButton("next", this))
    , m_currentPage(0)
{
    auto* controlsLayout = new QHBoxLayout;
    controlsLayout->addWidget(m_previousButton);
    controlsLayout->addWidget(m_nextButton);
    controlsLayout->addStretch();

    auto* layout = new QVBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->addLayout(controlsLayout);
    layout->addWidget(m_pdfView);

    connect(m_previousButton, &QPushButton::clicked, this, &PdfViewerWidget::previousPage);
    connect(m_nextButton, &QPushButton::clicked, this, &PdfViewerWidget::nextPage);

    QPdfPageNavigator* navigator = m_pdfView->pageNavigator();
    if (navigator)
    {
        connect(navigator, &QPdfPageNavigator::currentPageChanged,
                this, &PdfViewerWidget::updateNavigationButtons);
    }

    updateNavigationButtons();
    setLayout(layout);
}

void PdfViewerWidget::setDocument(QPdfDocument* document)
{
    m_pdfView->setDocument(document);

    if (QPdfPageNavigator* navigator = m_pdfView->pageNavigator())
    {
        navigator->clear();
        if (document && document->pageCount() > 0)
        {
            navigator->jump(0, QPointF(), 0);
        }
    }

    updateNavigationButtons();
}

void PdfViewerWidget::goToPage(int page)
{
    QPdfDocument* document = m_pdfView->document();
    if (!document)
    {
        return;
    }

    const int pageCount = document->pageCount();
    if (pageCount <= 0 || page < 0 || page >= pageCount)
    {
        return;
    }

    QPdfPageNavigator* navigator = m_pdfView->pageNavigator();
    if (!navigator)
    {
        return;
    }

    m_currentPage = page;
    navigator->jump(page, QPointF(), 0);
}

void PdfViewerWidget::previousPage()
{
    QPdfPageNavigator* navigator = m_pdfView->pageNavigator();
    if (!navigator)
    {
        return;
    }

    goToPage(navigator->currentPage() - 1 );
}

void PdfViewerWidget::nextPage()
{
    QPdfPageNavigator* navigator = m_pdfView->pageNavigator();
    if (!navigator)
    {
        return;
    }

    goToPage(navigator->currentPage() + 1 );
}

void PdfViewerWidget::updateNavigationButtons()
{
    QPdfDocument* document = m_pdfView->document();
    QPdfPageNavigator* navigator = m_pdfView->pageNavigator();

    if (!document || !navigator || document->pageCount() <= 0)
    {
        m_previousButton->setEnabled(false);
        m_nextButton->setEnabled(false);
        return;
    }

    const int currentPage = navigator->currentPage();
    const int lastPage = document->pageCount() - 1;

    m_previousButton->setEnabled(currentPage > 0);
    m_nextButton->setEnabled(currentPage < lastPage);
}