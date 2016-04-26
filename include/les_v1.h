// Defining a new type .
struct SLLNode {
// Struct for a Single Linked List Node .
int miData ;
// List stores integers .
SLLNode * mpNext ; // Points to next node in list .
};

using SNPtr = SLLNode *; 

/**Imprime os números inteiros da lista,
na mesma sequência que estão armazenados na lista, no formato “{ a 1 , a 2 , a 3 , . . . , a n }”,
 onde a i quer dizer o i-éesimo elemento da lista*/
void print( SNPtr _pAIL );

/**
Calcula e retorna o comprimento atual da lista. O compri-
mento deve ser zero, caso a lista esteja vazia.
*/
int length( SNPtr _pAIL );

/**
Retorna verdadeiro caso a lista esteja vazia; ou falso, caso
contrário.
*/
bool empty( SNPtr _pAIL );

/**
Remove todos os elementos da lista, libera a memória
alocada e faz o apontador de início de lista apontar para nullptr , indicando lista vazia.
*/
void clear( SNPtr & _pAIL );

/**
Recupera no segundo parˆametro
o primeiro elemento da lista (sem removˆe-lo) e retorna verdadeiro; ou falso, caso a lista esteja
vazia.
*/
bool front( SNPtr _pAIL, int & _retrievedVal );

/**
Recupera no segundo parˆametro o
último elemento da lista (sem removˆe-lo) e retorna verdadeiro; ou falso, caso a lista esteja
vazia.
*/
bool back( SNPtr _pAIL, int & _retrievedVal );

/**
Cria um novo nó na lista contendo
o valor do segundo parˆametro e o insere na frente da lista. Se a operação for bem sucedida, a
função deve retornar verdadeiro; ou falso, caso contrário.
*/
bool pushFront( SNPtr & _pAIL, int _newVal );

/**
Cria um novo nó na lista contendo o
valor do segundo parˆametro e o insere no final da lista. Se a opera ̧c ̃ao for bem sucedida, a
função deve retornar verdadeiro; ou falso, caso contrário.
*/
bool pushBack( SNPtr & _pAIL, int _newVal );

/**
Se a lista possuir um ou
mais elementos, a função recupera o primeiro elemento no segundo parˆametro, remove-o da
lista e retorna verdadeiro; caso contrário retorna falso.
*/
bool popFront( SNPtr & _pAIL, int & _retrievedVal );

/**
Se a lista possuir um ou mais
elementos, a função recupera o u
 último elemento no segundo parˆametro, remove-o da lista e
retorna verdadeiro; caso contrário retorna falso.
*/
bool popBack( SNPtr & _pAIL, int & _retrievedVal );

/**
Busca na lista, a partir do primeiro nó primeira ocorrˆencia do valor indicado no segundo parˆametro e retorna um apontador para o
nó imediatamente anterior ao nó procurado. Se o nó procurado for (a) o primeiro elemento
da lista ou (b) a lista for vazia a função retorna nullptr . Para diferenciar os dois casos
basta verificar se o AIL da lista é diferente de nulo, caracterizando o caso (a). Desafio: E se
quis ́essemos encontrar a 2 a ocorrˆencia de _targetVal ? Ou a 3 a ?
*/
SNPtr find( SNPtr _pAIL, int _targetVal);

/**
*/
bool insert( SNPtr & _pAIL, SNPtr _pAnte, int _newVal );
bool remove( SNPtr & _pAIL, SNPtr _pAnte, int & _retrievedVal );

