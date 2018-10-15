# Piano di Progetto

[TOC]


## 1. Introduzione

### 1.1 Overview del progetto

Il nostro progetto consiste nella progettazione e realizzazione, prevista nel corso di Ingegneria del Software del Corso di Laurea in Informatica tenuto nell'a.a. 2018/2019 dal prof. Agostino Cortesi, di un sistema Smart Home, composto principalmente da un robot, realizzato con il set **Lego Mindstorms EV3[^2]**, ed un'**applicazione Android[^1]** di interfaccia remota del robot.

In particolare, il robot sarà in grado di raccogliere dati in tempo reale, grazie a diversi sensori incorporati allo scopo di rilevare intrusioni e misurare alcune variabili ambientali (come temperatura e umidità), inviandoli successivamente ad uno smartphone Android provvisto dell'applicazione per avvisare l'utente.

### 1.2 Deliverables del Progetto

Il progetto prevede una serie di elaborati da consegnare entro i tempi stabiliti, qui sotto riportati:

|          DELIVERABLE           |                  DESCRIZIONE                   | DATA CONSEGNA |
| :----------------------------: | :--------------------------------------------: | :-----------: |
|       Piano di progetto        |         Consegna del piano di progetto         |  16/10/2018   |
|   Documento di Analisi e SP    | Consegna del documento di analisi e specifiche |  02/11/2018   |
|        Piano di testing        |         Consegna del piano di testing          |  15/11/2018   |
|   Documentazione di progetto   |   Consegna della documentazione di progetto    |  10/12/2018   |
| Realizzazione e messa in linea | Rilascio di una versione stabile del software  |  31/01/2018   |

### 1.3 Evoluzione del progetto

Il progetto, ai fini dell'esame, é finalizzato alla consegna di un prototipo, non pronto per la produzione o l'uso commerciale. Un possibile sviluppo del progetto potrebbe essere quello di sviluppare una versione maggiormente orientata al consumo, utilizzando hardware personalizzato anzichè il set Lego Mindstorms ed un'applicazione volta a migliorare l'esperienza utente.

### 1.4 Materiale di Riferimento

- [Documentazione ufficiale sviluppo Android][developer.android.com]
- [Slide del corso di ingegneria del software 2018/2019][https://www.unive.it/data/insegnamento/89084]
- [Documentazione ufficiale lego Mindstorm EV3][https://le-www-live-s.legocdn.com/ev3/userguide/1.4.0/ev3_userguide_enus.pdf]

### 1.5 Definizione e Abbreviazioni

- [^1]: *Android*: sistema operativo dedicato agli smartphone e tablet sviluppato da Google

- [^2]: *Lego Mindstorms EV3*: Kit di sviluppo realizzato da Lego per l'assemblaggio e programmazione di robot, composto da vari sensori e motori da collegare ad un'unità centrale (EV3), dotata di porte USB e Bluetooth.

- [^3]: *Agile*: insieme di metodi di sviluppo del software focalizzato sull'obiettivo di consegnare al cliente piú brevemente e frequentemente software funzionante. Le caratteristiche principali di Agile sono due: scrivere e revisionare il codice contemporaneamente in modo da minimizzare gli errori e quella di concentrarsi di piú sul mantenere il software funzionante rispetto ad aggiornare la documentazione che lo segue.

- [^4]: *Github*: servizio di hosting gratuito per progetti software che utilizza il software *Git* per un *version-control* molto semplice ed intuitivo, oltre a fornire strumenti per il project management, come le *Kanban* e la *Wiki[^7]*.

- [^5]: *Issues*: su *Github[^4]* , sono un sistema per tener traccia dei vari *todos* e *open items* del progetto.

- [^6]: *Board*: su *Github[^4]* , é un sistema per categorizzare e visualizzare lo stato delle varie *Issues[^5]*.

- [^7]: *Wiki*: su *Github[^4]* , é uno strumento collaborativo per scrivere la documentazione del software.

- [^8]: *Android studio*: un ambiente di sviluppo integrato (IDE) basato sul software di *JetBrains IntelliJ IDEA* esclusivamente per la creazione di applicazioni *Android[^1]* native.

- [^9]: *Telegram*: servizio di messaggistica istantanea basato su cloud, disponibile su molte piattaforme quali smartphone, desktop e Web.

- [^10]: *Typora*: software per la creazione di documenti in *Markdown*.

- [^11]: *CLion*: IDE di Jetbrains dedicato alla scrittura di codice C++.

- [^12]: *Visual Studio Code*: IDE gratuito di Microsoft.

- [^13]: *Adobe Xd*: software gratuito per la realizzazione e il mockup delle interfacce grafiche.

- [^14]: *Docker*: software di virtualizzazione che facilita il lavoro di *cross compiling* e *deployment*.

- [^15]: *Git*: software di *code versioning* che permette di tenere traccia delle versioni dei file sorgenti in maniera decentralizzata.

- [^16]: *Continuos Integration*: un software per automatizzare il processo di testing automatico, formattazione del codice, validazione e deployment, integrato con Git.



## 2. Organizzazione del Progetto

### 2.1 Modello del Processo

Per realizzare al meglio il progetto, a cui si aggiunge la scarsa disponibilità di ritrovarsi di persona da parte dei componenti del gruppo, adotteremo una metodologia di gestione progetto di tipo **Agile[^3]**, la cui filosofia prevede l'esecuzione di cicli di sviluppo iterativi di durata costante.

Ogni ciclo (che chiameremo anche *sprint*) prevede una fase di planning e assessment del lavoro svolto del ciclo precedente mediante una riunione in presenza, seguito da una parte di analisi, sviluppo e testing. Il risultato di uno sprint è una serie di nuove funzionalità o una parte di lavoro compiuta, che non necessariamente corrisponde ad un deliverable tra quelli sopra descritti. Al termine di uno sprint si analizza e verifica il lavoro fatto finora e si pianifica il risultato atteso dal ciclo successivo.

### 2.2 Struttura Organizzativa

È stata scelta una struttura organizzativa di tipo **democratica decentralizzata**: ogni membro ha la stessa importanza nel progetto, con equa responsabilità e dovrà rispettare le scadenze assegnate. Ulteriori proposte di funzionalità verranno valutate durante riunioni di gruppo; se una proposta dovesse essere ritenuta fattibile ed inerente al progetto dalla maggioranza del team, la proposta verrà accettata.

### 2.3 Interfacce Organizzative

Per favorire una migliore comunicazione tra i componenti del gruppo, abbiamo deciso di utilizzare un sistema di chat online (*Telegram[^9]*), dove potremmo prendere decisioni, organizzare le attività e gli incontri e ci aiuteremo in caso di necessità. Inoltre, sono previste riunioni in teleconferenza per riallineamento.

Il progetto verrà reso pubblico e gestito mediante la piattaforma online fornita da **Github[^4]**, il quale ci servirà per mantenere il controllo delle versioni (quindi, rendendo non necessaria la figura del Software Librarian), le *Issues[^5]* di progetto (Todo, bugs e altri problemi), la *Board[^6]* con le issues e la *Wiki[^7]* di progetto (dove manterremo la documentazione necessaria ai vari componenti del team di progetto).

Questi due strumenti renderanno più semplice anche l'eventuale comunicazione con i committenti (Agostino Cortesi e Alvise Spanò) e con terze parti (eventuali tester esterni).

### 2.4 Responsabilita di progetto

Per garantire il successo del progetto, le varie responsabilità saranno suddivise per ruoli come seguente:

- **Project Manager**
  - <u>Responsabile:</u> Casarin Samuele
  - <u>Funzione:</u> Pianifica, coordina e supervisiona le attività del team.
- **Software Architect**
  - <u>Responsabile:</u> Zausa Giulio
  - <u>Funzione:</u> Progetta ad alto livello la parte software, includendo standard di codifiche e meccanismi di automazione.
- **Product Manager**
  - <u>Responsabile:</u> Scodeller Giovanni
  - <u>Funzione:</u> È responsabile di mantere le relazioni con il cliente e di verificare l'aderenza del prodotto con le specifiche.
- **Backup Engineer**
  - <u>Responsabile:</u> Lazzaro Dario
  - <u>Funzione:</u> Supporta il project manager ed è responsabile della validazione.
- **Test Manager**
  - <u>Responsabile:</u> Baccega Sandro
  - <u>Funzione:</u> Si occupa di gestire i piani di testing, i test automatici ed è responsabile dei deliverables.
- **Technical Staff**
  - <u>Responsabile:</u> Baccega Sandro, Casarin Samuele, Lazzaro Dario, Scodeller Giovanni, Zausa Giulio
  - <u>Funzione:</u> Conduce l'analisi e lo sviluppo.


## 3. Processi gestionali

### 3.1 Obiettivi e Priorità

- **Obiettivi**
  - Sviluppare due applicativi:
    - Applicazione Android in grado di informare l'utente di determinati eventi e consultare dati storici.
    - Firmware per EV3 in grado di rilevare dati dai sensori, elaborarli ed inviarli a richiesta all'app Android.
  - Realizzare un robot Lego il quale, attraverso l'uso di alcuni sensori in sua dotazione, riesca ad effettuare programmate operazioni.
- **Priorità**
  - Mantenere coesione e collaborazione tra i membri del gruppo.
  - Riuscire ad ottenere un livello coerente tra i vari membri del gruppo.
  - Tenere una documentazione stabile e aggiornata.
  - Assicurare un'elevata qualità delle funzionalità del prodotto e del codice.

### 3.2 Assunzioni, Dipendenze, Vincoli

- **Assunzioni**
  - Alla fine del progetto, il robot realizzerà gli obbiettivi preposti in maniera affidabile.
  - Nessun membro del team abbondonerà il progetto.
  - L'utente finale deve avere un telefono con sistema operativo Android ed essere in possesso di un *Lego Mindstorm EV3*.
- **Dipendenze**
  - Apprendimento di nuovi linguaggi di programmazione e tecniche di sviluppo.
  - Approvvigionamento dell'hardware necessario.
- **Vincoli**
  - L'applicazione mobile deve essere programmata attraverso **Android Studio[^8]**.
  - Dover seguire altri corsi universitari e rispettivi esami.
  - Verrano rispettate le deadlines.
  - Dovranno essere usati almeno due sensori.

### 3.3 Gestione dei Rischi

|ID | Rischio | Categoria | Probabilità | Impatto |
|------------ | -------------|------------ |------------ |------------ |
|**1** | Mancanza di conoscenze | Trascurabile | 60% | Basso |
|**2** | Malattie ed infortuni | Marginale | 45% | Alto |
|**3** | Malfunzionamento o perdita Lego Mindstorm | Critico | 5% | Alto |
|**4** | Errata valutazione del carico di lavoro | Critico | 15% | Medio |
|**5** | Mancante interazione tra i membri del gruppo | Catastrofico | 20% | Alto |
|**6** | Errata valutazione della fattibiltà del progetto | Critico | 20% | Medio |

![Quadrati rischi](./Quadrati rischi.svg)

### 3.4 Meccanismo di monitoraggio e di controllo

Ogni componente del gruppo effetuerà in un primo momento un controllo personale del lavoro svolto che verrà poi revisionato insieme al resto del gruppo, dove saranno esposte possibili lacune, imprecisioni e correzioni possibili.

Ogni settimana si terrà una riunione dove si discute del lavoro svolto fino a quel punto, se il progetto è in linea con i tempi e sta proseguendo nella direzione corretta.
Se dovessero sorgere problematiche dovute a possibili ritardi derivanti, per esempio, a difficoltà tecniche i membri possono cambiare momentaneamente i propri compiti per cercare di arginare rapidamente il problema.

Il team di sviluppo ha scelto di appogiarsi a *Github* per lo sviluppo software e l'organizzazione dei documenti. Per un rapido scambio di informazioni e comunicazioni urgenti, nel caso occorressero, verrano utilizzate applicazioni di messagistica come *Telegram*.

### 3.5 Pianificazione dello staff

Lo staff tecnico verrà diviso in due sezioni: una che seguirà lo sviluppo e l'analisi del robot e una che seguirà l'app Android, questo per l'elevata differenza di software e capacità necessarie per sviluppare le due parti.

Lo staff cercherà di lavorare nella maniera più parallela possibile, per accellerare i tempi. Tutti i lavori fatti dal gruppo saranno depositati su un repository su Github, dato che ci permetterà di lavorare su singoli file in parallelo, dove all'occorrenza sarà possibile aprire Issues e fare commenti sul codice e sulla documentazione depositata.

Nel caso di lacune nelle conoscenze del gruppo verrano colmate attraverso guide online, tutorial e documentazione ufficiale.



## 4. Processi Tecnici

### 4.1 Metodi, strumenti e tecniche

- **Strumenti Hardware**:
  - Ogni membro del gruppo utilizzerà il proprio notebook personale (*Windows*/*Linux*/*Mac*) per lo sviluppo del progetto.
  - Ogni membro del gruppo avrà a disposizione il proprio smartphone *Android* per lo sviluppo dell'applicazione.
  - *Lego Mindstorms EV3* fornito dall'università.
  - Eventuali sensori aggiuntivi e dongle USB.
- **Strumenti Software**
  - *Git[^15]*
  - *Android Studio[^8]*
  - *Typora[^10]*
  - *CLion[^11]*
  - *Visual Studio Code[^12]*
  - *Adobe Xd[^13]*
  - *Docker[^14]*

### 4.2 Documentazione del Software

Il progetto sará accompagnato dai seguenti documenti:

- Piano di Progetto
- Documento di Progettazione
- Documento di analisi e specifica
- Piano di Testing

### 4.3 Funzionalita al supporto del progetto

- **Pianificazione della qualitá**

  Lavoreremo in 2 gruppi (uno per il robot e l'altro per l'applicazione) i quali scriveranno e revisioneranno il codice contemporaneamente (in modo da minimizzare gli errori).
  Solamente dopo i dovuti testing aggiorneremo la documentazione, come previsto dalla metodologia *Agile*.

  Non considereremo i vari membri dei gruppi formatisi come valori assoluti, pensando infatti che possibili scambi per consultazioni o aggiornamenti saranno frequenti.

- **Pianificazione di Code Version Control e Continuos Integration**

  - Utilizzeremo *Github* in modo da: facilitare il lavoro del gruppo in fase di sviluppo / debugging e da tener traccia di tutte le versioni precedenti con facilitá.

  - Utilizzeremo strumenti di CI[^16] in modo da assicurare la qualità del codice ed evitare errori di regressione in maniera efficiente.


## 5. Pianificazione del lavoro delle risorse umane e del budget

### 5.1 WBS

- **1 PIANIFICAZIONE**
   - 1.1 Definizione degli obiettivi generali
   - 1.2 Definizione del piano di progetto
     - 1.2.1 Analisi dei processi gestionali
     - 1.2.2 Analisi dei processi tecnici
     - 1.2.3 Pianificazione del lavoro, delle risorse umane e del budget
   - 1.3 Definizione del documento di analisi e specifica
- **2 PROGETTAZIONE**
   - 2.1 Definizione del documento di progettazione
     - 2.1.1 Analisi del sistema
     - 2.1.2 Analisi del componente Lego Mindstorms
     - 2.1.3 Analisi dell'applicazione Android
     - 2.1.4 Prototipazione dell'interfaccia grafica
   - 2.2 Definizione del piano di testing
- **3 REALIZZAZIONE**
   - 3.1 Apprendimento tecnico
   - 3.2 Realizzazione del componente Lego Mindstorms
     - 3.2.1 Assemblaggio dei componenti hardware
     - 3.2.2 Programmazione del firmware
   - 3.3 Realizzazione dell'applicazione Android
     - 3.3.1 Programmazione del backend
     - 3.3.2 Programmazione del frontend
   - 3.4 Collaudo del sistema
- **4 DISPIEGAMENTO**
   - 4.1 Realizzazione del manuale utente
   - 4.2 Consegna del sistema
- **5 REVISIONE**
   - 5.1 Revisione finale
   - 5.2 Chiusura del progetto

### 5.2 Dipendenze

| N | Attività | Durata (in ore) | Dipendenze |
| - | - | - | - |
| A | Definizione degli obiettivi generali | 5 | - |
| B | Analisi dei processi gestionali | 10 | A |
| C | Analisi dei processi tecnici | 10 | A |
| D | Pianificazione del lavoro, delle risorse umane e del budget | 10 | A |
| E | Definizione del documento di analisi e specifica | 10 | B, C, D |
| F | Analisi del sistema | 10 | E |
| G | Analisi del componente Lego Mindstorms | 5 | F |
| H | Analisi dell'applicazione Android | 10 | F |
| I | Prototipazione dell'interfaccia grafica | 10 | F |
| J | Definizione del piano di testing | 10 | G, H, I |
| K | Apprendimento tecnico | 15 | J |
| L | Assemblaggio dei componenti hardware | 5 | K |
| M | Programmazione del firmware | 15 | K |
| N | Programmazione del backend | 15 | K |
| O | Programmazione del frontend | 10 | K |
| P | Collaudo del sistema | 5 | L, M, N, O |
| Q | Realizzazione del manuale utente | 10 | P |
| R | Consegna del sistema | 1 | Q |
| S | Revisione finale | 2 | R |
| T | Chiusura del progetto | 1 | S |

### 5.3 Risorse necessarie

Le risorse necessarie per la realizzazione del progetto sono:
- **Risorse umane**: i membri del team di sviluppo e testing e i responsabili di gestione progetto;
- **Risorse hardware**: un computer connesso ad Internet per ogni membro del team, hardware necessario per il robot;
- **Risorse software**: *Telegram* (comunicazione), *Discord* (comunicazione), *GitHub* (gestione delle versioni del progetto), *Typora* (stesura della documentazione), *Latex* (impaginazione della documentazione), *gcc* (compilazione firmware), *CMake* (automazione della compilazione), *VSCode* (programmazione del firmware), *Android Studio* (programmazione dell'applicazione Android).

### 5.4 Allocazione del budget e delle risorse

Lo sviluppo dell’applicazione non richiede alcun tipo di risorsa economica, in quanto i software impiegati per la realizzazione sono a costo zero. Inoltre, anche il set Lego Mindstorms EV3 è stato fornito in comodato d'uso dall'Università Ca' Foscari.

Eventuali sensori esterni saranno acquistati dai componenti del progetto in maniera volontaria e indipendente e non saranno considerati nel budget di progetto.

### 5.5 Pianificazione

La pianificazione del progetto è basata sui termini di consegna del progetto e di tutta la relativa documentazione, stabiliti con il professor Cortesi all’interno del corso di Ingegneria del Software 2018/2019:
- Piano di Progetto: 16/10/2018
- Documento di Analisi e Specifica: 02/11/2018
- ­Piano di Testing: 15/11/2018
- Documento di Progettazione: 10/12/2018
- Realizzazione e messa in linea: 31/01/2019
