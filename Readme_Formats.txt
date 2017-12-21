Jonathan Van der Cruysse
Eerste Bachelor Informatica 2014-2015
s0142476
Beschrijving functionaliteit extra bestandsformaten
===================================================
Uitvoerformaten
---------------
Deze engine ondersteun drie uitvoerformaten:
  * svg - Scalable Vector Graphics (*.svg)
  * bmp - Bitmap (*.bmp)
  * ppm - Portable pixmap (*.ppm)

Het volstaat de regel `outputtype = "<format>"` - waar "<format>" een van de bovenstaande
formaten is - toe te voegen aan de "General" sectie om het gewenste uitvoerformaat te
verkrijgen. Indien zo'n regel er niet staat, gaat de engine ervan uit dat "bmp"
bedoeld werd.

"ppm" en "bmp" geven gewoonlijk identieke resultaten, daar zij allebei bitmap-formaten
zijn, "svg" gebruikt echter een andere techniek: aangezien dit een vector-formaat
is, worden lijnen en driehoeken omgezet in paths, die de SVG-renderer dient te renderen.
De praktische gevolgen van dit model is dat figuren niet door de engine gerasterized
worden, en het concept van een individuele pixel bij dit uitvoerformaat niet
bestaat. Aangezien deze twee zaken vereisten zijn voor een Z-buffering implementatie,
wordt Z-buffering niet uitgevoerd bij SVG output, zelfs indien een afbeeldingsformaat
als "LightedZBuffering", "ZBuffering" of "ZBufferedWireframe" wordt genomen. Elke
lijn en driehoek wordt weggeschreven naar het SVG-bestand, waardoor elke vorm van
belichting het gevormde beeld kan verstoren.

SVG-afbeeldingen zijn echter niet geheel onnuttig: bij figuren waar Z-buffering
of belichting niet relevant is, vormen zij een aantrekkelijk resultaat dat uitvergroot
of verkleind kan worden naar arbitraire dimensies, en goed als image element
in een webpagina kan dienen.

Invoerformaten
--------------
Deze engine ondersteun twee texture map invoerformaten:
  * bmp - Bitmap (*.bmp)
  * ppm - Portable pixmap (*.ppm)

Voor verdere verduidelijking verwijs ik naar de readme over texture mapping.
