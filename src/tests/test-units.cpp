/*
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

#include <QtTest/QtTest>

class TestUnits: public QObject
{
    Q_OBJECT

  private slots:
    void dp_data();
    void gu_data();

    void dp();
    void gu();
};


void TestUnits::dp_data()
{
    QTest::addColumn<double>("input");
    QTest::addColumn<double>("dpi");
    QTest::addColumn<int>("expected");

    QTest::newRow("dp standard resolution") << 20.0 << 160.0 << 20;
    QTest::newRow("normal pc resolution") << 10.0 << 120.0 << 8;
    QTest::newRow("high resolution screen") << 100.0 << 320.0 << 200;
}

void TestUnits::dp()
{
    QEXPECT_FAIL("", "Need to mock DPI query.", Continue);
    QFETCH(double, input);
    QFETCH(int, expected);

    auto units = new ergo::Units(parent());
    QCOMPARE(units->dp(input), expected);
}

void TestUnits::gu_data()
{
    QTest::addColumn<double>("grid_unit_px");
    QTest::addColumn<double>("input");
    QTest::addColumn<int>("expected");

    QTest::newRow("default") << 8.0 << 8.0 << 64;
    QTest::newRow("average") << 12.0 << 10.0 << 120;
    QTest::newRow("high dpi") << 23.0 << 2.5 << 58;
}

void TestUnits::gu()
{
    QFETCH(double, grid_unit_px);
    QFETCH(double, input);
    QFETCH(int, expected);

    qputenv(ergo::Units::GRID_UNIT_PX_ENV, QByteArray().setNum(grid_unit_px));
    auto units = new ergo::Units(parent());
    QCOMPARE(units->gu(input), expected);
    qunsetenv(ergo::Units::GRID_UNIT_PX_ENV);
}


QTEST_MAIN(TestUnits)
#include "test-units.moc"
