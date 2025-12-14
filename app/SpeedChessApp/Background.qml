import QtQuick 2.0
import QtQuick.Particles 2.0

Rectangle {
    color: "black"

    ParticleSystem {
        id: particles
        running: true
    }

    ImageParticle {
        anchors.fill: parent
        system: particles
        source: Qt.resolvedUrl("icon/star.png")
        sizeTable: Qt.resolvedUrl("icon/sparkleSize.png")
        alpha: 0
        colorVariation: 0.6
    }

    Emitter {
        anchors.fill: parent
        system: particles
        emitRate: 2000
        lifeSpan: 2000
        size: 0.25
        sizeVariation: 0.25
    }
}
