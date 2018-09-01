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
#include "clipboard.h"

#include <QtTest/QtTest>
#include <QStringList>
#include <QVariant>


class TestClipboard: public QObject
{
    Q_OBJECT

  private slots:
    void pushData();
};


void TestClipboard::pushData()
{
    auto clipboard = new ergo::Clipboard(parent());
    clipboard->pushData("123456");
    clipboard->pushData(QVariant());
}


QTEST_MAIN(TestClipboard)
#include "test-clipboard.moc"
