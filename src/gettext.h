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

#pragma once

#include <QObject>

namespace ergo
{

    class Gettext: public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString domain
                   READ domain
                   WRITE setDomain)

      public:
        explicit Gettext(QObject *parent = 0);

        Q_INVOKABLE QString tr(const QString& text) const;
        Q_INVOKABLE QString tr(const QString& singular,
                               const QString& plural,
                               int n) const;

        QString domain() const;
        void setDomain(const QString& domain);

      private:
        Q_DISABLE_COPY(Gettext);

        QString m_domain;
    };

} // namespace ergo
