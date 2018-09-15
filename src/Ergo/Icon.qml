/*
 * Copyright 2015 Canonical Ltd.
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

import Ergo 0.0
import QtQuick 2.7

Item {
    id: iconRoot

    property string name

    property alias source: iconImage.source
    property alias color: colorMask.colorOut
    property alias keyColor: colorMask.colorIn

    Image {
        id: iconImage
        objectName: "iconMask"
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit

        cache: true
        asynchronous: true
        visible: !colorMask.visible

        sourceSize.width: width
        sourceSize.height: height

        source: iconRoot.name ? "image://theme/%1".arg(iconRoot.name) : ""
    }

    ShaderEffect {
        id: colorMask
        objectName: "colorMask"

        anchors.centerIn: parent
        width: iconImage.paintedWidth
        height: iconImage.paintedHeight

        // Whether or not a color has been set.
        visible: iconImage.status == Image.Ready && colorOut != Qt.rgba(0.0, 0.0, 0.0, 0.0)

        property Image source: iconImage
        property color colorOut: Qt.rgba(0.0, 0.0, 0.0, 0.0)
        property color colorIn: "#808080"
        property real threshold: 0.1

        fragmentShader: "
            varying highp vec2 qt_TexCoord0;
            uniform sampler2D source;
            uniform highp vec4 colorOut;
            uniform highp vec4 colorIn;
            uniform lowp float threshold;
            uniform lowp float qt_Opacity;
            void main() {
                lowp vec4 sourceColor = texture2D(source, qt_TexCoord0);
                gl_FragColor = mix(
                    colorOut * vec4(sourceColor.a),
                    sourceColor,
                    step(threshold, distance(
                        sourceColor.rgb / sourceColor.a,
                        colorIn.rgb))
                ) * qt_Opacity;
            }"
    }
}
