# Librairie TGP LCD Keypad

Permet le contrôle simplifié d'un blindage "LCD Keypad Shield". Incluant les 5 boutons, l'écran LCD 2x16 et le rétroéclairage. Elle nécessite les autres classes [TGP Bouton](https://github.com/TechnoPhysCAL/TGP_Bouton), [TGP Del](https://github.com/TechnoPhysCAL/TGP_Del) et [LiquidCrystal](https://www.arduino.cc/en/Reference/LiquidCrystal).

## Détails

## Notes de version
-0.9.0 Version d'essai avant utilisation officielle

## Calibration

Les cinq boutons de ce blindage sont reliés à une seule entrée digitale (A10); un diviseur de tension variable permet de distinguer quel bouton est appuyé (un seul détecté à la fois). La valeur des résistances de ces boutons peut varier un peu d'un blindage à l'autre, il faut donc procéder à une calibration manuelle de ces boutons. Les 5 valeurs analogues lues seront conservées dans le EEPROM pour conserver la calibration de manière permanente. L'adresse en mémoire du EEPROM utilié peut être spécifié (voir méthode begin() plus bas).

Pour entamer la procédure de calibration au moment de mettre la carte sous tension : 
- Maintenez enfoncé simultanément les boutons 'droite' et 'reset';
- Relachez le bouton 'reset' en maintenant 'droite' enfoncé;
- La séquence de calibration devrait s'afficher à l'écran LCD : suivez les directives où chacun des boutons devra être enfoncé puis relaché dans un ordre qui vous sera nommé.

Le programme poursuivra ensuite son déroulement comme prévu.


## Utilisation

```cpp
#include <LCDKeypad.h>
LCDKeypad lcdKeypad;

void setup()
{
  lcdKeypad.begin();
}

void loop()
{
  lcdKeypad.refresh();

  if (lcdKeypad.haut.isPressed() || lcdKeypad.haut.isLongPressed())  //Le bouton HAUT ou BAS est appuyé
  {
    lcdKeypad.retro.setBrightness(lcdKeypad.retro.getBrightness() + 5); //allumer la Del rouge.

  }
  if (lcdKeypad.bas.isPressed() || lcdKeypad.bas.isLongPressed())  //Le bouton HAUT ou BAS est appuyé
  {
    lcdKeypad.retro.setBrightness(lcdKeypad.retro.getBrightness() - 5); //allumer la Del rouge.

  }

  if (lcdKeypad.selection.isPressed()) //Le bouton selection est appuyé
  {
    lcdKeypad.ecran.ecrire("Bonjour monde!", 0);
  }
  
  if (lcdKeypad.gauche.isPressed()) //Le bouton selection est appuyé
  {
    lcdKeypad.ecran.effacer( 1);
    lcdKeypad.ecran.ecrire("Gauche..", 1);
  }
  
  if (lcdKeypad.droite.isPressed()) //Le bouton selection est appuyé
  {
    lcdKeypad.ecran.effacer(1);
    lcdKeypad.ecran.ecrire("        ..Droite!", 1);
  }
}
```

## Constructeurs
```cpp
LCDKeypad()

```
Aucun paramètre nécessaire; l'initialisation des divers éléments qui constituent Le LCD Keypad sont initialisés selon leur broches respectives.


## Propriétés disponibles

Dans les descriptions suivantes, la variable lcdKeypad est une instance de la classe ProtoTGP.

```cpp
BoutonLCD lcdKeypad.gauche
BoutonLCD lcdKeypad.droite
BoutonLCD lcdKeypad.haut
BoutonLCD lcdKeypad.bas
BoutonLCD lcdKeypad.selection
```
Permet d'accéder aux objets de type BoutonLCD. Toutes les méthodes de la classe [Bouton](https://github.com/TechnoPhysCAL/TGP_Bouton) sont ensuite disponibles.

---
```cpp
Del lcdKeypad.retro
```
Permet d'accéder au rétroéclairage de l'écran LCD.  Toutes les méthodes de la classe [TGP Del](https://github.com/TechnoPhysCAL/TGP_Del) sont ensuite disponibles.

---
```cpp
Ecran lcdKeypad.ecran
```
Permet d'accéder à l'objet de type EcranLCD, qui offre les mêmes fonctionnalités que la librairie [LiquidCrystal](https://www.arduino.cc/en/Reference/LiquidCrystal) et quelques autres supplémentaires (voir section plus bas).

## Méthodes disponibles
```cpp
void begin()
void begin(int epprom_addres)
```
Initialise toutes les composantes du blindage. Pour la calibration des boutons, on peut préciser l'adresse mémoire dans le EEPROM qui contient ces valeurs (par défaut adresse 0).

---
```cpp
void refresh()
```
Cette méthode doit être placée en début de boucle loop(): elle permet de mettre à jour l'état de toutes les composantes du blindage .

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

## Propriétés de la classe EcranLCD

```cpp
void ecrire(char *str)
void ecrire(char *str, int line)
void ecrire(String str)
void ecrire(Strin str, int line)

```
Permet d'afficher une chaîne de texte à l'écran, à ligne voulue (0 ou 1, par défault 0 si non spécifié) .

--- 
```cpp
void effacer()
void effacer(int line)

```
Permet d'effacer tout l'écran (si aucun paramètre n'est fourni), ou seulement une ligne spécifique (0 ou 1, ou -1 pour effacer tout l'écran).

### Remarque

Toutes les méthodes primitives déjà présentes dans la librairie LiquidCrystal sont disponibles.