# Piano di Testing

## 1 Introduzione

...

## 2 Strategia di Testing

In questa sezione vengono definite le strategie adottate per il processo di verifica e validazione dei requisiti di progetto e il modo

(Scegliere una o più alternative - 1)

- Incremental Testing: i test vengono effettuati all'aggiunta di nuove unità.

- Top-Down Testing: vengono testate prima le unità complesse e poi le unità elementari (pro: adatta per lo sviluppo top-down, individua rapidamente errori architetturali; contro: richiede la conoscenza completa della struttura del sistema, difficile sviluppare gli "stub", ovvero simulatori di modulo).
- Bottom-Up Testing: vengono testate prima le unità elementari e poi le unità complesse (pro: adatta per lo sviluppo bottom-up, appropriato per sistemi object-oriented, richiede solo una conoscenza parziale della struttura del sistema, facile sviluppare gli "stub"; contro: non individua rapidamente errori architetturali).

- Thread Testing: i test vengono effettuati su operazioni che comportano una sequenza di passi di processo che vengono eseguiti da uno stesso thread nel sistema (pro: adatto a sistemi real-time e ad object-oriented; contro: difficile effettuare un test completo, a causa del numero elevato di combinazioni di eventi).

- Stress Testing: i test vengono effettuati per verificare che il sistema sopporti il carico massimo definito in fase di progettazione (pro: adatto per sistemi distribuiti).

- Back-To-Back Testing: i risultati dei test vengono confrontati con quelli di diverse versioni dello stesso programma; se qualche risultato è diverso, ci sono errori potenziali.

(Scegliere una o più alternative - 2)

Black-box testing: i casi di test sono basati esclusivamente sulla specifica del sistema, a mio avviso CONSIGLIATO.

White-box testing: i casi di test sono basati a partire dalla struttura del programma (copertura dei cammini).

Analisi Statica: verificare la corrispondenza tra un sistema software e la sua specifica senza eseguire il codice.

## 3 Tracciabilità dei requisiti

Quali sono le condizioni per cui i requisiti di progetto possono definirsi verificati (nel singolo) e validi (nell'insieme)?

[ Tabella di associazione tra ogni specifica dei requisiti (definita nel Documento di Progettazione, sezione <...>), con ID e Nome della specifica, e la condizione per cui il test risulta superato in Test (unico, oppure Alpha e Beta, oppure ...) ]

## 4 Elementi di Testing

Quali sono gli elementi (hw e sw) soggetti al processo di testing?

## 5 Schedule di Testing

Come sono distribuiti il tempo e le risorse per l'esecuzione del processo di testing?

[ Tabella per la schedulazione di tempo e risorse ]

## 6 Procedure di Registrazione dei Test

Come verranno registrati i risultati del processo di testing?

## 7 Requisiti Hardware e Software

Quali sono gli strumenti (hw e sw) richiesti per l'esecuzione del processo di testing?

## 8 Vincoli

Quali sono gli eventuali vincoli (es. data di consegna del progetto) del processo di testing?
