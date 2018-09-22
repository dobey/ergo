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

  /*! Utilities for handling units of screen measurement
   *
   * Units provides provides device-independent pixel size calculations, to
   * aid in the development of application interfaces which scale correctly
   * across a wide range of screen configurations.
   *
   * The Units class is not instantiable within an application directly, but
   * must be used through the singleton `units` context property.
   *
   * \code
   * import QtQuick 2.7
   * import QtQuick.Controls 2.2
   * import Ergo 0.0
   *
   * Page {
   *     width: units.dp(640)
   *     height: units.dp(480)
   * }
   * \endcode
   *
   */
    class Units: public QObject
    {
        Q_OBJECT

      public:
        //! @cond
        explicit Units(QObject *parent = 0);
        //! @endcond

        Q_INVOKABLE int dp(double value) const;
    };

} // namespace ergo
