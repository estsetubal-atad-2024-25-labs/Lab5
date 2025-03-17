# Algoritmos e Tipos Abstratos de Dados

## Lab 5 - Formalização de algoritmos e recursividade

Este repositório foi criado a partir de:

- <https://github.com/estsetubal-atad/CProgram_Template> 

Consulte o README se tiver dúvidas sobre a sua utilização.

----

**Objetivos**:

- Formalização de algoritmos;
  
- Eficiência vs. Eficácia;
  
- Recursividade;

**Referências**:

- Slides TP, disponíveis no Moodle.

----

### 1 | Experimentação

> :bulb:  
> Faça o clone **deste** repositório antes de avançar.  
> Contém o módulo `arrays` onde irá modificar/adicionar funções.

1. Analise o código existente no módulo `arrays` e na função `main`. Compile e execute o programa;

2. Pergunte ao ChatGPT :robot:: "No contexto de um algoritmo, qual a diferença entre eficiência e eficácia?". Retenha os conceitos;

3. Otimize o algoritmo de ordenação *bubble sort* por forma a terminar quando a sequência já se encontrar ordenada. Confira a eficácia da implementação resultante.

    - :bulb: A sequência já se encontra ordenada quando, durante um varrimento, não houver trocas.

4. :question: A otimização do ponto anterior melhorou a *eficiência* e/ou *eficácia* do algoritmo? Discuta ou peça ajuda ao ChatGPT para compreender efetivamente o que foi obtido com esta otimização.

5. No `main.c` aumente o tamanho do array (`TEST_SIZE`) para **100k** (cem mil) e depois para **1m** (um milhão). Compile e execute o programa a cada aumento.

    - :warning: A ordenação na última situação poderá não ser obtida em tempo útil; pode fazer `Ctrl + C` para interromper a execução.

    - :question: Que conclusões tira sobre a eficiência do algoritmo *bubble sort* para sequências muito grandes?

### 2 | Algoritmo de ordenação Quicksort

6. Consulte a **adenda** (no final deste enunciado) onde está descrito o algoritmo de ordenação *Quicksort*. 

    - Implemente ambas as funções descritas no ficheiro `arrays.c` com o modificador `static` (analogamente à função `swap`, dado que só serão utilizadas dentro deste ficheiro).

    - Modifique a implementação da função `arrSort` por forma a invocar este algoritmo:

        ```cpp
        void arrSort(int *arr, int arrLength) {
            if(!arr || arrLength <= 0) return;
            
            quickSort(arr, 0, arrLength - 1);

            // ... código existente comentado
        }
        ```

    - Compile e execute o programa novamente.

7. :question: De acordo com os conceitos de *eficiência* e *eficácia*, assinale todas as respostas corretas:

    - [ ] **A)** O Bubble Sort é sempre eficaz, pois ordena corretamente os elementos da lista.  

    - [ ] **B)** O Quick Sort pode ser ineficiente no pior caso, mas continua sendo eficaz se implementado corretamente.  

    - [ ] **C)** A eficiência do Bubble Sort no pior caso é melhor do que a do Quick Sort.  

    - [ ] **D)** O Bubble Sort pode ser otimizado para interromper a execução se a lista já estiver ordenada, reduzindo o número de iterações desnecessárias.  

    - [ ] **E)** O Quick Sort é geralmente mais eficiente que o Bubble Sort devido à sua complexidade média de `O(n log n)`.  

    - [ ] **F)** O Bubble Sort é mais eficiente que o Quick Sort para grandes volumes de dados.  

### 3 | Pesquisa binária

8. Consulte a **adenda** onde se descreve o algoritmo **recursivo** de pesquisa binária;

9. Complete o seguinte pseudo-código de acordo com a descrição anterior:

    ```markdown
    Algorithm binarySearch
        input: val - integer
            arr - array of integers
            start - start index for search - natural number
            end - end index for search - natural number
        output: arr index of val; -1 if not found - integer
    BEGIN
        IF start > end THEN
            RETURN -1

        mid <- (start + end) / 2

        IF arr[mid] = val THEN
            RETURN mid
        ELSE IF arr[mid] > val THEN
            RETURN /* TODO */
        ELSE
            RETURN /* TODO */
        END IF 
    END
    ```

10. Implemente a função anterior no ficheiro `arrays.c` com o modificador `static`.

11. Adicione ao módulo `arrays` a função:

    ```cpp
    int arrBinarySearch(int *arr, int arrLength) {
        return binarySearch(arr, 0, arrLength - 1);
    }
    ```

    - Teste esta função no `main`, sobre uma sequência ordenada.

### 4 | Recursividade e a memória *stack*

12. Coloque o seguinte código no [PythonTutor](https://pythontutor.com/c.html#mode=edit) e execute-o passo-a-passo, visualizando como as invocações recursivas são mantidas na memória *stack* até que um critério de paragem seja atingido.

    ```cpp
    #include <stdio.h>
    #include <string.h>

    void reverseString(char str[], int left, int right) {
        if (left >= right) return;
        
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        
        reverseString(str, left + 1, right - 1);
    }

    int main() {
        char str[] = "hello, world";
        reverseString(str, 0, strlen(str) - 1);
        printf("Reversed string: %s\n", str);
        return 0;
    }
    ```

### Adenda | Formalização de algoritmos

#### Algoritmo de ordenação Quicksort

O algoritmo [*quicksort*](https://en.wikipedia.org/wiki/Quicksort) é um algoritmo de ordenação assente no princípio "dividir-para-conquistar" e pode ser implementado de forma **recursiva**. A sua complexidade algorítmica *average-case* é de `O(n log n)`; em condições muito particulares (raras), a sua complexidade *worst-case* pode degenerar em `O(n^2)`.

A sua formalização em pseudo-código é apresentada de seguida:

```markdown
Algorithm quickSort
    input: arr - array of integers
           low - starting index for sorting - natural number
           high - ending index for sorting - natural number
    output: sorted arr (in-place)
BEGIN
    IF low < high THEN
        pi <- partition(arr, low, high)
        
        quickSort(arr, low, pi - 1)  // Sort left partition
        quickSort(arr, pi + 1, high) // Sort right partition
    END IF
END

Algorithm partition
    input: arr - array of integers
           low - starting index - natural number
           high - ending index - natural number
    output: partition index - natural number
BEGIN
    pivot <- arr[high]
    i <- low - 1  // Index of smaller element
    
    FOR j <- low TO high - 1 DO
        IF arr[j] < pivot THEN
            i <- i + 1
            swap arr[i] and arr[j]
        END IF
    END FOR

    swap arr[i + 1] and arr[high]
    RETURN i + 1
END
```

#### Algoritmo recursivo de Pesquisa Binária

A **pesquisa binária** é um algoritmo eficiente para encontrar um elemento dentro de uma sequência **ordenada**. Funciona dividindo repetidamente a sequência ao meio até encontrar o elemento desejado ou determinar que ele não está presente.  

##### **Formalização em linguagem natural**  

1. **Definir os limites**: Começamos com dois índices, um apontando para o primeiro elemento (esquerda) e outro para o último elemento (direita) da sequência.  

2. **Encontrar o meio**: Calculamos o índice do elemento central da sequência.  

3. **Comparação**:  
   - Se o elemento do meio for o valor procurado, a busca termina com sucesso.  
   - Se o valor procurado for **menor** que o elemento do meio, repetimos a busca na **metade esquerda** da sequência.  
   - Se o valor procurado for **maior** que o elemento do meio, repetimos a busca na **metade direita** da sequência.  

4. **Repetição**: Continuamos dividindo a sequência e ajustando os limites até encontrar o elemento ou até que os limites se cruzem, indicando que o elemento não está na lista.  

##### **Características do algoritmo**  
- **Requisitos**: A sequência deve estar **ordenada** previamente.  
- **Complexidade**: No pior caso, precisa de `O(log n)` comparações, o que é muito mais eficiente do que a pesquisa linear `O(n)` para sequências grandes.  
- **Aplicações**: Usado em pesquisa de bases de dados, sistemas de arquivos, árvores binárias e outras áreas onde a eficiência é crucial.  

Este método é muito eficiente porque reduz o espaço de pesquisa pela metade a cada passo. A figura seguinte ilustra a pesquisa (com sucesso) do número `19` numa sequência ordenada:

![](binarySearch.png)

----

bruno.silva@estsetubal.ips.pt
