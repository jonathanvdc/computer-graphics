Jonathan Van der Cruysse
Eerste Bachelor Informatica 2014-2015
s0142476
Beschrijving functionaliteit texture mapping
============================================
Deze readme is enkel van toepassing op afbeeldingen van het type "LightedZBuffering".

Inhoud readme:
 * Texture property syntax
   * texture entries
 * Textures
   * solid
   * plane-texture
   * sphere-texture
   * opacity-mask
   * blend-over
   * blend-additive (aka blend-add)
   * blend-multiplicative (aka blend-multiply)
   * blend-subtract
   * radial-gradient
 * Texture paths
   * ppm files
   * bmp files
   * random bitmaps
 * Sampler syntax
 * Samplers
   * nearest-neighbor-wrap (aka default/nearest-neighbor/wrap)
   * nearest-neighbor-clamp (aka clamp)
   * linear
   * cosine
   * cubic

Texture property syntax:
=======================
Elke "property" die aan een texture toegewezen kan worden, kan door behulp van
drie verschillende ini "entries" op een waarde gezet worden. De namen van deze
entries zijn de volgende, in dalende volgorde van precendence:

 * <property>Texture = <section>
 * <property>Color = <color>
 * <property>Light = <color>
 * <property>Reflection = <color>

waar "<property>" de naam van de property voorstelt. De "<property>Color", "<property>Light" en
"<property>Reflection" vormen verwijzen naar een inline floating-point 3-tupel
dat een kleur voorstelt, zoals gedefinieerd bij belichting. Bijvoorbeeld:

    [Figure0]
    type = "Cube"
    scale = 1
    rotateX = 0
    rotateY = 0
    rotateZ = 0
    center = (0, 0, 0)
    ambientReflection = (1.0, 1.0, 1.0)
    diffuseReflection = (0.50, 0.25, 0.00)
    specularReflection = (0.4, 0.4, 0.4)
    reflectionCoefficient = 20

In het bovenstaande voorbeeld is `ambientReflection = (1.0, 1.0, 1.0)`
equivalent aan `ambientColor = (1.0, 1.0, 1.0)`. De "Color"-varianten zijn
geintroduceerd omdat textures zich ook op andere textures kunnen beroepen
(zie "opacity-mask" en "blend-over" onder "Textures"), in welk geval "Reflection" een
onlogische naam zou zijn (hoewel, bij gebrek aan een andere
texture-style of color-style entry ook daar de reflection-style entries ingelezen
worden).

Texture-style entries verwijzen naar een andere section van de ini, die een texture
definieert. Bijvoorbeeld:

    [Figure0]
    type = "Cube"
    scale = 1
    rotateX = 0
    rotateY = 0
    rotateZ = 0
    center = (0, 0, 0)
    ambientTexture = "BlueTexture"

    [BlueTexture]
    type = "solid"
    color = (0.0, 0.0, 1.0)

In dit voorbeeld wordt een blauwe kubus gedefinieerd, aangezien `ambientTexture = "BlueTexture"`
verwijst naar texture "BlueTexture", dat gedefinieerd is als een blauwe solid color
texture (zie "solid" onder "Textures").

texture entries
---------------
Het voorgaande is zowel van toepassing op enkele entries binnen de bestaande
sections, als op sommige entries in nieuwe section types. Die laatsten worden
toegelicht waar ze gedefinieerd worden. De eersten worden hier opgesomd.
Nieuwe entries binnen figuren en lichten:

  * De ambient/diffuse/specular texture of kleur van een figuur:
    * ambientColor
    * ambientLight
    * ambientTexture
    * diffuseColor
    * diffuseLight
    * diffuseTexture
    * specularColor
    * specularLight
    * specularTexture

  * De diffuse en specular texture of kleur van een licht:
    * diffuseColor
    * diffuseReflection
    * diffuseTexture
    * specularColor
    * specularReflection
    * specularTexture

Merk op dat enkel de `ambientLight` entry van een licht behouden blijft. Hier kan
geen texture op toegepast worden, en heeft ook geen alternatieve namen. De voorgenoemde
zaken zijn echter wel van toepassing op de diffuse en specular textures van een
licht.

Textures
========
solid
-----
Een solid color texture wordt geidentificeerd door `type = "solid"`, en heeft als
enige entry "color". Bijvoorbeeld:

    [BlueTexture]
    type = "solid"
    color = (0.0, 0.0, 1.0)

plane-texture
-------------
Een plane texture bestaat uit een bitmap die de te renderen texture voorstelt,
een vlak en een sampler. Deze texture stemt overeen met een texture mapping voor
willekeurige vlakken, door drie-dimensionale punten op een vlak te projecteren,
volgens hoofdstuk "18.3 Willekeurige oppervlakken" in de cursus.

Lijst van entries:

    type = "plane-texture" : identificeert de texture als een plane texture.
    texture = <bitmap path> : duidt de locatie van de bitmap aan (zie "Texture paths")
    position = <3-dimensional tuple> : duidt het punt van het vlak aan dat overeen stemt
                                       met de linker onderhoek van de bitmap.
    uDirection = <3-dimensional tuple> : bepaalt de breedte van het vlak. Deze
                                         vector stemt overeen met de X-as van de bitmap.
    vDirection = <3-dimensional tuple> : bepaalt de hoogte van het vlak. Deze
                                         vector stemt overeen met de Y-as van de bitmap.
    samplerReference = <section> : Refereert naar de sampler voor deze texture.
    sampler = <inline sampler> : Definieert naar de sampler voor deze texture.
                                 (merk op dat samplerReference en sampler elkaar uitsluiten)

Bijvoorbeeld:

    [Texture0]
    type = "plane-texture"
    texture = "Image.bmp"
    position = (-1, -1, -1)
    uDirection = (0, 2, 0)
    vDirection = (0, 0, 2)

sphere-texture
-------------
Een sphere texture bestaat uit een bitmap die de te renderen texture voorstelt,
het midden van een bol en een sampler. Deze texture stemt overeen met de
texture mapping voor een bol, volgens hoofdstuk "18.2 Bolvormige oppervlakken"
in de cursus. Ze is ook nuttig voor ander min of meer bolvormige oppervlakken,
zoals een icosaeder, afgeknotte icosaeder of dodecaeder.

Lijst van entries:

    type = "sphere-texture" : identificeert de texture als een sphere texture.
    texture = <bitmap path> : duidt de locatie van de bitmap aan (zie "Texture paths")
    position = <3-dimensional tuple> : bepaalt het midden van het bolvormig oppervlak.
    samplerReference = <section> : Refereert naar de sampler voor deze texture.
    sampler = <inline sampler> : Definieert naar de sampler voor deze texture.
                                 (merk op dat samplerReference en sampler elkaar uitsluiten)

Bijvoorbeeld:

    [Texture0]
    type = "sphere-texture"
    texture = "Image.bmp"
    position = (0, 0, 0)

opacity-mask
------------
Een opacity mask texture maakt een nieuwe texture op basis van twee bestaande textures:
de "mask" en de "brush". Het resultaat van een opacity mask is een texture waarvan
het alpha channel in elke pixel overeenkomt met de grijswaarde van de mask, en de
rgb channels gelijk zijn aan de rgb waarden van de brush in die pixel.

Lijst van entries:

    type = "opacity-mask" : identificeert de texture als een opacity mask texture.
    brush(Texture/Color/Reflection) = <section/color> : definieert de brush texture.
    mask(Texture/Color/Reflection) = <section/color> : definieert de mask texture.

Bijvoorbeeld:

    [Texture0]
    type = "opacity-mask"
    brushTexture = "Texture1"
    maskColor = (0.75, 0.75, 0.75)

    [Texture1]
    type = "sphere-texture"
    texture = "Image.bmp"
    position = (0, 0, 0)

Opmerking: Een opacity-mask dient gecombineerd te worden met een blend-over texture,
zodat het alpha channel voor elke pixel terug '1.0' wordt. Er bestaat geen garantie
dat de output bitmap alpha blending uitvoert (momenteel is dit niet het geval, maar
zelfs als outputafbeeldingen toch alpha blending deden, zou dat incompatibel met Z-buffering zijn).

blend-over
----------
Een blend over texture voert per pixel "over" alpha blending uit op een "top" en
"bottom" texture, die op die wijze gecombineerd worden tot een nieuwe texture.

Lijst van entries:

    type = "blend-over" : identificeert de texture als een blend over texture.
    top(Texture/Color/Reflection) = <section/color> : definieert de top texture.
    bottom(Texture/Color/Reflection) = <section/color> : definieert de bottom texture.

Bijvoorbeeld:

    [Texture0]
    type = "sphere-texture"
    texture = "random:10 10"
    position = (0, 0, 0)

    [Texture1]
    type = "opacity-mask"
    maskColor = (0.75, 0.75, 0.75)
    brushTexture = "Texture0"

    [Texture2]
    type = "blend-over"
    topTexture = "Texture1"
    bottomColor = (0.00, 0.00, 0.00)

Hier stelt Texture2 een random texture voor waarbij elke pixel een rgb waarde heeft
tussen (0.0, 0.0, 0.0) en (0.75, 0.75, 0.75).

blend-additive (aka blend-add)
--------------
Een additive blend telt de kleurwaarden van de overeenkomstige pixels van
textures "top" en "bottom" op, en combineert ze tot een nieuwe texture.

Lijst van entries:

    type = "blend-additive" : identificeert de texture als een additive blend texture.
    top(Texture/Color/Reflection) = <section/color> : definieert de top texture.
    bottom(Texture/Color/Reflection) = <section/color> : definieert de bottom texture.

blend-subtract (aka blend-subtract)
--------------
Een additive blend trekt de kleurwaarden van de overeenkomstige pixels van textures
"top" en "bottom" af.

Lijst van entries:

    type = "blend-additive" : identificeert de texture als een subtract blend texture.
    top(Texture/Color/Reflection) = <section/color> : definieert de top texture.
    bottom(Texture/Color/Reflection) = <section/color> : definieert de bottom texture.


blend-multiplicative (aka blend-multiply)
--------------------
Een additive blend vermenigvuldigt de kleurwaarden van de overeenkomstige pixels
van textures "top" en "bottom".

Lijst van entries:

    type = "blend-additive" : identificeert de texture als een multiplicative blend texture.
    top(Texture/Color/Reflection) = <section/color> : definieert de top texture.
    bottom(Texture/Color/Reflection) = <section/color> : definieert de bottom texture.

radial-gradient
---------------
Een radial gradient texture combineert twee andere textures op basis van hun afstand
tot een zeker punt en een straal.

Lijst van entries:

    type = "radial-gradient" : identificeert de texture als een radial gradient texture.
    position = <three-dimensional vector> : duidt het middelpunt van de radial gradient aan
    radius = <double> : duidt de straal aan waarin geblend wordt tussen "center" en "periphery".
    center(Texture/Color/Reflection) = <section/color> : definieert de texture in het middelpunt.
    periphery(Texture/Color/Reflection) = <section/color> : definieert de texture and de buitenkant.

De kleur van een radial gradient texture op een punt "p" wordt als volgt bepaald:

    gradient(p) = center(p) * (1 - |p - position| / radius) + periphery(p) * |p - position| / radius
        met |p - position| < radius
    gradient(p) = periphery(p)
        met |p - position| >= radius

Texture paths
=============
ppm files
---------
Portable pixel map files (http://netpbm.sourceforge.net/doc/ppm.html) kunnen
gebruikt worden als texture bitmaps en als output formaat. Texture bitmaps met
een ".ppm" extensie worden herkend als ppm bitmaps. De ppm reader ondersteunt
enkel ppm files met "P3" of "P6" magic characters. Arbitraire P3 files kunnen geparsed
worden. Enkel miniscule P6 bitmaps worden correct ingelezen. Om een P3 ppm als output
te verkrijgen volstaat het om `outputtype = "ppm"` in de "General" sectie te plaatsen.

bmp files
---------
24-bits per pixel bmp files worden als texture bitmaps en output gebruikt tenzij
expliciet anders aangegeven.

random bitmaps
--------------
Het is mogelijk random bitmaps te genereren en als texture te gebruiken door de
"texture" entry van een sphere-texture of plane-texture op de volgende manier te definieren:

    texture = "random:<width> <height>"

waar "width" en "height" de grootte van de te genereren bitmap voorstellen.

Sampler syntax
==============
Naast textures ondersteunt deze engine ook samplers, i.e. technieken om van een
(u, v) paar over te gaan naar een kleur. Samplers worden gebruikt door "sphere-texture"
en "plane-texture". Ofwel kunnen ze aangeduid worden door de "samplerReference" entry, wat
naar een sectie in de ini verwijst, ofwel door de "sampler" entry, die een inline
sampler definieert. Verder kunnen alle sampler types zowel als door een section
als door een inline value gedefinieerd worden. Dat eerste kan door de "type" entry
van de section het type van de sampler toe te wijzen, het tweede door het type van de
sampler als string aan de "sampler" entry door te geven. Indien een sampler niet
expliciet aangegeven wordt, gaat de engine ervan uit dat de "default", i.e. "wrap"
interpolatie bedoeld werd.

Bijvoorbeeld:

    [Texture0]
    type = "sphere-texture"
    texture = "random:10 10"
    samplerReference = "Sampler0"
    position = (0, 0, 0)

    [Sampler0]
    type = "cubic"
    sampler = "clamp"

of

    [Texture0]
    type = "sphere-texture"
    texture = "random:10 10"
    sampler = "wrap"
    position = (0, 0, 0)

Samplers
========
nearest-neighbor-wrap (aka default/nearest-neighbor/wrap)
---------------------
Deze sampler trunceert de (u, v) waarden en neemt de pixel in de bitmap die hiermee
overeen komt. Indien de (getrunceerde) (u, v) waarden buiten de bitmap vallen,
wordt de afbeelding herhaald.

nearest-neighbor-clamp (aka clamp)
----------------------
Deze sampler trunceert de (u, v) waarden en neemt de pixel in de bitmap die hiermee
overeen komt. Indien de (getrunceerde) (u, v) waarden buiten de bitmap vallen,
worden de waarden op de rand van de afbeelding genomen.

linear
------
De lineaire sampler trunceert de (u, v) waarden, vraagt dan via een andere
sampler de kleurwaarden van deze en drie naburige pixels op, en past dan lineaire interpolatie
toe. Het gebruik van een andere sampler staat toe te varieren tussen clamp en wrap.

Bijvoorbeeld:

    [Sampler0]
    type = "linear"
    sampler = "clamp"

cosine
------
De cosinus-interpolatie sampler trunceert de (u, v) waarden, vraagt dan via een andere
sampler de kleurwaarden van deze en drie naburige pixels op, en past dan cosinus-interpolatie
toe op die waarden.

Bijvoorbeeld:

    [Sampler0]
    type = "cosine"
    sampler = "wrap"

cubic
-----
De kubieke interpolatie sampler trunceert de (u, v) waarden, vraagt dan via een andere
sampler de kleurwaarden van deze en vijftien naburige pixels op, en past dan kubieke interpolatie
toe op die waarden.

Bijvoorbeeld:

    [Sampler0]
    type = "cubic"
    sampler = "clamp"

Opmerking: omdat cubic interpolation rekening houdt met meer dan alleen de vier
dichtstbijzijnde texels van een punt, is het aangeraden "clamp" als sampler te
gebruiken in combinatie met "cubic", in plaats van de default "wrap", tenzij
wrap-around een wensbare eigenschap is. "clamp" vermijdt dat kleurwaarden van
de ene kant van een afbeeldingen overvloeien in de kleuren aan de overstaande kant.
