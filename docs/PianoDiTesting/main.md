# Piano di Testing

## 1 Introduzione

Il seguente documento contiene le informazioni relative alla pianificazione del processo di testing per il progetto WatchDoge. Tale processo ha lo scopo di verifica e validazione dei requisiti di progetto e verrà eseguito dal team di progetto durante e in seguito alla fase di sviluppo.

La struttura del documento è la seguente:
- **Strategia di Testing**: in questa sezione sono definite le procedure adottate per il processo di testing in ognuno degli elementi considerati;
- **Tracciabilità dei Requisiti**: in questa sezione sono definite le associazioni tra ciascuna specifica dei requisiti di progetto (vedi *Documento di spefica dei requisiti*, sezione 3.5) e il metodo di testing e la condizione per cui il test risulta essere soddisfatto;
- **Elementi di Testing**: in questa sezione sono riportati gli elementi soggetti al processo di testing;
- **Schedule di Testing**: in questa sezione è visualizzato lo schema di allocazione temporale delle risorse di progetto impiegate per il processo di testing;
- **Procedure di Registrazione dei Test**: in questa sezione sono definite le modalità con cui i risultati del processo di testing vengono raccolti ed archiviati;
- **Requisiti Hardware e Software**: in questa sezione sono definiti i requisiti in termini di hardware e software che devono essere soddisfatti per l'esecuzione del processo di testing;
- **Vincoli**:  in questa sezione sono definiti i vincoli da rispettare al fine che lo stesso processo di testing possa essere considerato attendibile.

Per una completa comprensione del presente documento e del progetto WatchDoge, fare riferimento anche ai documenti *Piano di Progetto* e *Documento di Specifica dei Requisiti*.

## 2 Strategia di Testing

Seguiremo due percorsi di testing separati: uno per il Robot ed uno per l'applicazione Android.
Adotteremo una strategia di testing basata sull'approccio Bottom-Up: si andranno dapprima a collaudare i moduli di basso livello presenti nella nostra gerarchio di sviluppo, crescendo poi di livello proseguendo con lo sviluppo.
In questo modo, la verifica dei moduli implementati partirà dalle unità elementari fino ad arrivare a moduli sempre di più complessi.

Quando le due macro-componenti (Robot ed applicazione) avranno raggiunto singolarmente una discreta stabilità, uniremo i due percorsi di testing, in modo tale da poter effettuare test basati sull'interazione tra di esse.

Suddivideremo il processo di testing in tre fasi:

1) inizialmente, sarà data priorità al corretto funzionamento delle specifiche del Robot: essendo gran parte dell'applicazione dipendente a comportamenti basilari della macchina, è necessario ottenere un certo grado di sicurezza sul corretto funzionamento di quest'ultima.
2) in seguito, potremo cominciare la fase di testing relativa all'applicazione Android; non potendo avere a disposizione in questa fase l'implementazione completa delle funzionalità utili per l'interazione con il Robot, ricorreremo anche all'utilizzo di dummy objects.
Per queste due prime fasi, adotteremo per lo più la strategia di testing White-Box, per avere così una certa garanzia di correttezza della parte software sviluppata indipendentemente.
3) una volta raggiunto un buon punto di stabilità per lo sviluppo singolo del Robot e dell'applicazione, sarà possibile e necessario verificare che l'interazione tra le due macro-componenti sia quella desiderata e, probabilmente, la stessa ottenuta dai test eseguiti con dummy objects.
In quest'ultima fase si adotterà maggiormente la strategia di testing Black-Box, ovvero simulando le possibili azioni che un utente finale potrà compiere.

Altre strategie di testing che adotteremo sono le seguenti:
- Incremental Testing: i test vengono effettuati all'aggiunta di nuove unità;
- Stress Testing: i test vengono effettuati per verificare che il sistema sopporti il carico massimo definito in fase di progettazione (tipo di test necessario per sistemi distribuiti);
- Analisi Statica: verificare la corrispondenza tra un sistema software e la sua specifica senza eseguire il codice.

## 3 Tracciabilità dei requisiti

Gli identificatori utilizzati per la creazione della tabella sono definiti nel Documento di Specifica dei Requisiti, sezione 3.5.

Tutti i test cases descritti di seguito devono essere riproducibili e rispettare i risultati previsti.

| ID Requisito | Nome Requisito                         | Test Alpha                                                   | Test Beta                                                    |
| ------------ | :------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| FRS-01       | Associazione con codice Pin            | Si verifica quando il Doge riconosce il Pin inviato dal telefono. | Si verifica quando il Doge ed il telefono si associano correttamente. |
| FRS-02       | Rilevazione di un intruso              | Il Doge riesce a vedere l'ambiente attraverso la telecamera. | Il Doge riesce a rilevare un oggetto in movimento.           |
| FRS-03       | Notificazione acustica dell'intrusione | Il Doge emette un suono acustico.                            | Alla rilevazione di un movimento emette un suono acustico    |
| FRS-04       | Disattivazione antifurto               | Il Doge si spegne attraverso un segnale.                     | Il Doge si spegne tramite una sequenza di tasti.             |
| FRS-05       | Primo avvio                            | L'operazione è verificata se al tap l'applicazione si avvia correttamente. | L'operazione è verificata se gli utenti riescono ad aprire l'applicazione correttamente. |
| FRS-06       | Utilizzo menù                          | Controllo del menù, apertura e primo utilizzo.               | Utilizzo stressante dell'applicazione.                       |
| FRS-07       | Programmazione Doge                    | Controllo delle funzionalità programmabili.                  | Inserimento di tutte le possibili combinazioni programmabili. |
| FRS-08       | Sistema di notifica                    | L'applicazione crea notifiche.                               | Le notifiche vengono create con informazioni inviate dal robot. |
| FRS-09       | Spostamento manuale Doge               | Il Doge riesce a muoversi su un asse.                        | Il Doge riesce a muoversi attraverso dei segnali.            |



## 4 Elementi di Testing

Gli elementi sottoposti ai vari test durante il periodo di debugging saranno principalmente tutte le componenti presenti nel Robot e nell'applicazione.

Prove specifiche finalizzate a scoprire e risolvere eventuali problematiche che potrebbero presentarsi nel Robot riguarderanno:
- i singoli componenti forniti nel set Lego Mindstorm EV3;
- il firmware del Robot;
- le unità, a partire da quelle elementari alle più complesse, dell'applicazione Android.

## 5 Schedule di Testing

| Nome Requisito                         | Tipo test | Tester | Data | Esito |
| -------------------------------------- | --------- | ------ | ---- | ----- |
| Associazione con codice Pin            | Alfa      |        |      |       |
| Rilevazione di un intruso              | Alfa      |        |      |       |
| Notificazione acustica dell'intrusione | Alfa      |        |      |       |
| Disattivazione antifurto               | Alfa      |        |      |       |
| Primo avvio                            | Alfa      |        |      |       |
| Utilizzo menù                          | Alfa      |        |      |       |
| Programmazione Doge                    | Alfa      |        |      |       |
| Sistema di notifica                    | Alfa      |        |      |       |
| Spostamento manuale Doge               | Alfa      |        |      |       |
| Associazione con codice Pin            | Beta      |        |      |       |
| Rilevazione di un intruso              | Beta      |        |      |       |
| Notificazione acustica dell'intrusione | Beta      |        |      |       |
| Disattivazione antifurto               | Beta      |        |      |       |
| Primo avvio                            | Beta      |        |      |       |
| Utilizzo menù                          | Beta      |        |      |       |
| Programmazione Doge                    | Beta      |        |      |       |
| Sistema di notifica                    | Beta      |        |      |       |
| Spostamento manuale Doge               | Beta      |        |      |       |

## 6 Procedure di Registrazione dei Test

Per eseguire ed archiviare il risultato dei test ci avvaleremo di *Travis CI*, uno strumento software gratuito messo a disposizione su *Github* per il testing del software.

Dopo la configurazione iniziale, *Travis CI* verificherà ogni unità pushata sulla repository remota del progetto su Github, tenendo traccia dell'esito automaticamente.

Sarà possibile accedere agli esiti dei test effettuati da *Travis CI* tramite un'apposita sezione su Github.

Per tutto il codice per cui *Travis CI* non è configurato, sfrutteremo il modello definito nella sezione 5 *Schedule di Testing* per documentare il processo di testing: descrizione della funzionalità, nome del tester, data di testing ed esito.

## 7 Requisiti Hardware e Software

Per eseguire i vari test, useremo questi strumenti:

- Hardware:
    - Smartphone personali dei componenti del gruppo per verificare l'applicazione Android
    - Robot EV3 per verificare il programma

- Software:
    - Emulatore di smartphone Android (disponibile nativamente su Android Studio)
    - *Travis CI* (disponibile su Github)

## 8 Vincoli

Il processo di testing verrà effettuato durante e in seguito l'attività di sviluppo del progetto e dovrà terminare entro 5 giorni prima della data di scadenza (entro il 26 gennaio 2019), al fine di verificare e validare tutti i requisiti di progetto entro i limiti di tempo e riducendo il più possibile la probabilità di errori durante la fase di produzione.
