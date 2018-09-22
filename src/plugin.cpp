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
#include "gettext.h"
#include "units.h"

// TODO: Replace this with seemless theme implementation
#include "unitythemeiconprovider.h"

#include <QQmlContext>
#include <QQmlEngine>
#include <QQmlExtensionPlugin>
#include <QVariant>

class ErgoPlugin: public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

    public:
    explicit ErgoPlugin(QObject *parent=0):
        QQmlExtensionPlugin(parent)
    {
        setlocale(LC_ALL, "");
    }

    void initializeEngine(QQmlEngine *engine, const char *uri) override
    {
        // FIXME: Need a better way to do this.
        static auto provider = new unity::ThemeIconProvider();
        engine->addImageProvider(QLatin1String("theme"), provider);

        static auto i18n = new ergo::Gettext(engine);
        static auto units = new ergo::Units(engine);

        auto context = engine->rootContext();
        context->setContextProperty(QStringLiteral("i18n"), i18n);
        context->setContextProperty(QStringLiteral("units"), units);
    }

    void registerTypes(const char *uri) override
    {
        qmlRegisterType<ergo::Clipboard>(uri, 0, 0, "Clipboard");
        qmlRegisterType<ergo::Gettext>(uri, 0, 0, "Gettext");
    }
};

#include "plugin.moc"
