Création d'un plugin aLTAG3D
============================

Afin de permettre à aLTAG3D de remplir de manière automatique le plus grand
nombre d'informations possible, un système de plugin a été mis en place.

Lors de l'importation d'un fichier dans le projet d'archivage, aLTAG3D cherche
dans la liste des plugins disponible celui étant compatible avec le format du
fichier importé. Si il existe, ce plugin pourra communiquer au logiciel un
ensemble d'informations concernant le fichier, qui viendront compléter les
données du projet.

Le système de plugins mis en place est celui de Qt, dont la documentation est
disponible ici_.

L'interface plugin dans aLTAG3D
-------------------------------

.. literalinclude:: _static/files/inc/interfaces.h
    :language: cpp
    :linenos:

Exemple de plugin simple
------------------------

.. literalinclude:: _static/files/altag3d_example.pro
   :caption: Fichier .pro \:
   :linenos:

.. literalinclude:: _static/files/exampleplugin.cpp
    :language: cpp
    :caption: exampleplugin.cpp \:
    :linenos:

.. literalinclude:: _static/files/exampleplugin.h
    :language: cpp
    :caption: exampleplugin.h \:
    :linenos:

.. literalinclude:: _static/files/pluginsfilters.json
  :language: json
  :caption: pluginsfilters.json \:
  :linenos:

Le fichier *pluginsfilters.json* est presque vide, mais nécessaire à la compilation.

.. _ici: http://doc.qt.io/qt-5/plugins-howto.html#the-low-level-api-extending-qt-applications
