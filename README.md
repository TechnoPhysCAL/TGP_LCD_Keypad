# Librairie TGP LCD Keypad

Permet le contrôle simplifié d'un blindage "LCD Keypad Shield". Incluant les 5 boutons et l'écran LCD 2x16. Elle nécessite les autres classes [TGP Bouton](https://github.com/TechnoPhysCAL/TGP_Bouton) et [LiquidCrystal](https://www.arduino.cc/en/Reference/LiquidCrystal).
## Détails

## Utilisation

```cpp
#include <ProtoTGP.h> 

ProtoTGP proto;
 
void setup()
{

  proto.begin();
}

void loop()
{
  proto.refresh(); 
  
  if (proto.haut.isPressed() || proto.bas.isPressed())  //Le bouton HAUT ou BAS est appuyé
  {
    proto.rouge.set(true); //allumer la Del rouge.

  }

  if (proto.gauche.isLongPressed() || proto.droite.isLongPressed()) //Le bouton gauche ou droite est maintenu appuyé
  {
    proto.verte.set(true); //allumer la Del verte.
  }
  
  }
  if (proto.selection.isPressed()) //Le bouton selection est appuyé
  {
    proto.ecran.ecrire("Bonjour monde!");
  }
```

## Constructeurs
```cpp
Proto()

```
Aucun paramètre nécessaire; l'initialisation des divers éléments qui constituent ProtoTPhys sont initialisés selon leur broches respectives.


## Propriétés disponibles

Dans les descriptions suivantes, la variable proto est une instance de la classe ProtoTGP.

```cpp
Bouton proto.gauche
Bouton proto.droite
Bouton proto.haut
Bouton proto.bas
Bouton proto.selection
```
Permet d'accéder aux objets de type Bouton. Toutes les méthodes de la classe [Bouton](https://github.com/TechnoPhysCAL/TGP_Bouton) sont ensuite disponibles.

---
```cpp
Del proto.rouge
Del proto.verte
```
Permet d'accéder aux objets de type Del.  Toutes les méthodes de la classe [TGP Del](https://github.com/TechnoPhysCAL/TGP_Del) sont ensuite disponibles.

---
```cpp
Ecran proto.ecran
```
Permet d'accéder à l'objet de type Ecran.  Toutes les méthodes de la classe [Ecran](https://github.com/TechnoPhysCAL/TGP_Ecran) sont ensuite disponibles.

## Méthodes disponibles
```cpp
void begin()
```
Initialise toutes les composantes de la plateforme. Doit être appelée dans la fonction setup().

---
```cpp
void refresh()
```
Cette méthode doit être placée en début de boucle loop(): elle permet de mettre à jour l'état de toutes les composantes de la plateforme.

---
```cpp
void setDebounceDelay(unsigned long)
```
Permet de modifier le temps de "debouncing" en millisecondes pour tous les boutons.

---
```cpp
void setLongPressDelay(unsigned long)
```
Permet de modifier le temps en millisecondes nécessaire pour que le bouton soit considéré comme 'maintenu longtemps' pour tous les boutons.

---
```cpp
void setLongPressInterval(unsigned long)
```
Permet de modifier le temps en millisecondes entre chaque valeur vraie de la méthode  'isLongPressed()' pour tous les boutons.

---