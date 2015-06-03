/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtDeclarative module of the Qt Toolkit.
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

#ifndef QDECLARATIVESTATEGROUP_H
#define QDECLARATIVESTATEGROUP_H

#include "private/qdeclarativestate_p.h"

QT_BEGIN_NAMESPACE

QT_MODULE(Declarative)

class QDeclarativeStateGroupPrivate;
class Q_DECLARATIVE_EXPORT QDeclarativeStateGroup : public QObject, public QDeclarativeParserStatus
{
    Q_OBJECT
    Q_INTERFACES(QDeclarativeParserStatus)
    Q_DECLARE_PRIVATE(QDeclarativeStateGroup)

    Q_PROPERTY(QString state READ state WRITE setState NOTIFY stateChanged)
    Q_PROPERTY(QDeclarativeListProperty<QDeclarativeState> states READ statesProperty DESIGNABLE false)
    Q_PROPERTY(QDeclarativeListProperty<QDeclarativeTransition> transitions READ transitionsProperty DESIGNABLE false)

public:
    QDeclarativeStateGroup(QObject * = 0);
    virtual ~QDeclarativeStateGroup();

    QString state() const;
    void setState(const QString &);

    QDeclarativeListProperty<QDeclarativeState> statesProperty();
    QList<QDeclarativeState *> states() const;

    QDeclarativeListProperty<QDeclarativeTransition> transitionsProperty();

    QDeclarativeState *findState(const QString &name) const;

    virtual void classBegin();
    virtual void componentComplete();
Q_SIGNALS:
    void stateChanged(const QString &);

private:
    friend class QDeclarativeState;
    bool updateAutoState();
    void removeState(QDeclarativeState *state);
};

QT_END_NAMESPACE

QML_DECLARE_TYPE(QDeclarativeStateGroup)

#endif // QDECLARATIVESTATEGROUP_H
