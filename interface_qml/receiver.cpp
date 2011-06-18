/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the documentation of Qt. It was originally
** published as part of Qt Quarterly.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
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
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#include "receiver.h"
#include<QMessageBox>
Receiver::Receiver(const QXmlNamePool &namePool)
    : namePool(namePool)
{
}

void Receiver::attribute(const QXmlName &xmlname, const QStringRef &valueref)
{
    QString name = xmlname.localName(namePool);
    QString value = valueref.toString();
    QString currentElement = elements.top();

//    switch (currentElement) {
//    case "time" :  currentForecast.time[name] = value; break;
//    case "symbol" : currentForecast.symbol[name] = value;break;
//    case "windDirection" : currentForecast.windDirection[name] = value;break;
//    case "windSpeed" : currentForecast.windSpeed[name] = value;break;
//    case "sun" : sun[name] = value;
//        break;
//    }

    if (currentElement == "time")
        currentForecast.time[name] = value;
        else if (currentElement == "symbol")
        currentForecast.symbol[name] = value;
        else if (currentElement == "windDirection")
            currentForecast.windDirection[name] = value;
        else if (currentElement == "windSpeed")
            currentForecast.windSpeed[name] = value;
    else if (currentElement == "temperature")
        currentForecast.temperature[name] = value;
    else if (currentElement == "sun")
        sun[name] = value;
    }

void Receiver::characters(const QStringRef &value)
{
     nextUpdate = value.toString();
}
void Receiver::startElement(const QXmlName &xmlname)
{
    QString name = xmlname.localName(namePool);
    elements.push(name);

    if (name == "time")
        currentForecast = Forecast();
}

void Receiver::endElement()
{
    if (elements.pop() == "time")
        forecasts.append(currentForecast);
}

