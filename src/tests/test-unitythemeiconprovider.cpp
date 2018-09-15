/*
 * Copyright 2015 Canonical Ltd.
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

#include <unitythemeiconprovider.h>

#include <QtTest>

class TestIconProvider : public QObject
{
    Q_OBJECT
public:
    TestIconProvider() {}

private Q_SLOTS:

    void initTestCase()
    {
        qputenv("XDG_DATA_DIRS", CMAKE_CURRENT_SOURCE_DIR);
    }

    void test_loadIcon_data()
    {
        QTest::addColumn<QString>("icon");
        QTest::addColumn<QSize>("requestSize");
        QTest::addColumn<QSize>("resultSize");

        QTest::newRow("battery0") << "battery-100-charging" << QSize(-1, -1) << QSize(256, 166);
        QTest::newRow("battery1") << "battery-100-charging" << QSize(-1, 16) << QSize(25, 16);
        QTest::newRow("battery2") << "battery-100-charging" << QSize(16, -1) << QSize(16, 10);
        QTest::newRow("battery3") << "battery-100-charging" << QSize(0, 16) << QSize(25, 16);
        QTest::newRow("battery4") << "battery-100-charging" << QSize(16, 0) << QSize(16, 10);
        QTest::newRow("battery5") << "battery-100-charging" << QSize(24, 16) << QSize(24, 16);
        QTest::newRow("battery6") << "battery-100-charging" << QSize(24, 24) << QSize(24, 16);
        QTest::newRow("battery7") << "battery-100-charging" << QSize(37, 24) << QSize(37, 24);
        QTest::newRow("battery8") << "battery-100-charging" << QSize(15, 512) << QSize(15, 10);

        QTest::newRow("gallery0") << "gallery-app" << QSize(-1, -1) << QSize(512, 512);
        QTest::newRow("gallery1") << "gallery-app" << QSize(-1, 16) << QSize(16, 16);
        QTest::newRow("gallery2") << "gallery-app" << QSize(16, -1) << QSize(16, 16);
        QTest::newRow("gallery3") << "gallery-app" << QSize(0, 16) << QSize(16, 16);
        QTest::newRow("gallery4") << "gallery-app" << QSize(16, 0) << QSize(16, 16);
        QTest::newRow("gallery5") << "gallery-app" << QSize(24, 16) << QSize(16, 16);
        QTest::newRow("gallery6") << "gallery-app" << QSize(24, 24) << QSize(24, 24);
    }

    void test_loadIcon()
    {
        QFETCH(QString, icon);
        QFETCH(QSize, requestSize);
        QFETCH(QSize, resultSize);

        unity::ThemeIconProvider provider("mockTheme");
        QSize returnedSize;
        QImage i = provider.requestImage(icon, &returnedSize, requestSize);
        QCOMPARE(i.size(), resultSize);
        QCOMPARE(returnedSize, resultSize);

        // Search again to make sure subsequent searches still work
        i = provider.requestImage(icon, &returnedSize, requestSize);
        QCOMPARE(i.size(), resultSize);
        QCOMPARE(returnedSize, resultSize);
    }

    void test_hicolorLast()
    {
        QSize returnedSize;
        unity::ThemeIconProvider provider("mockTheme");

        // myapp is in MockTheme3 (white) and hicolor (black)
        // MockTheme3 one is returned since hicolor is last per spec
        QImage i = provider.requestImage("myapp", &returnedSize, QSize(-1, -1));
        QVERIFY(!i.isNull());
        QCOMPARE(QColor(i.pixel(0,0)), QColor(Qt::white));

        // myapp2 is only in hicolor (black) so that's the one returned
        i = provider.requestImage("myapp2", &returnedSize, QSize(-1, -1));
        QVERIFY(!i.isNull());
        QCOMPARE(QColor(i.pixel(0,0)), QColor(Qt::black));
    }
};

QTEST_MAIN(TestIconProvider)

#include "test-unitythemeiconprovider.moc"
