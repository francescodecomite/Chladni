# Chladni
Utiliser des micro-controleurs pour faire des figures de Chladni

Plusieurs phases : 
1. Générer et contrôler du son avec un Arduino (puis ESP32, puis microchip (mais je ne promets rien))
2. Afficher des infos sur chacun des modèles avec un écran LCD. 

#Générer et contrôler du son avec un Arduino
Je voudrais bien générer un son plus fort que ce que peut sortir l'arduino, mais pour ça faut amplifier, et faire un circuit avec un transistor
et ça, j'ai pas directement sous la main. En fait peut-être que si. 

Je voulais aussi  utiliser la bibliothèque [toneAC](https://github.com/jurs/toneAC) qui promet un volume double de ce que produirait un 
arduino normale. Mais le fichier [toneAC_Demo](./toneAC_demo.pde) retourne plein d'erreur .. à voir.

# Samedi 19 septembre. 
On reprend le problème(?) de l'amplification. Je me base sur [ce tuto](https://passionelectronique.fr/haut-parleur-arduino/  )

Schema : ![image](schema1.jpg)

D'abord, un modèle sans amplification le fichier [happybirthday](./happybirthday/happybirthday.ino). Le son est trop bas pour faire vibrer une membrane.

Et puis avec l'ampli du tuto cité plus haut. On entends, mais c'est toujours pas assez fort pour faire vibrer une membrane. Voir photos et vidéos, j'ai un peu simplifié le schéma, mais ça ne change pas grand chose. Je n'avais pas le bon Mosfet, j'ai utilisé un BUK553, c'est tout ce que j'avais. 

En même temps, j'ai cramé l'arduino, je continue avec un esp32. 
J'ai acheté des amplis tout fait TDA2030 et une alimentation réglable, et ça a fini par marché. 
Le cablage est ici : ![image](cablage.jpg)

Il y a aussi les programmes qui font des sons. 

Je me suis aussi rappelé que j'avais construit un ampli pour un speakjet (un circuit de synthèse vocale) : 
 ![image](speakjet.jpg)

Si je retrouve mes LM386, je vais essayer de le refaire. 

# 26/09
En utilisant ce tuto : https://www.youtube.com/watch?v=hKmPc0Q0kKg

J'ai refait un truc en collant une tige filetée sur la membrane du haut-parleur. 
J'ai ensuite coupé la tige filetée (quand c'est trop lourd, la membrane a du mal à commmuniquer sa vibration.)
Il y a plein de photos et de vidéos dans le git, mais c'est tout en bazar. 
Sur la tige filetée, avec deux vis, on peut fixer une plaque vibrante. 
Là ça commence à marcher. 
Le choix du matériau et des dimensions de la plaque doit avoir de l'importance -> à tester...

J'ai rajouté un potentiomètre pour pouvoir changer la fréquence, mais il faut que je raffine le système. 
On ne doit pas changer le son à chaque mouvement du potentiomètre, je vais utiliser les interruptions, et ne faire un changement
que lorsque la nouvelle valeur est significativement différente de la précédente. 

Pour les interruptions j'ai essayé plusieurs trucs (interruption quand le potentiomètre change, lecture par un timer) mais ça me fait tout le temps rebooter le micro-contrôleur. Finalement, je regarde si le changement est significatif, et alors je change. 
ça donne des valeurs plus stables, et donc la note tient plus longtemps. 

# 27/09
J'ai découpé une autre plaque plus petite (la taille et la structure de la plaque jouent un rôle dans les figures générées). J'ai peint les plaques en noir, les vidéos qui s'appellent 'sunday' sont assez jolies. 


# 28/09
J'ai remplacé le sable par du bicarbonate de soude, ça marche mieux, c'est plus léger. J'ai essayé des fréquences plus élevées. Au dessus de 1000-2000 Hz, il ne se passe plus rien. La plaques est trop epaisse ? 

A faire : essayer des fréquences encore plus élevées ....

Entre 500 et 1000, on a des courbes rigolotes (voir la vidéo monday .  En fait non, le fichier est trop gros, il est sur Bluesky ). J'i fait des captures d'écran qui s'appellent lundi1 à lundi4.

# 29/09

On va rajouter l'affichage sur un écran led, puis on mixera les deux fonctions dans un seul programme. 

## Commander un écran led avec un esp32

Je me base sur [ce tuto](https://www.instructables.com/ESP32-How-to-Interface-LCD-With-ESP32-Microcontrol/).
Il y a un problème par rapport au nombre de pattes de mon lcd (14 au lieu de 16)...

J'ai aussi un [autre tuto](https://www.circuitschools.com/interfacing-16x2-lcd-module-with-esp32-with-and-without-i2c/) qui utilise l'entrée 5v au lieu de 3.3v
Pour le moment y a rien qui marche, j'ai commandé des nouveaux écrans lcd, celui e j'ai me semble naze. 








