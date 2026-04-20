## 📌 Simulação de Memória RISC-V

Este projeto foi desenvolvido como parte da disciplina de Organização e Arquitetura de Computadores da Universidade de Brasília (UnB).

O objetivo é simular, em linguagem C, o comportamento das principais instruções de acesso à memória da arquitetura RISC-V, com foco em conceitos fundamentais como endereçamento, manipulação de bytes e palavras, e extensão de dados.

---

## 🧠 Conceitos Abordados

A memória foi simulada como um vetor de bytes, onde cada posição representa 1 byte. Isso permite trabalhar em um nível mais próximo do funcionamento real de um processador.

O endereço de acesso à memória é calculado pela soma de dois parâmetros:
address = reg + kte

---

## ⚙️ Instruções Implementadas

### 🔹 lb (Load Byte - com sinal)
Lê 1 byte da memória e realiza extensão de sinal para 32 bits, preservando valores negativos.

### 🔹 lbu (Load Byte Unsigned - sem sinal)
Lê 1 byte da memória e realiza extensão com zero, garantindo que o valor seja sempre positivo.

### 🔹 lw (Load Word)
Lê 4 bytes consecutivos da memória e monta uma palavra de 32 bits utilizando operações de deslocamento e combinação de bits. A organização segue o padrão little-endian.

### 🔹 sb (Store Byte)
Armazena 1 byte na memória no endereço especificado.

### 🔹 sw (Store Word)
Armazena uma palavra de 32 bits na memória, dividindo-a em 4 bytes. O byte menos significativo é armazenado no menor endereço (little-endian).

---

## 🧪 Testes Realizados

Foram realizados testes de escrita e leitura na memória:

Escrita:
- Escrita de uma palavra de 32 bits (sw)
- Escrita de bytes individuais (sb)

Leitura:
- Leitura de palavra completa (lw)
- Leitura de bytes com extensão de sinal (lb)
- Leitura de bytes sem sinal (lbu)

---

## ✅ Resultados Esperados

lw(0,0)   → 0xabacadef

lb:
0 → 0xffffffef  
1 → 0xffffffad  
2 → 0xffffffac  
3 → 0xffffffab  

lbu:
0 → 0x000000ef  
1 → 0x000000ad  
2 → 0x000000ac  
3 → 0x000000ab  

---

## 📚 Tecnologias Utilizadas

- Linguagem C  
- Biblioteca stdint.h para controle preciso dos tamanhos dos tipos de dados
