# 🚢 Jogo Batalha Naval em C

Este projeto simula o clássico jogo **Batalha Naval**, implementado em **linguagem C**, com **três desafios progressivos**: básico, intermediário e avançado.

---

## 📁 Estrutura do Projeto

- `desafio1-nivel-basico.c`
- `desafio2-nivel-intermediario.c`
- `desafio3-nivel-avancado.c`

---

## 🔹 Desafio 1 – Nível Básico

### 🎯 Objetivo

Simular a posição de **dois navios** em um **tabuleiro 10x10**, utilizando **vetores e matrizes**.

### ⚙️ Funcionalidades

- Tabuleiro 10x10 representado por matriz.
- Dois navios de tamanho 3:
  - Um posicionado na **horizontal**.
  - Outro posicionado na **vertical**.
- Validação de:
  - Limites do tabuleiro.
  - Sobreposição de navios.
- Exibição do tabuleiro no terminal.

---

## 🔹 Desafio 2 – Nível Intermediário

## 🎯 Objetivo

Este desafio tem como objetivo **aumentar a complexidade do jogo Batalha Naval**, posicionando **quatro navios** em diferentes direções no tabuleiro.

### Navios posicionados:

- Dois navios em **horizontal** e **vertical**.
- Dois navios nas **diagonais principal** e **secundária**.

---

## ⚙️ Funcionalidades

- Tabuleiro 10x10 representado por matriz.
- **Quatro navios de tamanho 3**.
- Validação de **sobreposição** entre navios.
- Exibição visual do tabuleiro com navios em **várias direções**.
- Saída em terminal para visualização clara da posição dos navios.

---

## 🔹 Desafio 3 – Nível Avançado

## 🎯 Objetivo

Adicionar **habilidades especiais com área de efeito** no tabuleiro do jogo Batalha Naval, simulando **ataques táticos** de diferentes formatos.

---

## ⚙️ Funcionalidades

- Implementação de **três formas de área de ataque 5x5**:
  - 🔺 **Cone**
  - ➕ **Cruz**
  - 🔷 **Octaedro**
- Aplicação das habilidades com **validação de limites do tabuleiro**.
- Visualização clara dos efeitos aplicados no terminal.
- Representação visual por meio de **legenda especial**.

---

## 🧭 Legenda

- `0`: Água  
- `3`: Parte de navio  
- `5`: Área atingida por habilidade especial  

---
