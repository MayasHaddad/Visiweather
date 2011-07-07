import Qt 4.7
import Qt.labs.particles 1.0

Item {
    id: interfc
        signal update()
    width: 640; height: 480
    // Let's draw the sky...
    Rectangle {
        anchors { left: parent.left; top: parent.top; right: parent.right; bottom: parent.verticalCenter }
        gradient: Gradient {
            GradientStop {
                position: 0.0
                SequentialAnimation on color {
                    loops: Animation.Infinite
                    ColorAnimation { from: "DeepSkyBlue"; to: "#0E1533"; duration: 500000 }
                    ColorAnimation { from: "#0E1533"; to: "DeepSkyBlue"; duration: 500000 }
                }
            }
            GradientStop {
                position: 1.0
                SequentialAnimation on color {
                    loops: Animation.Infinite
                    ColorAnimation { from: "SkyBlue"; to: "#437284"; duration: 500000 }
                    ColorAnimation { from: "#437284"; to: "SkyBlue"; duration: 500000 }
                }
            }
        }
    }

    // the sun, moon, and stars
    Item {
        width: parent.width; height: 2 * parent.height
                SequentialAnimation on rotation{
        running: true
        NumberAnimation  { from: interfce.getPositionCiel(); to: interfce.getPositionCiel()-180; duration: 5000000}
        NumberAnimation  { from: interfce.getPositionCiel()-180; to: interfce.getPositionCiel()-360; duration: 5000000}
                loops: Animation.Infinite
        }
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

        // BackGround Cloud

        Component{
        id:hugeCloud
        Item{

        width:interfc.width; height:interfc.height
        Image{
                x:-300;y:-150
                width:parent.width+700; height:parent.height+300
                source:"ressources/CL41.png"
        }
        }
        }

        Loader{id : hugeCloudLoader}

                Connections {
                        target: interfce
                        onCloudy :	hugeCloudLoader.sourceComponent=hugeCloud;
                        }

        // the clouds: onPartly cloudy
        Component{
        id:partlyCloudy
        Item
        {
        Item{
                width:parent.width;
                PropertyAnimation on y {from :interfce.depsury(); to:interfce.arvsury(); duration:1000000/interfce.getWindSpeed(); loops:Animation.Infinite}
                PropertyAnimation on x {from : interfce.depsurx(); to:interfce.arvsurx(); duration:1000000/interfce.getWindSpeed(); loops:Animation.Infinite}
                Image{
                PropertyAnimation on width {from :interfce.depsurz(); to:interfce.arvsurz(); duration:1000000/interfce.getWindSpeed(); loops:Animation.Infinite}
                PropertyAnimation on height {from :interfce.depsurz(); to:interfce.arvsurz(); duration:1000000/interfce.getWindSpeed(); loops:Animation.Infinite}
                        source: "ressources/CL15.png"; x: 20
        }
        }
        Item{
                width:parent.width;
                PropertyAnimation on y {from :interfce.depsury(); to:interfce.arvsury(); duration:1000000/interfce.getWindSpeed(); loops:Animation.Infinite}
                PropertyAnimation on x {from : interfce.depsurx(); to:interfce.arvsurx(); duration:1000000/interfce.getWindSpeed(); loops:Animation.Infinite}
                Image{
                PropertyAnimation on width {from :interfce.depsurz(); to:interfce.arvsurz(); duration:1000000/interfce.getWindSpeed(); loops:Animation.Infinite}
                PropertyAnimation on height {from :interfce.depsurz(); to:interfce.arvsurz(); duration:1000000/interfce.getWindSpeed(); loops:Animation.Infinite}
                        source: "ressources/CL06.png"; x: 20
        }
        }
        // Item{
                // width:parent.width;
                // PropertyAnimation on y {from :interfce.depsury(); to:interfce.arvsury(); duration:1000000/interfce.getWindSpeed(); loops:Animation.Infinite}
                // PropertyAnimation on x {from : interfce.depsurx(); to:interfce.arvsurx(); duration:1000000/interfce.getWindSpeed(); loops:Animation.Infinite}
                // Image{
                // PropertyAnimation on width {from :interfce.depsurz(); to:interfce.arvsurz(); duration:1000000/interfce.getWindSpeed(); loops:Animation.Infinite}
                // PropertyAnimation on height {from :interfce.depsurz(); to:interfce.arvsurz(); duration:1000000/interfce.getWindSpeed(); loops:Animation.Infinite}
                        // source: "ressources/CL13.png"; x: interfce.getRandomInteger(); y:interfce.getRandomInteger()
        // }
        // }
        // Item{
                // width:parent.width;
                // PropertyAnimation on y {from :interfce.depsury(); to:interfce.arvsury(); duration:1000000/interfce.getWindSpeed(); loops:Animation.Infinite}
                // PropertyAnimation on x {from : interfce.depsurx(); to:interfce.arvsurx(); duration:1000000/interfce.getWindSpeed(); loops:Animation.Infinite}
                // Image{
                // PropertyAnimation on width {from :interfce.depsurz(); to:interfce.arvsurz(); duration:1000000/interfce.getWindSpeed(); loops:Animation.Infinite}
                // PropertyAnimation on height {from :interfce.depsurz(); to:interfce.arvsurz(); duration:1000000/interfce.getWindSpeed(); loops:Animation.Infinite}
                        // source: "ressources/CL14.png"; x: interfce.getRandomInteger(); y:interfce.getRandomInteger()
        // }
        // }
        }
        }
        Loader{id:cloudiesLoader}
        Connections{
                target:interfce
                onPCloudy: cloudiesLoader.sourceComponent=partlyCloudy
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

        // The rain
        Component{
                id:rain
        Particles {
                        id:rainP
            x: 0; y: 0; width: interfc.width; height: interfc.height
            source: "ressources/rain.png"; velocity: 40
            velocityDeviation: 0; count: interfce.getFrequence(); fadeInDuration: 3000; emissionRate:4000
                        ParticleMotionGravity {
             yattractor: 1000
             xattractor: 0
             acceleration: 25
         }
        }
                }

                Loader{id : rainLoader}

                // Connections {
                        // target: interfce
                        // onDestroyAll :	rainP.destroy();
                        // }

                Connections {
                        target: interfce
                        onRain : rainLoader.sourceComponent=rain
                }

        // The snow
        Component{
                                id:snow
        Particles {
            x: 0; y: 0; width: interfc.width; height: interfc.height
            source: "ressources/snow.png"; velocity: 40
            velocityDeviation: 0; count: interfce.getFrequence(); fadeInDuration: 3000; emissionRate:4000
                        ParticleMotionGravity {
             yattractor: 1000
             xattractor: 0
             acceleration: 25
         }
        }
                }
                Loader{id : snowLoader}

                Connections {
                        target: interfce
                        onSnow : snowLoader.sourceComponent=snow
                }


        // The small house
Item{
                x:100; y:200
        Image {
                        width:100; height:100;
                        source: "ressources/house.png";
                }
                }
        // Thunder, l'éclaire doit apparaitre de facon aléatoire

        Component{
                id:eclaire
                Item{
                Component
                {
                id:ecler
                Item{
                Image{
                        y:20; x:Math.floor(Math.random() * 300)
                        source:"ressources/ECLAIRE.png"
                }
                Timer {
         interval:5; running: true; repeat: false
         onTriggered: ecler.destroy()
                }
                }
                }


                Loader{id:eclerLoader}
                Timer {
         interval: 300; running: true; repeat: true
         onTriggered: eclerLoader.sourceComponent=ecler
                 }
                 }
                }

        Loader {id: eclaireLoader }

        Connections {
                        target: interfce
                        onThunder : eclaireLoader.sourceComponent=eclaire}

        Item{
                x:540; y:20
        Image {
                        width:100; height:100;
                        source: "ressources/cardino.png";
                }
                }


        Item{

                id: brouillard
                width:parent.width; height:parent.height
                 Component {
                         id: fogRect
                        Rectangle {
                                width: 500 // parent.width
                                height: 500 //parent.height
                                color: "grey"
                                opacity:0.3
                        }

                 }

                Loader{id : fogLoader}

                Connections {
                        target: interfce
                        onItFogz : fogLoader.sourceComponent=fogRect
                }
        }
                 Text {id:dv; text :"Direct. vent : "+interfce.getWindDirection(); x:20; y:20}
             Text {id:vv; text :"Vites. vent : "+(interfce.getWindSpeed()*3.6).toFixed(2)+" Km/h"; x:20; y:30}
                 Text {id:sy; text :"Temps : "+interfce.getSymbol(); x:20; y:40}
                 Text {id:tem; text :"Temper. : "+interfce.getTemperature()+" C"; x:20; y:50}

          Timer {
         interval: 5000; running: true; repeat: true
         onTriggered: {	dv.text="Direct. vent : "+interfce.getWindDirection()
                                                vv.text="Vites. vent : "+(interfce.getWindSpeed()*3.6).toFixed(2)+" Km/h";
                                                sy.text="Temps : "+interfce.getSymbol()
                                                tem.text="Temper. : "+interfce.getTemperature()+" C"
                                                }
     }


}
