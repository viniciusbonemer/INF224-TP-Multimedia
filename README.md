# INF224-TP-Multimedia
Travaux pratiques de Paradigmes de Programmation

## Questions

### 4e Étape

#### Comment appelle-t'on ce type de méthode et comment faut-il les déclarer ?
C'est appelé un méthode *abstraite*. On les déclare comme:
**virtual**` <`*type_retour*`> <`*nom_fonction*`> (<`*parametres*`>) = 0;`

#### Si vous avez fait correctement ce qui précède, il ne sera plus possible d'instancer des objets de la classe de base. Pourquoi ?
Maintenant, la classe de base est une classe abstraite, parcequ'elle a un méthode abstrait (qui n'est pas défini). Les classes abstraites ne peuvent pas être instancées.
