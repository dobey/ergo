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

#pragma once

#include <QObject>

namespace ergo
{

    class Units: public QObject
    {
        Q_OBJECT

      public:
        explicit Units(QObject *parent = 0);

        Q_INVOKABLE int dp(float value);
        Q_INVOKABLE int gu(float value);

      private:
        float m_gridUnitPx;
    };

} // namespace ergo
