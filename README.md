# INF224-TP-Multimedia
Travaux pratiques de Paradigmes de Programmation

## Questions

### 4e Étape

#### Comment appelle-t'on ce type de méthode et comment faut-il les déclarer ?
C'est appelé un méthode *abstraite*. On les déclare comme:
**virtual**` <`*type_retour*`> <`*nom_fonction*`> (<`*parametres*`>) = 0;`

#### Si vous avez fait correctement ce qui précède, il ne sera plus possible d'instancer des objets de la classe de base. Pourquoi ?
Maintenant, la classe de base est une classe abstraite, parcequ'elle a un méthode abstrait (qui n'est pas défini). Les classes abstraites ne peuvent pas être instancées.

### 5e Étape

#### Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ?
Le polymorphisme.

#### Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ?
En C++, on doit avoir une superclasse commune entre les objets et les traiter comme s'ils étaient des instances de la superclasse.

####Quel est le type des éléments du tableau : est-ce que ce tableau contient les objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java.
Le tableau contient des pointeurs vers les objets. On ne peut pas créer un tableau avec les objets directement parce que leur superclasse est abstraite. En C++ il n'est pas possible de déclarer un tableau qui contient des classes abstraites. En Java, le tableau serais aussi composé par des "pointeurs", mais en Java on ne les voit pas. Quand on utilise des instances d'une classe, on utilise toujours des références.

### 6e Étape

#### Que faut-il faire pour que l'objet `Film` ait plein contrôle sur ses données et que son tableau de durées des chapitres ne puisse pas être modifié (ou pire, détruit) à son insu ? (c'est l'objet qui doit pouvoir modifier ce qui lui appartient, pas les autres !)
Il faut que le modifieur n'utilise pas le tableau passé comme parametre, mais qu'il crée un nouveau tableau avec le même contenu.

### 7e Étape

#### Parmi les classes précédemment écrites quelles sont celles qu'il faut modifier afin qu'il n'y ait pas de fuite mémoire quand on détruit leurs instances ?
Seulement `Film`. C'est la seule classe qui a des pointeurs.

#### De même, la copie d'objets peut poser problème dans certains cas. Pourquoi et que faudrait-il faire ?
Si on fait une copie superficielle deux objets ont une référence à un seule objet. Si un des deux modifie cet objet, on peut avoir un comportement étrange. En certaines situations, ce qu'on veut faire c'est une copie profonde pour garantir que les deux objets sont indépendents.

### 8e Étape

#### On rappelle aussi que la liste d'objets doit en fait être une liste de pointeurs d'objets. Pourquoi ? Comparer à Java.
Si on fait une liste d'objets, les objets seront copiés dans la liste. Ce qu'on veut est d'avoir une reference pour qu'on puisse avoir le même objet referencé en plusieurs endroits.

### 11e Étape

#### Votre méthode processRequest() devra pouvoir accéder aux données de la classe créée à la question précédente (`MultimediaFactory`). Sachant que cette méthode peut appartenir à n'importe quelle classe, quelle est la solution la plus simple ?

La solution la plus simple est de créer une nouvelle classe qui traite les requests et appelle les méthodes qu'il faut. 
