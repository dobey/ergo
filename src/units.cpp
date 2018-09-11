/*
 * Copyright 2012-2016 Canonical Ltd.
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

#include "units.h"

#include <QGuiApplication>
#include <QScreen>


namespace ergo
{

Units::Units(QObject *parent):
    QObject(parent)
{
}


int Units::dp(double value) const
{
    auto screen = QGuiApplication::primaryScreen();
    // Based on 160 DPI as 1:1 to match Android
    return qRound(value * (screen->physicalDotsPerInch() / 160));
}

} // namespace ergo
