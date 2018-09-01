/*
 * Copyright 2012 Canonical Ltd.
 * Copyright 2018 Rodney Dawes
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "clipboard.h"

#include <QDebug>
#include <QGuiApplication>
#include <QMimeData>
#include <QMimeDatabase>


namespace ergo
{

Clipboard::Clipboard(QObject *parent):
    QObject(parent)
{
    m_clipboard = QGuiApplication::clipboard();
}


void Clipboard::pushData(const QVariant& data)
{
    if (!data.isValid()) {
        return;
    }

    QMimeDatabase mime;
    auto bytes = data.toByteArray();
    auto type = mime.mimeTypeForData(bytes);
    auto mimeData = new QMimeData;
    mimeData->setData(type.name(), bytes);
    m_clipboard->setMimeData(mimeData);
}

} // namespace ergo
