# Eindopdracht 6V

![6VWO Eindopdracht](https://img.shields.io/badge/6VWO-Eindopdracht-red)


In dit repository beheer je het eindproject en plaats je de code voor
- de webwidget (zie map `widget`)
- de knikkerbaan (zie map `arduino`)


Het eundverslag schrijf je in `eindverslag.md`..

Je werkt in dit project actief met GitHub.
Dat betekent dat je vanuit issues en het planbord werkt en tijdens het ontwikkelen op een goede manier gebruik maakt van branches en commits.
Iedere eerste les van de week heb je daarvoor een korte meeting en bespreek wat je de vorige week hebt gedaan en wat iedereen de komende week gaat doen.
In `planningsverslag.md` maak je hiervan elke keer een heel kort verslagje.
Zorg ervoor dat (voor zowel je groepsleden als de docent) altijd duidelijk is waar je mee bezig bent.


Arduino kun je niet ontwikkelen binnen GitPod. Deze code zul je op een andere manier moeten committen in GitPod.

## Algemene structuur
De webwidget en de knikkerbaan geven informatie aan de database en vragen ook informatie daar op. Het kan echter voorkomen dat de wificommunicatie van de Arduino langzamer gaat dan gewenst. Je zult daarvoor een veiligheidsmechanisme met een andere Arduino in moeten bouwen dat ervoor zorgt dat knikkers in een 'overloopbaantje' komen. 

## Widget
Het widget wordt door de server eenmalig als statisch bestand gestuurd naar een browser die erom vraag. De code van de widget wordt niet door GitPod uitgevoerd, maar door het browservenster waarin het widget zichtbaar is. Het testen / debuggen van het widget doe je met de optie 'Javascript-console' van je browser. In Chrome vind je die onder het menu 'Weergave->Ontwikkelaar->Javascript-console' en in Safari onder 'Ontwikkelaar-> Toon Javascript Console'. Je kunt daar ook breakpoints maken en de inhoud van variabelen inspecteren.

## Handige links
* [Tinkercad](https://tinkercad.io) - voor het maken van een virtuele Arduino
* [KhanAcademy](https://khanacademy.org) - voor sql en javascript / p5js-functies
* [w3schools](https://w3shools.com) - extra javascript informatie
* [p5js](https://p5js.org/reference) - naslagmateriaal p5js
* [Arduino](https://www.arduino.cc/reference) - naslagmateriaal
* [Arduino-lessen](http://arduino-lessen.nl) - lessen die je 5V heb gezien
* [Seeed wiki](https://wiki.seeedstudio.com/Grove/) - informatie over evt. Grove modules
* [Markdown](https://guides.github.com/pdfs/markdown-cheatsheet-online.pdf) Opmaak van je verslag
* [Schema's tekenen](https://draw.io) Voor bijv. strokendiagram
