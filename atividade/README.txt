Para compilar:
  g++ -Wall -o teste_ordenacao teste_ordenacao.cpp ordenacao.cpp

Para executar
  ./teste_ordenacao

Para o manual do programa
  ./teste_ordenacao -h

Para executar o teste no arquivo 'e1.txt' e gerar a saída no arquivo 's1.txt'.
  ./teste_ordenacao < e1.txt > s1.txt

OBS: O padrão é ordenação por seleção.

Para definir ordenação por inserção do arquivo 'e1.txt' e gerar o arquivo 's1.txt'.
  ./teste_ordenacao -i < e1.txt > s1.txt

Para definir ordenação por seleção do arquivo 'e1.txt' e gerar o arquivo 's1.txt'.
  ./teste_ordenacao -s < e1.txt > s1.txt

Para definir ordenação por merge-sort do arquivo 'e1.txt' e gerar o arquivo 's1.txt'.
  ./teste_ordenacao -m < e1.txt > s1.txt

Para executar os testes:
./teste_ordenacao < testes/caso01/exemplo-10000-1.txt

Para executar multiplos testes de uma só vez:


for arquivo in ./testes/caso05/exemplo-*.txt; do     echo "Executando teste com $arquivo" >> saida2.txt;     ./teste_ordenacao -m < "$arquivo" >> saida2.txt;     echo "-----------------------------" >> saida2.txt; done
