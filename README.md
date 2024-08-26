# Spell Guard 🧙

O mundo assim como no principio se torna escuro e vazio, com a calamidade das criaturas com a soberania Skulls Archers, que a todo custo querem o mundo a sua imagem e semelhança. Apenas o nosso herói pode mudar a história completando sua invocação arcana de poderoso nivel para trazer a luz novamente.

### Requisitos
- estar em um ambiente Windows (preferencialmente);
- Possuir o GCC 13.1.0 ou versão superior;
- De preferência, estar utilizando o Visual Studio Code;
- Possuir o `make` instalado;
- Doxygen (para documentação).

### Compilação
Basta digitar `make` ou `mingw32-make` para compilar o programa.

### Execução
Apenas abra seu terminal dentro do diretório do projeto e digite:
```bash 
./bin/app
```

### Documentação
Para ter acesso a uma documentação mais complexa do jogo, você pode instalar a ferramenta `doxygen` e, no diretório raiz, digitar
```bash
doxygen
```
No novo diretório `docs`, procure pelo arquivo `html/index.html` e clique nele.
Agora você tem acesso à documentação completa e mais detalhada do nosso código fonte.

### Sobre o Jogo
Spell Guard é um jogo de defesa de base em que inimigos surgem no mapa com o objetivo de destruir a base. Seu objetivo é proteger a base durante um tempo determinado.

#### Herói
Um Mago a procura de proteger seu Circulo Arcano de Invocação para cessar a escuridão e trazer luz ao mundo novamente.

- Vida: 100 pontos fixo.
- Regeneração: Ao coletar poções de vida dropadas pelos inimigos.
- Mana: 50 pontos, usados para lançar projéteis.
- Movimento: O herói se move em direção ao ponto clicado com o botão direito do mouse. Se o botão direito for mantido pressionado, o herói segue o cursor do mouse.
- Área de Ação: O herói pode se mover livremente dentro e fora da base.
- Ataque: O herói pode disparar projéteis pressionando a tecla Q, com alcance limitado, na direção do cursor do mouse.

#### Inimigos
Os Skull Archers. Criaturas das trevas que tentam a todo custo propagar a escuridão pelo mundo, através de suas flechas e medo.

- Spawn: Surgem aleatoriamente nas bordas do mapa em intervalos fixos de tempo, que podem diminuir conforme a dificuldade aumenta.
- Vida: Os inimigos tem sua vida determinada pela dificuldade do jogo.
- Movimento: Os inimigos se movem em direção ao centro da base ou ao herói.
- Ataque: Disparam projéteis em direção ao herói aumentando o dano conforme a dificuldade.
- Interações: Os projéteis podem colidir com o herói, com outros inimigos, ou com a base.
- Drops: Ao serem derrotados, os inimigos deixam itens (mana e poção de vida) que podem ser coletados pelo herói. Esses itens desaparecem após certo tempo se não forem coletados.

#### Base
Circulo Arcano de Invocação poderoso, capaz de salvar o mundo da escuridão iminente.

- Vida: A base tem sua vida determinada pela dificuldade do jogo.
- Regeneração: A base regenera sua vida ao longo do tempo, aumentando o tempo conforme a dificuldade.
- Condição de Derrota: O jogo termina se a base for destruída ou se o herói morrer.
- Condição de Vitória: O jogo termina se a base for protegida durante o tempo determinado.

#### Dificuldades
Antes de iniciar o jogo, o usuário é direcionado para a escolha de dificuldade. As opções são:

##### Fácil:
- Vida da Base: 1000 pontos
- Regeneração: 10 segundos
- Intervalo de Spawn: 5 segundos
- Duração do Jogo: 91 segundos
- Vida do Inimigo: 25 pontos
- Dano do Inimigo: 5 pontos

##### Médio:
- Vida da Base: 800 pontos
- Regeneração: 15 segundos
- Intervalo de Spawn: 3 segundos
- Duração do Jogo: 121 segundos
- Vida do Inimigo: 50 pontos
- Dano do Inimigo: 10 pontos

##### Difícil:
- Vida da Base: 600 pontos
- Regeneração: 20 segundos
- Intervalo de Spawn: 3 segundos
- Duração do Jogo: 181 segundos
- Vida do Inimigo: 75 pontos
- Dano do Inimigo: 15 pontos

#### Como Jogar
##### Menu: Ao iniciar o jogo, você será levado ao menu principal, onde pode selecionar a dificuldade e iniciar o jogo.
##### Movimentação: Use o botão direito do mouse para definir o destino do herói. 
##### Ataque: Pressione Q para disparar projéteis em direção ao cursor do mouse.
##### Proteger a Base: Derrote inimigos e colete mana para se fortalecer.
##### Sobrevivência: Proteja a base pelo tempo determinado ou até que todos os inimigos sejam derrotados.

### Estrutura do Código
O código está organizado em classes e módulos, incluindo:
- Menu: Controla o fluxo de escolha do usuário ao executar o programa.
- Game: Controla o fluxo principal do jogo, como o estado atual, inicialização de objetos, renderização e lógica de jogo.
- Hero: Representa o herói controlado pelo jogador.
- Enemy: Representa os inimigos que surgem no mapa.
- Base: Representa a base que deve ser protegida.
- Drop: Itens que podem ser coletados pelo herói.

Para uma melhor visualização, visite a seção **Documentação.**

#### Criação de Objetos e Lógica de Jogo
- Inicialização: Cada objeto é inicializado com atributos específicos, como vida, velocidade e posição.
- Atualização: Durante o jogo, todos os objetos são atualizados em tempo real, incluindo movimento, ataques e colisões.
- Colisões: A detecção de colisões é gerenciada para interações entre projéteis, herói, inimigos e base.
- Herança: Foi criada uma classe pai denominada <i>Entity</i>, que contém métodos e atributos comuns a todos os objetos do jogo. A partir dessa classe, foram derivadas as classes filhas <i>Base</i> e <i>Character</i>. A classe <i>Character</i> foi dividida em duas subclasses: <i>Hero</i> e <i>Enemy</i>. Cada uma dessas classes herda os atributos e métodos comuns de <i>Entity</i>, permitindo que compartilhem comportamentos básicos enquanto ainda podem definir seus próprios comportamentos específicos.
- Polimorfismo: Para permitir que diferentes classes possam ter comportamentos específicos, alguns métodos foram declarados como <i>virtual</i>, permitindo que as classes derivadas sobrescrevam esses métodos e implementem comportamentos específicos. Isso permite, por exemplo, que tanto o herói quanto os inimigos tenham métodos de movimento ou ataque com comportamentos diferentes, mas ainda sejam chamados de forma genérica através de um ponteiro ou referência da classe pai.
- Métodos Genéricos: Foram implementados métodos genéricos para realizar operações comuns em diferentes tipos de objetos do jogo, como a função `calculateCollisionsWithProjectiles`, presente em _Game_, que recebe uma lista de projéteis e outra de objetos derivados de _Entity_, ou a função `useItem` de _Hero_, que pode consumir qualquer item desde que este seja derivado de _Item_.

#### Funcionalidades Implementadas

- Movimentação do Herói: O herói pode se mover em qualquer direção ao clicar no mapa com o botão direito do mouse.
- Disparo de Projéteis pelo Herói: O herói dispara projéteis na direção do cursor ao pressionar a tecla "Q".
- Diferentes Texturas: Sprites para entidades, telas, fontes, etc.
- Animações: Animaçõs em diversos momentos, como caminhar, atacar, projéteis, etc...
- Sons: Trilhas e efeitos sonoros.
- Vida do Herói: O herói tem vida limitada a 100.
- Inimigos: Inimigos surgem aleatoriamente nas bordas do mapa e caminham em direção à base.
- Colisão de Projéteis: Projéteis podem colidir com o herói, inimigos, ou a base.
- Drop: Itens de vida e munição deixados pelos inimigos abatidos.
- Coleta de Projéteis: Herói pode coletar projéteis deixados pelos inimigos abatidos.
- Quantidade Limitada de Projéteis do Herói.
- Disparo de Projéteis pelos Inimigos em Direção ao Herói
- Regeneração da Base: A base regenera sua estrutura ao longo do tempo.
- Menu com opções de jogar, créditos e sair.
- Dificuldade: Três niveís diferentes de dificuldades, alternando entre Fácil, Normal e Difícil.
- Finalização do Jogo: Condições de vitória\derrota baseadas no tempo, na destruição da base ou na morte do herói.
- Game Over e Game Win.
- Utilização de Smart Pointers para gerenciamento automático da memória.
- Documentação com Doxygen.

#### Possíveis Erros 
- As animações nem sempre respondem corretamente.

#### Funcionalidades Não Implementadas
- Pause: Foi iniciada a implementação do Pause, contudo não finalizada.
- Animações pendentes: Animações como dano ou regeneração de vida ou mana.
- Diferentes tipos de inimigos: A ideia foi posta em prática, contudo não andou.
- Ataque Corpo a Corpo: Foi iniciada a implementação do dano Corpo a Corpo, porém havia alguns erros com a colisão.


### Considerações Finais
Aproveite o jogo e defenda sua base com estratégia e habilidade! Se tiver sugestões ou encontrar algum bug, sinta-se à vontade para contribuir no repositório com o seu próprio `pull request`.
