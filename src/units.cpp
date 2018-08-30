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

#include <QDebug>
#include <QGuiApplication>
#include <QScreen>

#define ENV_GRID_UNIT_PX "GRID_UNIT_PX"
#define DEFAULT_GRID_UNIT_PX 8

namespace ergo
{

/*
 * Read an environment variable value as a float
 */
static float getenvFloat(const char* name, float defaultValue)
{
    QByteArray stringValue = qgetenv(name);
    bool ok;
    float value = stringValue.toFloat(&ok);
    return ok ? value : defaultValue;
}


Units::Units(QObject *parent):
    QObject(parent)
{
    m_gridUnitPx = getenvFloat(ENV_GRID_UNIT_PX, DEFAULT_GRID_UNIT_PX);
}


int Units::dp(float value)
{
    auto screen = QGuiApplication::primaryScreen();
    // Based on 160 DPI as 1:1 to match Android
    return qRound(value * (screen->physicalDotsPerInch() / 160));
}


int Units::gu(float value)
{
    return qRound(value * m_gridUnitPx);
}

} // namespace ergo
