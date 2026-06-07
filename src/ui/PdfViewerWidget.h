//
// Created by sircraft-gaming on 6/6/26.
//
#pragma once

#ifndef TABMENU_PDFVIEWERWIDGET_H
#define TABMENU_PDFVIEWERWIDGET_H

#include <QWidget>

class QPdfDocument;
class QPdfView;

class PdfViewerWidget: public QWidget
{
    Q_OBJECT
public:
    explicit PdfViewerWidget(QWidget* parent = nullptr);

    void setDocument(QPdfDocument* document);

private:
    QPdfView* m_pdfView;
};


#endif //TABMENU_PDFVIEWERWIDGET_H
