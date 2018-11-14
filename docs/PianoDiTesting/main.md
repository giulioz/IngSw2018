# Piano di Testing

## 1 Introduzione

...

## 2 Strategia di Testing

In questa sezione vengono definite le strategie adottate per il processo di verifica e validazione dei requisiti di progetto.

- Incremental Testing: i test vengono effettuati all'aggiunta di nuove unità. (OK)

- Bottom-Up Testing: vengono testate prima le unità elementari e poi le unità complesse (pro: adatta per lo sviluppo bottom-up, appropriato per sistemi object-oriented, richiede solo una conoscenza parziale della struttura del sistema, facile sviluppare gli "stub"; contro: non individua rapidamente errori architetturali). (OK)

- Stress Testing: i test vengono effettuati per verificare che il sistema sopporti il carico massimo definito in fase di progettazione (pro: adatto per sistemi distribuiti). (OK)

Black-box testing: i casi di test sono basati esclusivamente sulla specifica del sistema, a mio avviso CONSIGLIATO. (OK)

Analisi Statica: verificare la corrispondenza tra un sistema software e la sua specifica senza eseguire il codice. (OK)

## 3 Tracciabilità dei requisiti

Quali sono le condizioni per cui i requisiti di progetto possono definirsi verificati (nel singolo) e validi (nell'insieme)?

[ Tabella di associazione tra ogni specifica dei requisiti (definita nel Documento di Progettazione, sezione <...>), con ID e Nome della specifica, e la condizione per cui il test risulta superato in Test (unico, oppure Alpha e Beta, oppure ...) ]

## 4 Elementi di Testing

Quali sono gli elementi (hw e sw) soggetti al processo di testing?

Singole componenti del robot, assemblaggio del robot, applicazione Android

## 5 Schedule di Testing

Come sono distribuiti il tempo e le risorse per l'esecuzione del processo di testing?

[ Tabella per la schedulazione di tempo e risorse ]

## 6 Procedure di Registrazione dei Test

Come verranno registrati i risultati del processo di testing?

Travis

## 7 Requisiti Hardware e Software

Quali sono gli strumenti (hw e sw) richiesti per l'esecuzione del processo di testing?

Travis

## 8 Vincoli

Quali sono gli eventuali vincoli (es. data di consegna del progetto) del processo di testing?

Data di consegna della prima versione del Piano di Testing e del rilascio della prima versione del progetto con la documentazione completa.
