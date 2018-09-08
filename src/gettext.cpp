/*
 * Copyright 2012-2015 Canonical Ltd.
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
#include "gettext.h"

#include <QDebug>
#include <QDir>

#include <libintl.h>


namespace ergo
{

Gettext::Gettext(QObject *parent):
    QObject(parent)
{
    setlocale(LC_ALL, "");
}

QString Gettext::tr(const QString& text) const
{
    return QString::fromUtf8(gettext(text.toUtf8()));
}

QString Gettext::tr(const QString& singular,
                    const QString& plural,
                    int n) const
{
    return QString::fromUtf8(ngettext(singular.toUtf8(), plural.toUtf8(), n));
}

QString Gettext::domain() const
{
    return m_domain;
}

void Gettext::setDomain(const QString& domain)
{
    if (!m_domain.isEmpty()) {
        qWarning() << "Domain already set, not setting.";
        return;
    }
    m_domain = domain;

    textdomain(m_domain.toUtf8());

    /* Find the path */
    QString appDir = QString::fromLocal8Bit(getenv("APP_DIR"));
    QString localePath;

    if (appDir.isEmpty()) {
        appDir = QString::fromLocal8Bit(getenv("SNAP"));
    }

    if (!appDir.isEmpty() &&QDir::isAbsolutePath(appDir)) {
        localePath = QDir(appDir).filePath(QStringLiteral("share/locale"));
    } else {
        localePath = QStringLiteral("/usr/share/locale");
    }

    bindtextdomain(m_domain.toUtf8(), localePath.toUtf8());
}

} // namespace ergo
