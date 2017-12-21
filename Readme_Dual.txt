Jonathan Van der Cruysse
Eerste Bachelor Informatica 2014-2015
s0142476
Beschrijving functionaliteit duale en getrunceerde figuren
==========================================================
Deze engine kan, naast de vereiste figuren, ook
twee extra klassen van figuren renderen:
    - Dual* (de duale figuur)
    - Truncated* (de afgeknotte figuur)
      (waar '*' een niet-wireframe figuur is)

Zo is een BuckyBall gelijk aan een TruncatedIcosahedron, en is een pentakis
dodecahedron een DualBuckyBall, of DualTruncatedIcosahedron.
De truncatie-factor kan ingesteld worden door de volgende regel toe te voegen aan de definitie van een figuur:
    - `truncation = <waarde>` (waar '<waarde>' een waarde tussen 0.0 en 0.5 is)

Een elftal voorbeelden zijn bijgevoegd onder de folder "dual_examples".

Het valt op te merken dat naast de buckyball er nog een reeks andere lichamen bestaan
die te bekomen zijn via deze prefixes, zoals:
   - Octahedron == DualCube
   - Dodecahedron == DualIcosahedron
   - Bicone == DualCylinder

Het toepassen van de "Dual"-prefix op een "Thick" figuur levert alsook de duale
figuur van de "Thick"-variant op. Desondanks ontstaan uit deze cylinders geen
bicones. Dit is echter een logisch gevolg van de duale figuur nemen van deze cylinders:
ze hebben geen boven- of ondervlak, en per gevolg heeft de duale figuur geen punten
op die plaatsen.
