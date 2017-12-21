Jonathan Van der Cruysse
Eerste Bachelor Informatica 2014-2015
s0142476
Beschrijving stochastische replacement rules
============================================
De stochastische replacement rules zijn een simpele extensie op de bestaande
L2D- en L3D-formaten. Ze betreft enkel het "Rules"-gedeelte van zo'n bestand.

Bijvoorbeeld:

Rules = {
        A -> "B",
        B -> "A"
}

De extensie bestaat erin dat het nu mogelijk is een "weight" te associeren met
elke regel - indien dit niet gebeurt, wordt aangenomen dat "weight" 1 bedoeld werd -
zodat de kans dat een bepaalde replacement rule gekozen wordt gelijk is aan
de weight van die regel gedeeld door de som van alle weights voor replacement
rules die opereren op het gegeven symbool. Om meer dan een mogelijke replacement
rule op te geven, kunnen verschillende candidaten gescheiden worden door een
semicolon-delimited list.

De volledige syntax voor entry in het "Rules"-gedeelte wordt:

<symbol> -> "<string>"[-<weight>][; "<string>"[-<weight>]...]

Een voorbeeld:

Rules = {
        A -> "B"-2; "AB"-3; "A",
        B -> "A"; "B"
}

Dit stelt dat "A" een 2/6 kans heeft om vervangen te worden door "B", een 3/6 kans
om vervangen te worden door "AB" en een 1/6 kans - impliciet toegewezen - om
door "A" vervangen te worden. "B" heeft dan weer een 1/2 kans om door "A" en een
1/2 kans om door "B" vervangen te worden.

Deze uitbreiding blijft behouden in het formaat voor 3D L-Systemen.
