//
// Created by sircraft-gaming on 6/6/26.
//

#include "DocumentManager.h"
#include <QPdfDocument>

DocumentManager::DocumentManager(): m_document(std::make_unique<QPdfDocument>())
{
}

bool DocumentManager::loadDocument(const QString& fileName)
{
    return m_document->load(fileName) == QPdfDocument::Error::None;
}

QPdfDocument* DocumentManager::document()
{
    return m_document.get();
}

int DocumentManager::pageCount() const
{
    return m_document->pageCount();
}

bool DocumentManager::hasDocument() const
{
    return m_document->pageCount() > 0;
}




