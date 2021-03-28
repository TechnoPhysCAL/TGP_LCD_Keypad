# Librairie TGP LCD Keypad

Permet le contrôle simplifié d'un blindage "LCD Keypad Shield". Incluant les 5 boutons, l'écran LCD 2x16 et le rétroéclairage. Elle nécessite les autres classes [TGP Bouton](https://github.com/TechnoPhysCAL/TGP_Bouton), [TGP Del](https://github.com/TechnoPhysCAL/TGP_Del) et [LiquidCrystal](https://www.arduino.cc/en/Reference/LiquidCrystal).

## Détails

## Notes de version
-1.0.0 Première version officielle

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

  if (lcdKeypad.selection.isPressed()) //Le bouton selection est appuyé
  {
    lcdKeypad.ecran.ecrire("Bonjour monde!"); //affiche par défaut à la coordonnée (0,0).
  }
  
  if (lcdKeypad.gauche.isPressed()) //Le bouton selection est appuyé
  {
    lcdKeypad.ecran.ecrire("Gauche..",0, 1, 8); //affiche à la coordonnée (0,1) sur un espace de 8 caractères.
  }
  
  if (lcdKeypad.droite.isPressed()) //Le bouton selection est appuyé
  {
    
    lcdKeypad.ecran.ecrire("...Droite!",8, 1, 8); //affiche à la coordonnée (8,1) sur un espace de 8 caractères.
  }

  if (lcdKeypad.haut.isPressed() )  //Le bouton HAUT ou BAS est appuyé
  {
    lcdKeypad.retro.setBrightness(lcdKeypad.retro.getBrightness() + 5); //Augmenter la luminosité du rétroéclairage

  }
  if (lcdKeypad.bas.isPressed())  //Le bouton HAUT ou BAS est appuyé
  {
    lcdKeypad.retro.setBrightness(lcdKeypad.retro.getBrightness() - 5); //Diminuer la luminosité du rétroéclairage

  }
}
```

## Constructeurs
```cpp
LCDKeypad()
LCDKeypad(int rs, int en, int d4, int d5, int d6, int d7, int retro_broche, int keypad_broche)
```
À l'initialisation, les divers éléments qui constituent le blindage LCD Keypad sont initialisés selon leurs broches respectives. Si non spécifiées, les valeurs par défault sont rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7, retro_broche = 10 et keypad_broche = 0.

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
void begin(int epprom_addres) //Sur architecture Arduino
void begin(const char * name) //Sur architecture ESP32
```
Initialise toutes les composantes du blindage. Pour la calibration des boutons, on peut préciser l'endroit en mémoire qui contient ces valeurs. Sur Arduino, on doit fournir une adresse du EEPROM (par défaut 0); sur ESP32, on doit fournir le nom d'un espace pour stocker en mémoire EEPROM via la librairie Preferences (par défaut "lcd-keypad").ESP32, 

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
void ecrire(char *str, int x, int y, int largeur)
void ecrire(String str)
void ecrire(String str, int x, int y, int largeur)

```
Permet d'afficher une chaîne de texte à l'écran, à la coordonnée voulue ( (0,0) par défaut si non spécifié). On peut spécifier une largeur (par défaut 0), et si le texte à écrire est inférieur à la valeur de largeur, on complétera avec des espaces ' ', ce qui est peut être utile pour effacer du texte précédemment écrit.

--- 
```cpp
void effacer()
void effacer(int x, int y, int largeur)

```
Permet d'effacer tout l'écran (si aucun paramètre n'est fourni), ou seulement un espace spécifique débutant à la coordonnée (x,y) et de largeur spécifié.

### Remarque

Toutes les méthodes primitives déjà présentes dans la librairie LiquidCrystal sont disponibles.