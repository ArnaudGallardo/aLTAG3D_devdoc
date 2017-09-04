Modification du XSD
===================

Le fichier XSD_ utilisé par aLTAG3D pour fonctionner est maintenu par les
chercheurs du Consortium 3D. Cependant, aLTAG3D étant un logiciel Open-Source,
il est possible que vous cherchiez à modifier ce fichier XSD par vous même.

Le fichier XSD actuel est disponible ici_.

Parsage du fichier XSD
----------------------

Le fichier XSD n'est pas utilisable tel quel par aLTAG3D, il faut en effet
effectuer une requête xquery particulière sur le fichier XSD afin d'en extraire
un fichier XML utilisable par le logiciel.

Cette requête était au départ effectuée directement dans aLTAG3D, un problème
de version de XQuery dans Qt nous a forcé à déplacer cette étape hors du logiciel.

Le parseur XQuery utilisé est Saxon-HE-9_.

.. code-block:: sh

  java -classpath saxon9he.jar net.sf.saxon.Query -q:altag.xq inputDocument=mdacst3d.xsd -o:mdacst3d.xml

Le fichier altag.xq est disponible dans les sources.

Modification des fichiers de configuration
------------------------------------------

En plus du fichier XSD et de son équivalent parsé, aLTAG3D utilise un fichier de
configuration appelé altag.json.

Ce fichier permet de rajouter des informations concernant le XSD sans pour
autant le surcharger de données nécessaire uniquement à aLTAG3D et non à
l'archivage en lui même.

.. literalinclude:: _static/files/altag.json
   :language: json
   :caption: altag.json \:
   :linenos:

Utilisations du fichier de configuration par aLTAG3D :

- **version** : détermine la version du fichier XSD
- **indicators** : indique les noms des données utilisées comme "labels" sur certaines boîtes
- **mapToSIP** : permet de fixer en dur certains noms dans le code et de pouvoir simplement les modifier plus tard (utilisé lors de la création du SIP.xml)
- **fichMeta** : ensemble des boîtes utilisant des fichiers (utilisé lors de la création du SIP.xml)
- **autoCompletion** : ensemble des boîtes pouvant être auto-complétées (hors fichiers)

.. _Saxon-HE-9: http://www.saxonica.com/download/opensource.xml
.. _ici: http://altag3d.huma-num.fr/data/mdacst3d.xsd
.. _XSD: http://altag3d-userdoc.readthedocs.io/fr/latest/intro.html#a-propos-du-xsd
