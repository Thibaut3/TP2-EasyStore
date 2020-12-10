# TP2-EasyStore

BRACQ Colin - JUILLARD Thibaut

Ce TP consiste à concevoir une application de magasin en ligne nommé EasyStore. Ce TP vous permettra d'utiliser les références, les pointeurs et les allocations dynamiques.

La gestion de ce magasin nécessite la création de plusieurs classes : Produit, Client, Commande.

Un Produit peut être constitué des informations suivantes :

Un titre (ex : « PS4 »),
Une description (ex : « Console de jeu de marque Sony »),
Une quantité disponible (ex : 10),
Un prix unitaire (ex : 249,99€).
Un Client peut être constituée des informations suivantes :

Un prénom (ex : « Dominique »),
Un nom (ex : « Ginhac »),
Un panier d'achat, c'est-à-dire un tableau de produits sélectionnés qui sont attente de validation pour la commande. Une fois la commande validée, le panier d'achat est vidé automatiquement.
Une Commande peut être constitué des informations suivantes :

Un client,
Un tableau des produits commandés,
Un statut de la commande (Ex : livrée / pas livrée).
Attention, pour chacune de ses classes, vous devez vous assurer qu'on puisse bien identifier les objets. Certaines de ces classes ont peut-être besoin d'identifiants supplémentaires. Typiquement, la classe Client nécessite un identifiant unique car le nom / prénom n'est pas unique (homonymes).

Le magasin EasyStore est représenté sous la forme d'une classe Magasin comprenant impérativement les éléments suivants :

Un tableau de pointeurs vers des Produits (std::vector<Product*> m_products)
Un tableau de pointeurs vers des Clients (std::vector<Client*> m_clients)
Un tableau de pointeurs vers des Commandes (std::vector<Order*> m_orders)
L'utilisation des pointeurs et la gestion dynamique (avec les opérateurs new et delete) des différents éléments (Produits, Clients, Commandes) vous permettra de vous familiariser avec les principes clés de l'allocation dynamique.

Pour chacune des questions, on suppose que tous les paramètres passés aux constructeurs des classes sont valides, ce qui permet de créer les objets.

Par contre, il est indispensable de s'assurer au préalable que ces paramètres sont bons. Par exemple, avant de valider une commande, il est nécessaire de vérifier que le produit est disponible.
