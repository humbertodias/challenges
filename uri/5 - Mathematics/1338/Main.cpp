/* Maratona USP 2010
 * Problema C: It-miha
 *
 * Um número é de It-miha se e somente se ele não é divisível pelo quadrado de
 * nenhum primo. Se I é o conjunto dos números de It-miha, N* é o conjunto dos
 * inteiros positivos e kA, onde k é inteiro e A é um conjunto de inteiros, é
 * o conjunto dos elementos de A multiplicados por k, então
 *
 *   I = N* - (4 N* | 9 N* | 25 N* | 49 N* | 121 N* | ... | p^2 N* | ...)
 *
 * onde | significa união e a união é feita sobre todos os primos.
 *
 * Dado um inteiro positivo n, achar todos os elementos de I menores ou iguais
 * a n é possível pelo princípio da inclusão-exclusão:
 *
 *   #(I <= n) = #(N* <= n) -
 *             - #(4 N* <= n) - #(9 N* <= n) - #(25 N* <= n) - ... +
 *             + #[(4 N* <= n) & (9 N* <= n)] + #[(4 N* <= n) & (25 N* <= n)] +
 *             + #[(9 N* <= n) & (25 N* <= n)] + ... -
 *             - #[(4 N* <= n) & (9 N* <= n) & (25 N* <= n)] - ... +
 *             + ... et cetera
 *
 * onde (A <= n) é o conjunto dos elementos de A menores ou iguais a n e &
 * indica interseção.
 *
 * As duas observações cruciais são as seguintes:
 *
 *   1. (p N* <= n) & (q N* <= n) = (pq N* <= n);
 *   2. #(k N* <= n) = 0 para todo k > n.
 *
 * Como todos os multiplicadores de N* são quadrados perfeitos, no máximo
 * sqrt(n) termos são não-nulos.
 *
 * Ademais, o sinal da cardinalidade de #(k N* <= n) no somatório acima depende
 * apenas de k e não de n, e portanto pode ser pré-computado. Finalmente, é
 * óbvio que #(k N* <= n) = piso(n / k). Como piso(n / k) é não decrescente,
 * podemos guardar uma lista dos possíveis valores de k em ordem crescente
 * (com os respectivos sinais) e iterar sobre ela, parando assim que k > n.
 *
 * No entanto, nós temos o problema oposto aqui: dado k, queremos saber o n
 * para o qual #(I <= n) = k, mas sabendo calcular esta cardinalidade o
 * problema torna-se uma busca binária: a resposta é o menor n para o qual
 * #(I <= n) >= k.
 */

#include <cstdio>
#include <set>
#include <utility>
#include <cstdint> // include this header for uint64_t

using namespace std;

typedef unsigned long long uint64;

/* Valor máximo de N. */
const uint64 MAX_N = 20000000000;

/* .first:  multiplicador de N*; sempre um quadrado perfeito.
 * .second: sinal da contribuição de #(k N* <= n); sempre +1 ou -1.
 */
typedef pair<uint64, int> divisor;
set<divisor> terms;

/* Decide se p é primo. */
static bool is_prime(uint64 p) {
  /* Como essa função só é usada para pré-computar o vetor de termos e p é
   * no máximo 200000, qualquer coisa serve aqui. */
  for (uint64 d = 2; d <= p / d; d++) {
    if (p % d == 0) return false;
  }
  return true;
}

/* Popula o vetor de termos da inclusão-exclusão. */
static void precompute() {
  terms.clear();
  /* N* é o primeiro termo, com sinal positivo. */
  terms.insert(make_pair(1, +1));
  /* Para todos os primos menores que sqrt(2 * 10**10) < 2 * 10**5... */
  for (uint64 p = 2; p < 200000; p++) {
    if (!is_prime(p)) continue;
    /* ...encontramos todos os termos com multiplicador divisível por p. Para
     * não contar potências maiores do mesmo primo, colocamos todos os termos
     * em um set separado que depois é unido ao set de termos original. */
    set<divisor> new_terms;
    for (set<divisor>::iterator it = terms.begin(); it != terms.end(); it++) {
      /* Dados x e y inteiros positivos, x * y <= M se e somente se
       * x <= M / y; como x é inteiro, isso é equivalente a x <= piso(M / y).
       */
      if (p * p <= 2 * MAX_N / it->first) {
        new_terms.insert(make_pair(it->first * p * p, -it->second));
      } else break;
    }
    for (set<divisor>::iterator it = new_terms.begin();
         it != new_terms.end(); it++) {
      terms.insert(*it);
    }
  }
}

/* Calcula #(I <= n). */
static uint64 count_itmiha(uint64 n) {
  /* Total acumulado até agora. */
  uint64 tally = 0;
  for (set<divisor>::iterator it = terms.begin(); it != terms.end(); it++) {
    uint64_t count = n / it->first;
    if (count == 0) {
      /* A partir de agora, todos os termos são nulos. */
      break;
    }
    if (it->second == +1) {
      tally += count;
    } else {
      tally -= count;
    }
  }
  return tally;
}

/* Acha o k-ésimo número de It-miha. */
static uint64 find_itmiha(uint64 k) {
  /* Limites da busca binária: os invariantes são
   *   1. #(I <= lo) < k;
   *   2. #(I <= hi) >= k.
   */
  uint64 lo = 0;
  /*   #(I <= n) = #(N* <= n) - #(4 N* <= n) - #(9 N* <= n) -
   *             - #(25 N* <= n) - #(49 N* <= n) - #(121 N* <= n) - ... >=
   *               (tirando os pisos)
   *            >= n - (n/4 + n/9 + n/25 + n/49 + n/121 + ...) >=
   *               (adicionando os não-primos)
   *            >= n - (n/4 + n/9 + n/16 + n/25 + n/36 + ...) =
   *             = n * (2 - (1/1 + 1/4 + 1/9 + 1/16 + 1/25 + 1/36 + ...) =
   *             = n * (2 - pi^2/6) >=
   *            >= n * (2 - 9/6) = n/2.
   */
  uint64 hi = 2 * MAX_N;
  while (hi - lo > 1) {
    /* Evitar overflow. */
    uint64 mid = lo + (hi - lo) / 2;
    if (count_itmiha(mid) >= k) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  /* A resposta é o menor n para o qual #(I <= n) >= k. */
  return hi;
}

int main() {
  precompute();
  int T;
  scanf(" %d", &T);
  for (int h = 0; h < T; h++) {
    uint64 N;
    scanf(" %llu", &N);
    printf("%llu\n", find_itmiha(N));
  }
  return 0;
}
