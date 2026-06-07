//
// Created by sircraft-gaming on 6/6/26.
//

#include "PdfViewerWidget.h"

#include <QPdfView>
#include <QVBoxLayout>

PdfViewerWidget::PdfViewerWidget(QWidget* parent)
    : QWidget(parent), m_pdfView(new QPdfView(this))
{
    auto* layout = new QVBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(m_pdfView);

    setLayout(layout);
}

void PdfViewerWidget::setDocument(QPdfDocument* document)
{
    m_pdfView->setDocument(document);
}