//
// Created by sircraft-gaming on 6/6/26.
//

#pragma once

#ifndef TABMENU_DOCUMENTMANAGER_H
#define TABMENU_DOCUMENTMANAGER_H


#include <memory>
#include <QString>
#include <QPdfDocument>

class DocumentManager
{
public:
    DocumentManager();
    bool loadDocument(const QString& fileName);
    QPdfDocument* document();
    int pageCount() const;
    bool hasDocument() const;

private:
    std::unique_ptr<QPdfDocument> m_document;
};

#endif //TABMENU_DOCUMENTMANAGER_H
