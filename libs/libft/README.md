<p align ="center">
	<img src="images/../../images/fase1/libft.png">
</p>

<p>
	<h1> Libft </h1>
</p>

<p>
	O libft é o primeiro projeto da 42, onde recriamos funções da biblioteca padrão do C e outras adicionais, visando a utilização durante a resolução dos futuros projetos do programa.
</p>

<p>
	<h2> Pontuação </h2>
</p>
<p>
	<img src="images/../../images/100.jpg">
</p>

<p>
	<h2> Como usar a biblioteca: </h2>
</p>


<p>
	Para usar a biblioteca nas suas funções, inclua o header:
</p>

```c
#include "libft.h"
```

```bash
# Clone o projeto e entre na pasta
git clone git@github.com:gustavdlima/ecole_42.git && cd libft/

# Digite make para criar a biblioteca
make

# Se quiser funções para lista encadeada, digite make bonus
make bonus

# Compile o seu main com a bliblioteca, por exemplo:
clang main.c libft.a

# Execute o programa
./a.out

# Limpe os objetos criados com
make fclean

# Fim!
```

<p>
	<h2>  Tabela de referência  </h2>
</p>

<table>
    <thead>
        <tr>
            <th colspan=3><h4>Biblioteca C <a href="https://www.tutorialspoint.com/c_standard_library/ctype_h.htm">&lt;ctype.h&gt;</h4></a></th>
        </tr>
        <tr>
            <th>Libft</th>
            <th>Descrição</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href=ft_isalnum.c>ft_isalnum</a></td>
            <td>Checa se o caracter passado é alfanumérico.</td>
        </tr>
        <tr>
            <td><a href=ft_isalpha.c>ft_isalpha</a></td>
            <td>Checa se o caracter passado é alfabético.</td>
        </tr>
        <tr>
            <td><a href=ft_isascii.c>ft_isascii</a></td>
            <td>Checa se o caracter passado é  ASCII.</td>
        </tr>
        <tr>
            <td><a href=ft_isdigit.c>ft_isdigit</a></td>
            <td>Checa se o caracter passado é  um decimal.</td>
        </tr>
        <tr>
            <td><a href=ft_isprint.c>ft_isprint</a></td>
            <td>Checa se o caracter passado é  printável.</td>
        </tr>
        <tr>
            <td><a href=ft_tolower.c>ft_tolower</a></td>
            <td>Converte letra maiúsculas em minúsculas.</td>
        </tr>
        <tr>
            <td><a href=ft_toupper.c>ft_toupper</a></td>
            <td>Converte letras minúsculas para maiúsculas.</td>
        </tr>
    </tbody>
    <thead>
        <tr>
            <th colspan=3><h4>Biblioteca C <a href="https://www.tutorialspoint.com/c_standard_library/string_h.htm">&lt;string.h&gt;</h4></a></th>
        </tr>
        <tr>
            <th>Libft</th>
            <th>Descrição</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href=ft_bzero.c>ft_bzero</a></td>
            <td>Apaga os dados em 'n' bytes no bloco de memória e seta zeros.</td>
        </tr>
        <tr>
            <td><a href=ft_memchr.c>ft_memchr</a></td>
            <td>Procura pela primeira ocorrência do caracter c nos primeiros 'n' byyes da string.</td>
        </tr>
        <tr>
            <td><a href=ft_memcmp.c>ft_memcmp</a></td>
            <td>Compara os primeiros 'n' bytes da str1 e str2.</td>
        </tr>
        <tr>
            <td><a href=ft_memcpy.c>ft_memcpy</a></td>
            <td>Copia 'n' caracteres do src para dest.</td>
        </tr>
        <tr>
            <td><a href=ft_memmove.c>ft_memmove</a></td>
            <td>Copia 'n' caracteres do src para o dst de forma não destrutiva.</td>
        </tr>
        <tr>
            <td><a href=ft_memset.c>ft_memset</a></td>
            <td>Copia o caractere c para os primeiros 'n' caracteres da string.</td>
        </tr>
        <tr>
            <td><a href=ft_strchr.c>ft_strchr</a></td>
            <td>Procura pela primeira ocorrência do caractere c na string.</td>
        </tr>
        <tr>
            <td><a href=ft_strlcat.c>ft_strlcat</a></td>
            <td>Acrescenta a string src ao final de dst.</td>
        </tr>
        <tr>
            <td><a href=ft_strlcpy.c>ft_strlcpy</a></td>
            <td>Copia até o tamanho dest - 1 caracteres da string src a dst.</td>
        </tr>
        <tr>
            <td><a href=ft_strlen.c>ft_strlen</a></td>
            <td>Computa o tamanho da string, mas não inclui caracteres NULL.</td>
        </tr>
        <tr>
            <td><a href=ft_strncmp.c>ft_strncmp</a></td>
            <td>Compara, no máximo, os primeiros 'n' bytes de str1 e str2.</td>
        </tr>
        <tr>
            <td><a href=ft_strnstr.c>ft_strnstr</a></td>
            <td>Localiza a primeira ocorrência da string pequena na string grande, onde não são pesquisados mais do que o tamanho passado.</td>
        </tr>
        <tr>
            <td><a href=ft_strrchr.c>ft_strrchr</a></td>
            <td>Procura a última ocorrência do carácter c na string.</td>
        </tr>
    </tbody>
    <thead>
        <tr>
            <th colspan=3><h4>C Library <a href="https://www.tutorialspoint.com/c_standard_library/stdlib_h.htm">&lt;stdlib.h&gt;</h4></a></th>
        </tr>
        <tr>
            <th>Libft</th>
            <th>Descrição</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href=ft_atoi.c>ft_atoi</a></td>
            <td>Converte string em inteiro.</td>
        </tr>
        <tr>
            <td><a href=ft_calloc.c>ft_calloc</a></td>
            <td>Aloca o espaço requisitado e inicializa com 0 bytes.</td>
        </tr>
    </tbody>
    <thead>
        <tr>
            <th colspan=3><h4>Biblioteca C não padrão</h4></a></th>
        </tr>
        <tr>
            <th>Libft</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href=ft_itoa.c>ft_itoa</a></td>
            <td>Converte inteiro em string (char *).</td>
        </tr>
        <tr>
            <td><a href=ft_putchar_fd.c>ft_putchar_fd</a></td>
            <td>Retorna o caracter c.</td>
        </tr>
        <tr>
            <td><a href=ft_putendl_fd.c>ft_putendl_fd</a></td>
            <td>Retorna a string seguido de uma nova linha.</td>
        </tr>
        <tr>
            <td><a href=ft_putnbr_fd.c>ft_putnbr_fd</a></td>
            <td>Retorna o inteiro.</td>
        </tr>
        <tr>
            <td><a href=ft_putstr_fd.c>ft_putstr_fd</a></td>
            <td>Retorna string.</td>
        </tr>
        <tr>
            <td><a href=ft_strdup.c>ft_strdup</a></td>
            <td>Retorna um ponteiro a uma string de bytes nulo, que é um duplicado da string.</td>
        </tr>
        <tr>
            <td><a href=ft_striteri.c>ft_striteri</a></td>
            <td>Aplica uma função a cada carácter da corda.</td>
        </tr>
        <tr>
            <td><a href=ft_strjoin.c>ft_strjoin</a></td>
            <td>Devolve uma nova string, que é o resultado da concatenação de 's1' e 's2'.</td>
        </tr>
        <tr>
            <td><a href=ft_strmapi.c>ft_strmapi</a></td>
            <td>Aplica uma função a cada carácter da string de caracteres para criar uma nova string</td>
        </tr>
        <tr>
            <td><a href=ft_strtrim.c>ft_strtrim</a></td>
            <td>Devolve uma cópia de 's1' com os caracteres especificados em 'set' removidos do início e do fim da string.</td>
        </tr>
        <tr>
            <td><a href=ft_substr.c>ft_substr</a></td>
            <td>Devolve uma substring da string 's'. A substring começa no índice 'start' e é de tamanho máximo 'len'.</td>
        </tr>
    </tbody>
    <thead>
        <tr>
            <th colspan=3><h4>Lista Encadeada</h4></a></th>
        </tr>
        <tr>
            <th>Libft</th>
            <th>Descrição</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href=ft_lstadd_back.c>ft_lstadd_back</a></td>
            <td>Acrescenta o elemento no final da lista.</td>
        </tr>
        <tr>
            <td><a href=ft_lstadd_front.c>ft_lstadd_front</a></td>
            <td>Adiciona o elemento no início da lista.</td>
        </tr>
        <tr>
            <td><a href=ft_lstclear.c>ft_lstclear</a></td>
            <td>Apaga e liberta o elemento dado e todos os sucessores desse elemento, utilizando uma dada função e liberando.</td>
        </tr>
        <tr>
            <td><a href=ft_lstdelone.c>ft_lstdelone</a></td>
            <td>Toma como parâmetro um elemento e libera a memória do conteúdo do elemento usando uma função dada como parâmetro e libera o elemento</td>
        </tr>
        <tr>
            <td><a href=ft_lstiter.c>ft_lstiter</a></td>
            <td>Itera a lista e aplica uma função ao conteúdo de cada elemento.</td>
        </tr>
        <tr>
            <td><a href=ft_lstlast.c>ft_lstlast</a></td>
            <td>Devolve o último elemento da lista.</td>
        </tr>
        <tr>
            <td><a href=ft_lstmap.c>ft_lstmap</a></td>
            <td>Itera a lista e aplica uma função ao conteúdo de cada elemento. Cria uma nova lista resultante das sucessivas aplicações da função. Uma função 'del' é utilizada para eliminar o conteúdo de um elemento, se necessário.</td>
        </tr>
        <tr>
            <td><a href=ft_lstnew.c>ft_lstnew</a></td>
            <td>Retorna um novo elemento.</td>
        </tr>
        <tr>
            <td><a href=ft_lstsize.c>ft_lstsize</a></td>
            <td>Conta o número de elementos de uma lista.</td>
        </tr>
    </tbody>
</table>


