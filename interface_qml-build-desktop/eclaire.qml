import Qt 4.7
import Qt.labs.particles 1.0

Item
{
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
         interval: 500; running: true; repeat: false
         onTriggered: ecler.destroy()
		}
		}
		}
		
		
		Loader{id:eclerLoader}
		Timer {
         interval: 3000; running: true; repeat: true
         onTriggered: eclerLoader.sourceComponent=ecler
		 }
		 }
		}
		}