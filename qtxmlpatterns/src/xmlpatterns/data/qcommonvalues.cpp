/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtXmlPatterns module of the Qt Toolkit.
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

// CHANGES SCHLEUNIGER AG, April 2015 :: START [add "#define _CRT_BANNED_DEPRECATE( x )" in files to resolve wince sdk compiler errors]
#define _CRT_BANNED_DEPRECATE( x )
// CHANGES SCHLEUNIGER AG, April 2015 :: END

#include <limits>

#include "qabstractfloat_p.h"
#include "qanyuri_p.h"
#include "qboolean_p.h"
#include "qdecimal_p.h"
#include "qinteger_p.h"
#include "qatomicstring_p.h"
#include "quntypedatomic_p.h"

#include "qcommonvalues_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

// STATIC DATA
const AtomicString::Ptr               CommonValues::EmptyString
                                    (new AtomicString(QLatin1String("")));
const AtomicString::Ptr               CommonValues::TrueString
                                    (new AtomicString(QLatin1String("true")));
const AtomicString::Ptr               CommonValues::FalseString
                                    (new AtomicString(QLatin1String("false")));

const UntypedAtomic::Ptr        CommonValues::UntypedAtomicTrue
                                    (new UntypedAtomic(QLatin1String("true")));
const UntypedAtomic::Ptr        CommonValues::UntypedAtomicFalse
                                    (new UntypedAtomic(QLatin1String("false")));

const AtomicValue::Ptr              CommonValues::BooleanTrue
                                    (new Boolean(true));
const AtomicValue::Ptr              CommonValues::BooleanFalse(new Boolean(false));

const AtomicValue::Ptr               CommonValues::DoubleNaN
                                    (Double::fromValue(std::numeric_limits<xsDouble>::quiet_NaN()));

const AtomicValue::Ptr                CommonValues::FloatNaN
                                    (Float::fromValue(std::numeric_limits<xsFloat>::quiet_NaN()));

const Item                          CommonValues::IntegerZero
                                    (Integer::fromValue(0));

const AtomicValue::Ptr               CommonValues::EmptyAnyURI
                                    (AnyURI::fromValue(QLatin1String("")));

const AtomicValue::Ptr               CommonValues::DoubleOne
                                    (Double::fromValue(1));
const AtomicValue::Ptr                CommonValues::FloatOne
                                    (Float::fromValue(1));
const AtomicValue::Ptr              CommonValues::DecimalOne
                                    (Decimal::fromValue(1));
const Item                          CommonValues::IntegerOne
                                    (Integer::fromValue(1));
const Item                          CommonValues::IntegerOneNegative
                                    (Integer::fromValue(-1));

const AtomicValue::Ptr               CommonValues::DoubleZero
                                    (Double::fromValue(0));
const AtomicValue::Ptr                CommonValues::FloatZero
                                    (Float::fromValue(0));
const AtomicValue::Ptr              CommonValues::DecimalZero
                                    (Decimal::fromValue(0));

const Item::EmptyIterator::Ptr  CommonValues::emptyIterator
                                    (new Item::EmptyIterator());

const AtomicValue::Ptr               CommonValues::NegativeInfDouble
                                    (Double::fromValue(-std::numeric_limits<xsDouble>::infinity()));
const AtomicValue::Ptr               CommonValues::InfDouble
                                    (Double::fromValue(std::numeric_limits<xsDouble>::infinity()));
const AtomicValue::Ptr                CommonValues::NegativeInfFloat
                                    (Float::fromValue(-std::numeric_limits<xsFloat>::infinity()));
const AtomicValue::Ptr                CommonValues::InfFloat
                                    (Float::fromValue(std::numeric_limits<xsFloat>::infinity()));

const DayTimeDuration::Ptr      CommonValues::DayTimeDurationZero
                                    (DayTimeDuration::fromSeconds(0));
const DayTimeDuration::Ptr      CommonValues::YearMonthDurationZero
                                    (YearMonthDuration::fromComponents(true, 0, 0));


QT_END_NAMESPACE
