# iifrotaimperial
Olimpíadas Nacionais de Informática

http://www.dcc.fc.up.pt/oni/problemas/2013/qualificacao/probA.html

<h1>Problema A - Frota Imperial</h1>

O maníaco Palpatine é o Imperador e supremo líder do Império Galáctico. Para que o seu regime possa manter o controlo sobre todas as galáxias, Palpatine necessita de uma enorme frota imperial constituída por milhões de diferentes naves espaciais. Para facilitar a tarefa logística de coordenar toda esta frota, o Imperador decidiu numerar todas as naves com números inteiros consecutivos, começando no número 1. Sempre que uma nova nave sai de um estaleiro espacial recebe o primeiro número livre que nunca tenha sido antes atribuído.

Recentemente, Palpatine requisitou uma escolta para poder visitar Naboo, o planeta onde nasceu. O esquadrão escolhido corresponde a um conjunto de naves numeradas consecutivamente, tal como em todas as suas outras viagens anteriores. Em particular, eram as naves 88, 89 e 90. Palpatine reparou com agrado que o dígito (ou algarismo) 8, o seu favorito, era o mais frequente nos números destas naves, pois aparecia três vezes (o dígito 9 aparece duas vezes e o dígito 0 uma vez). Como a sua ânsia por poder era infinita (∞), nada como ter um dígito (8) que lhe fazia lembrar precisamente isso!

Palpatine pôs-se a pensar e reparou que numa viagem anterior tal não tinha acontecido e o dígito mais frequente era outro. Isto desagradou-lhe e decidiu que a partir de agora tal nunca mais iria acontecer. O problema é que os esquadrões são em tão quantidade que se torna complicado contar os dígitos manualmente. Como Grande Almirante do Império Galáctico, tens de ajudar o Imperador. Sabendo que os esquadrões a considerar estão sempre numerados consecutivamente, qual é o dígito que aparece mais vezes? E quantas vezes aparece?

<h2>O Problema</h2>

Dada um conjunto de N intervalos de números, a tua tarefa é descobrir, para cada intervalo, qual o(s) dígito(s) que aparece mais vezes, bem como quantas vezes ele aparece.

<h2>Input</h2>

Na primeira linha vem um único número inteiro N, indicando a quantidade de intervalos a considerar.

Nas N linhas seguintes vem um par de números Ai Bi (separados por um espaço), indicando que i-ésimo intervalo de números a considerar é [A,B] (ou seja, os números de A a B, inclusive).

<h2>Output</h2>

O output deve ser constituído por N linhas, uma para cada um dos intervalos do input. Cada uma destas linhas deve começar por ter um número inteiro indicando quantas vezes aparece o dígito mais frequente, seguida de uma lista (por ordem crescente) dos dígitos que aparecem com essa frequência máxima. Todos os números de uma mesma linha devem ser separados por um único espaço.

<h2>Restrições</h2>

São garantidos os seguintes limites em todos os casos de teste que irão ser colocados ao programa:

```
1 ≤ N ≤ 1 000                  Número de intervalos a considerar
1 ≤ A ≤ B ≤ 1 000 000 000      Limites de cada intervalo
```

<h2>Nota sobre a avaliação</h2>

Para um conjunto de casos de teste valendo 30% dos pontos, acontece sempre que A ≤ B ≤ 1 000.

Para um conjunto de casos de teste valendo 60% dos pontos, acontece sempre que A ≤ B ≤ 1 000 000

<h3>Exemplo de Input</h3>

```
4
88 90
99 100
1 9
1 10
```

<h3>Exemplo de Output</h3>

```
3 8
2 0 9
1 1 2 3 4 5 6 7 8 9
2 1
```

<h3>Explicação do Input/Output</h3>

A primeira linha do output, 3 8, indica que para o primeiro intervalo (que era [88,90] o dígito que aparece mais vezes é o 8, e que aparece três vezes. A segunda linha, 2 0 9 diz respeito ao segundo caso ([99,100]) e diz que os dígitos que aparecem mais vezes são o 0 e 9, sendo que aparecem duas vezes cada um. A terceira linha diz respeito a [1,9] e diz que os dígitos 1, 2, 3, 4, 5, 6, 7, 8 e 9 são os que aparecem mais vezes (uma vez, neste caso). Finalmente, a quarta linha diz que no intervalo [1,10] o dígito mais frequente é o 1, que aparece duas vezes.
