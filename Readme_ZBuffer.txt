Jonathan Van der Cruysse
Eerste Bachelor Informatica 2014-2015
s0142476
Beschrijving Z-Buffering output
====================================
Deze readme is enkel van toepassing op afbeeldingen van de types "ZBufferedWireframe",
"ZBuffering" en "LightedZBuffering".

Bij de voorgenoemde types van afbeeldingen is het mogelijk de Z-buffer te visualiseren
door onder de "General" section van de *.ini `outputZBuffer = true` te plaatsen.
De extra afbeelding die de Z-buffer voorstelt neemt dan de naam "zbuf_<name>.bmp"
aan, waar "<name>" de `name = "..."` entry is in dezelfde sectie van de *.ini.
Indien een "name" entry afwezig is, wordt "main" als default-waarde gekozen.

Bij "LightedZBuffering" met schaduwen bestaat ook de mogelijkheid tot het
wegschrijven van de Z-buffer van elke lichtbron, evenals met `outputZBuffer = true`
en een "name" entry, met de uitzondering dat de naam van het licht in kwestie,
in plaats van "main" als default-naam wordt genomen.
