/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef CONTENTTAB_H_
#define CONTENTTAB_H_

// EXTERNAL INCLUDES
#include <QDir>
#include <QUrl>
#include <QIcon>
#include <QFileInfo>
#include <QListWidget>
#include <QDesktopServices>
#include <QStandardPaths>

// INTERNAL INCLUDES

// FORWARD DECLARATIONS
QT_BEGIN_NAMESPACE
class QListWidgetItem;
QT_END_NAMESPACE

// CLASS DECLARATION

/**
* ContentTab class.
*
* This class implements general purpose tab for media files.
*/
class ContentTab : public QListWidget
{
    Q_OBJECT

public:         // Constructors & Destructors
    ContentTab(QWidget *parent);
    virtual ~ContentTab();

public:         // New Methods
    virtual void init(const QStandardPaths::StandardLocation &location,
                      const QString &filter,
                      const QString &icon);

protected:      // New Methods
    virtual void setContentDir(const QStandardPaths::StandardLocation &location);
    virtual void setIcon(const QString &icon);
    virtual void populateListWidget();
    virtual QString itemName(const QFileInfo &item);
    virtual QUrl itemUrl(QListWidgetItem *item);
    virtual void handleErrorInOpen(QListWidgetItem *item);
protected:
    void keyPressEvent(QKeyEvent *event);

public slots:   // New Slots
    virtual void openItem(QListWidgetItem *item);

protected:     // Owned variables
    QDir m_ContentDir;
    QIcon m_Icon;
};


#endif // CONTENTTAB_H_

// End of File
