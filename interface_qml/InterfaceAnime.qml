import Qt 4.7
import Qt.labs.particles 1.0

Item {
    id: interfc
    width: 640; height: 480

    // Let's draw the sky...
    Rectangle {
		Text { text : con; x:20; y:20}
        anchors { left: parent.left; top: parent.top; right: parent.right; bottom: parent.verticalCenter }
        gradient: Gradient {
            GradientStop {
                position: 0.0
                SequentialAnimation on color {
                    loops: Animation.Infinite
                    ColorAnimation { from: "DeepSkyBlue"; to: "#0E1533"; duration: 50000 }
                    ColorAnimation { from: "#0E1533"; to: "DeepSkyBlue"; duration: 50000 }
                }
            }
            GradientStop {
                position: 1.0
                SequentialAnimation on color {
                    loops: Animation.Infinite
                    ColorAnimation { from: "SkyBlue"; to: "#437284"; duration: 50000 }
                    ColorAnimation { from: "#437284"; to: "SkyBlue"; duration: 50000 }
                }
            }
        }	
    }

    // the sun, moon, and stars
    Item {
        width: parent.width; height: 2 * parent.height
        NumberAnimation on rotation { from: 0; to: 360; duration: 100000; loops: Animation.Infinite }
        Image {
            source: "ressources/sun.png"; y: 10; anchors.horizontalCenter: parent.horizontalCenter
            rotation: -3 * parent.rotation
        }
        Image {
            source: "ressources/moon.png"; y: parent.height - 74; anchors.horizontalCenter: parent.horizontalCenter
            rotation: -parent.rotation
        }
        Particles {
            x: 0; y: parent.height/2; width: parent.width; height: parent.height/2
            source: "ressources/star.png"; angleDeviation: 360; velocity: 0
            velocityDeviation: 0; count: parent.width / 10; fadeInDuration: 2800
            SequentialAnimation on opacity {
                loops: Animation.Infinite
                NumberAnimation { from: 0; to: 1; duration: 50000 }
                NumberAnimation { from: 1; to: 0; duration: 50000 }
            }
        }
    }

    // ...and the ground.
    Rectangle {
        anchors { left: parent.left; top: parent.verticalCenter; right: parent.right; bottom: parent.bottom }
        gradient: Gradient {
            GradientStop {
                position: 0.0
                SequentialAnimation on color {
                    loops: Animation.Infinite
                    ColorAnimation { from: "ForestGreen"; to: "#001600"; duration: 50000 }
                    ColorAnimation { from: "#001600"; to: "ForestGreen"; duration: 50000 }
                }
            }
            GradientStop { position: 1.0; color: "DarkGreen" }
        }
    }
	Item{
		// x:-400; y:-50;
		PropertyAnimation on x {to:600; duration:100000; loops:Animation.Infinite}
	Item{
		durePassage: int
		SequentialAnimation on y{
		loops:Animation.Infinite
		NumberAnimation {from:10; to:0; duration:900}
		NumberAnimation {from:0; to:10; duration:900}
		}
		Image {
			source: "ressources/CL05.png"; x:50 
		}
	}
	}
	Item{
		PropertyAnimation on y {to:10; duration:10000; loops:Animation.Infinite}
	Image {
			source: "ressources/loveballoons.png"; y:1000; x:100
		}
		}
}
