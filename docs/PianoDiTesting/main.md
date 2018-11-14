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

Per eseguire e registrare molti test ci avvaleremo di un software chiamato *Travis CI*, un software gratuito messo a disposizione su *Github* per il testing del software.

Dopo una configurazione iniziale, Travis inizierá a testare ogni commit che verrá pushato sulla repository del progetto di Github ed a tenerne traccia automaticamente dell'esito.

Sará possibile accedere ai vari esiti dei testing effettuati da Travis tramite un apposita sezione su Github.

Per il resto del codice per cui Travis non é configurato sfrutteremo la *Schedule del Testing* (Punto 5.) per tener traccia di tutti i dati necessari al testing: descrizione feature, tester, data ed esito.

## 7 Requisiti Hardware e Software
Per eseguire i vari testing useremo questi strumenti:

- Hardware:

    - Smartphone personali dei componenti del gruppo per testare l'applicazione Android
    - Robot EV3 per testarne il programma 


- Software:
    - Emulatore di smartphone Android (disponibile nativamente su Android Studio)
    - Travis CI (disponibile su Github)


## 8 Vincoli

Quali sono gli eventuali vincoli (es. data di consegna del progetto) del processo di testing?

Data di consegna della prima versione del Piano di Testing e del rilascio della prima versione del progetto con la documentazione completa.
