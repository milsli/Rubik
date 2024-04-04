// Copyright (C) 2023 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick3D
import QtQuick3D.Helpers
import RubikSideModule

ApplicationWindow {
    id: window
    width: 1280
    height: 720
    visible: true
    title: qsTr("Rubik World")

    View3D {
        id: v3d
        anchors.left:  parent.left
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        camera: camera

        environment: SceneEnvironment {
            id: env
            backgroundMode: SceneEnvironment.Color
            clearColor: "#d0d1d0"
        }

        Node {
            id: originNode
            PerspectiveCamera {
                id: cameraNode
                z: 600
            }
        }

         DirectionalLight {
             id: directionalLight
             color: Qt.rgba(0.8, 0.2, 0.1, 1.0)
         //     ambientColor: Qt.rgba(0.1, 0.1, 0.1, 1.0)
         }

        // PointLight {
        //     id: pointLight
        //     position: Qt.vector3d(0, 0, 100)
        //     color: Qt.rgba(0.1, 1.0, 0.1, 1.0)
        //     ambientColor: Qt.rgba(0.2, 0.2, 0.2, 1.0)
        // }

        Model {
            id: gridModel
            visible: true
            scale: Qt.vector3d(150, 150, 150)

            geometry: RubikSide {
                id: rubicSide

                uv: true
                uvAdjust: 1
            }

            materials: [
                DefaultMaterial {
                    Texture {
                        id: baseColorMap
                        source: "qt_logo.png"
                    }
                    cullMode: DefaultMaterial.NoCulling
                    diffuseMap: null
                    specularAmount: 0.5
                    //diffuseColor: "#a02020"
                }

            ]
        }

        OrbitCameraController {
            origin: originNode
            camera: cameraNode
        }

    }




































}

