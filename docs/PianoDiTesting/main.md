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

In questa sezione vengono definite le strategie adottate per il processo di verifica e validazione dei requisiti di progetto.

Suddivideremo inizialmente due percorsi di Testing separati: uno per il Robot ed uno per l'applicazione che dovrà poi interfacciarsi con quest'ultimo.
Utilizzeremo un tipo di testing basato sull'approccio Bottom-Up: si andranno da prima a collaudare i moduli di basso livello presenti nella nostra gerarchio di sviluppo, crescendo poi di livello continuando con lo sviluppo.
In questo modo la valutazione della corretezza dei moduli implementati partirà dalle parti più piccole (e fondamenteli) fino ad arrivare a moduli sempre di più alto livello.

Quando le due unità (Robot ed Applicazione) avranno un numero di componenti implementate tali da poter avere una vera e propria dipendenza l'uno dall'altro uniremo questi due percorsi, in modo tale da poter effettuare test riconducibili ed un utilizzo sempre più simile rispetto a quello di un utente finale.

Potremo suddividere varie fasi per i test:

1) Inizialmente si darà priorità al corretto funzionamento delle specifiche del Robot: essendo gran parte dell'applicazione dipendente a comportamenti basilari della macchina è necessaria la certezza del loro corretto funionamento.
2) Potremo quindi poi cominciare la vera e propria fase di Testing relativa all'applicazione, testando quindi le funzionalità implementative non strettamente dipendenti a funzionalità raggiunte dalla parte Robot.
Per queste due fasi iniziali utilizzeremo per lo più un approccio di test a White-Box: effettuando test dettagliati che andranno a valutare la struttura della macchina e dell'app, per aver così una certezza sulla correttezza della parte software sviluppata.

3) Una volta raggiunte funzionalità tali che nessitano una sempre più grande interoperabilità dei due moduli del progetto, Robot ed applicazione, sarà necessario effettuare testare in contemporanea tra queste due parti.
In questa fase si darà, inoltre, molto spazio ad un approccio di test a Black-Box: simulando le possibili azione che un utente finale andrà a compiere.

Il modello di Testing che si andrà ad eseguire dovrà, inolte, rispettare le seguenti condizioni:
- Incremental Testing: i test vengono effettuati all'aggiunta di nuove unità.
- Stress Testing: i test vengono effettuati per verificare che il sistema sopporti il carico massimo definito in fase di progettazione (pro: adatto per sistemi distribuiti). (OK)

Analisi Statica: verificare la corrispondenza tra un sistema software e la sua specifica senza eseguire il codice. (OK) (?)

## 3 Tracciabilità dei requisiti

Gli identificatori utilizzati la creazione della tabella sono gli stessi descritti nel documento di specifica dei requisiti.

Tutti i Test descritti di seguito devono essere riproducibili e rispettare nel modo più veritiero gli output descritti. 

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

Quali sono gli elementi (hw e sw) soggetti al processo di testing?

Singole componenti del robot, assemblaggio del robot, applicazione Android



## 5 Schedule di Testing

| Nome Requisito                         | Tipo test | Tester | Data | Esito |
| -------------------------------------- | --------- | ------ | ---- | ----- |
| Associazione con codice Pin            |           |        |      |       |
| Rilevazione di un intruso              |           |        |      |       |
| Notificazione acustica dell'intrusione |           |        |      |       |
| Disattivazione antifurto               |           |        |      |       |
| Primo avvio                            |           |        |      |       |
| Utilizzo menù                          |           |        |      |       |
| Programmazione Doge                    |           |        |      |       |
| Sistema di notifica                    |           |        |      |       |
| Spostamento manuale Doge               |           |        |      |       |

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

Il processo di testing verrà effettuato durante e in seguito l'attività di sviluppo del progetto e dovrà terminare entro 5 giorni prima della data di scadenza (entro il 26 gennaio 2019), al fine di verificare e validare tutti i requisiti di progetto entro i limiti di tempo e riducendo il più possibile la probabilità di errori durante la fase di produzione.

