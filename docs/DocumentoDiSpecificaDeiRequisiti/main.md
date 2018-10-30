# WatchDoge
## Documento di Analisi e Specifica
### Versione 1.0 - 2 novembre 2018

**Team DogeDroid**
- Dario Lazzaro
- Giovanni Scodeller
- Giulio Zausa
- Samuele Casarin
- Sandro Baccega

[TOC]

# 1 Introduzione

## 1.1 Funzionalità Generali del Sistema

L'obbiettivo del progetto è lo sviluppo di un sistema antifurto destinato all'uso domestico.
Tale sistema sarà composto principalmente da due sottosistemi:
- un robot che, quando abilitato, rileva le intrusioni all'interno dell'ambiente domestico (entro certi limiti) e le invia all'applicazione Android;
- un'applicazione Android che abilita/disabilita il robot su decisione dell'utente e notifica l'utente riguardo le segnalazioni ricevute dal robot.

## 1.2 Descrizione del Documento

### Da cambiare la descrizione dei campi

|          |               |
|----------|:-------------:|
|**Nome**|Nome del requisito funzionale|
|**ID**|Codice univoco del requisito funzionale|
|**Descrizione**|Descrizione del requisito funzionale|
|**Motivazione**|Descrive il perché abbiamo deciso di includere questo requisito funzionale|
|**Influisce**|Indica se questo requisito funzionale influisce sul sistema|
|**Specifica**|Indica la specifica dei requisiti funzionali|

# 2 Glossario

# 3 WatchDoge

## 3.1 Modelli del Sistema

|||
|-|-|
| **Codice** | UC-01 |
| **Nome** | Abilita Accoppiamento |
| **Scopo** | Associare il robot ad un dispositivo Android per permetterne il controllo all'utente. |
| **Attori** | Utente |
| **Precondizioni** | \- |
| **Trigger** | Pressione del pulsante *Abilita accoppiamento* (robot) |
| **Descrizione** | Il robot accetta richieste di accoppiamento per un certo tempo. |
| **Alternative** | \- |
| **Postcondizioni** | Il robot è accoppiato con un dispositivo Android, oppure non è accoppiato |

|||
|-|-|
| **Codice** | UC-02 |
| **Nome** | Visualizza Codice per Accoppiamento |
| **Scopo** | Mitigare la presa di controllo indesiderata del robot da parte di qualcun altro diverso dall'utente. |
| **Attori** | Utente |
| **Precondizioni** | UC-01 |
| **Trigger** | Il robot riceve una richiesta di accoppiamento. |
| **Descrizione** | Il robot visualizza un codice con cui il dispositivo che ha inviato la richiesta di accoppiamento deve rispondere per poter completare la procedura di accoppiamento. |
| **Alternative** | \- |
| **Postcondizioni** | Il successo della verifica garantisce che il dispositivo che ha inviato la richiesta di accoppiamento è effettivamente quello dell'utente. |

|||
|-|-|
| **Codice** | UC-03 |
| **Nome** | Accoppia Robot |
| **Scopo** | Associare il dispositivo Android al robot per permetterne il controllo all'utente. |
| **Attori** | Utente |
| **Precondizioni** | Connessione alla stessa rete del robot, UC-01 |
| **Trigger** | Primo avvio dell'applicazione Android e pressione del pulsante *Accoppia robot* (applicazione Android) |
| **Descrizione** | L'applicazione Android cerca robot presenti nella stessa rete dello smartphone entro un certo tempo. Al termine, l'applicazione Android visualizza la lista di robot trovati, permettendo all'utente di selezionare quello da associare. |
| **Alternative** | \- |
| **Postcondizioni** | Il dispositivo Android è accoppiato con il robot |

|||
|-|-|
| **Codice** | UC-04 |
| **Nome** | Inserisci Codice per Accoppiamento |
| **Scopo** | Mitigare la presa di controllo indesiderata del robot da parte di qualcun altro diverso dall'utente. |
| **Attori** | Utente |
| **Precondizioni** | UC-03 |
| **Trigger** | Selezione di un robot da associare |
| **Descrizione** | L'utente inserisce il codice di accoppiamento visualizzato dal robot e lo inserisce in un apposito campo. Successivamente, l'applicazione Android invia il codice al robot per la verifica. |
| **Alternative** | \- |
| **Postcondizioni** | Il successo della verifica garantisce che il dispositivo che ha inviato la richiesta di accoppiamento al robot è effettivamente quello dell'utente. |

|||
|-|-|
| **Codice** | UC-05 |
| **Nome** | Visualizza Stato Robot |
| **Scopo** | Consentire all'utente di visualizzare in tempo reale le informazioni relative al robot. |
| **Attori** | Utente |
| **Precondizioni** | UC-03 |
| **Trigger** | Aprire l'applicazione Android |
| **Descrizione** | L'utente visualizza in tempo reale se l'antifurto è abilitato oppure no e la sua programmazione attraverso un'apposita interfaccia grafica. |
| **Alternative** | \- |
| **Postcondizioni** | L'utente è al corrente dello stato del robot. |

|||
|-|-|
| **Codice** | UC-06 |
| **Nome** | Abilita/Disabita Robot |
| **Scopo** | Consentire all'utente di attivare/disattivare la funzione di antifurto del robot. |
| **Attori** | Utente |
| **Precondizioni** | UC-03 |
| **Trigger** | Pressione del pulsante *ON/OFF* (applicazione Android) |
| **Descrizione** | L'utente cambia lo stato del robot ad attivo/disattivo. |
| **Alternative** | \- |
| **Postcondizioni** | Il robot è attivo/disattivo. |

|||
|-|-|
| **Codice** | UC-07 |
| **Nome** | Imposta Programmazione |
| **Scopo** | Consentire all'utente di decidere quando il robot deve attivarsi/disattivarsi automaticamente in determinate fasce orarie. |
| **Attori** | Utente |
| **Precondizioni** | UC-03 |
| **Trigger** | Pressione del pulsante *Programma* |
| **Descrizione** | L'utente abilita/disabilita la modalità automatica attraverso un interrutore e imposta le fasce orarie di attivazione del robot attraverso una tabella oraria settimanale. |
| **Alternative** | \- |
| **Postcondizioni** | Il robot è configurato in modalità automatica per attivarsi negli orari stabiliti dall'utente. |

|||
|-|-|
| **Codice** | UC-08 |
| **Nome** | Controllo Remoto |
| **Scopo** | Consentire all'utente di guardare in tempo reale le immagini catturate dal robot e spostare la visuale. |
| **Attori** | Utente |
| **Precondizioni** | UC-03 |
| **Trigger** | Pressione del pulsante *Controllo remoto* |
| **Descrizione** | L'utente può connettersi da remoto al robot e visualizza le immagini catturate dalla fotocamera incorporata; inoltre, attraverso dei pulsanti direzionali, può spostare la visuale della fotocamera in base all'angolo di rotazione. |
| **Alternative** | \- |
| **Postcondizioni** | L'utente acquisisce una panoramica istantanea dell'ambiente dove è disposto il robot. |

|||
|-|-|
| **Codice** | UC-09 |
| **Nome** | Cambia Stato Robot |
| **Scopo** | Attivare/disattivare/configurare una o più funzioni del robot. |
| **Attori** | Utente |
| **Precondizioni** | UC-03 |
| **Trigger** | Una richiesta proveniente dall'applicazione Android |
| **Descrizione** | Attraverso l'interfaccia grafica, l'utente invia una richiesta al robot per cambiare il suo stato. |
| **Alternative** | \- |
| **Postcondizioni** | Lo stato del robot viene cambiato a seconda della richiesta inviata. |

|||
|-|-|
| **Codice** | UC-10 |
| **Nome** | Ottieni Stato Robot |
| **Scopo** | Consentire all'applicazione Android di riportare le informazioni relative alle funzioni del robot. |
| **Attori** | Utente |
| **Precondizioni** | UC-03 |
| **Trigger** | Una richiesta proveniente dall'applicazione Android |
| **Descrizione** | L'applicazione Android invia una richiesta al robot per ottenere il suo stato. |
| **Alternative** | \- |
| **Postcondizioni** | L'applicazione Android ottiene lo stato del robot a seconda della richiesta inviata. |

|||
|-|-|
| **Codice** | UC-11 |
| **Nome** | Visualizza Storico Segnalazioni |
| **Scopo** | Consentire all'utente di avere un archivio delle segnalazioni di intrusioni rilevate dal robot. |
| **Attori** | Utente |
| **Precondizioni** | UC-03 |
| **Trigger** | Pressione del pulsante *Storico* (applicazione Android) |
| **Descrizione** | L'applicazione Android visualizza la lista delle ultime segnalazioni. |
| **Alternative** | \- |
| **Postcondizioni** | L'utente ha una visione generale delle segnalazioni rilevate dal robot. |

|||
|-|-|
| **Codice** | UC-12 |
| **Nome** | Visualizza Notifica Segnalazione |
| **Scopo** | Consentire all'utente di ricevere immediatamente una segnalazione di intrusione. |
| **Attori** | Utente |
| **Precondizioni** | UC-03 |
| **Trigger** | Ricezione di una segnalazione dal robot |
| **Descrizione** | L'applicazione Android mostra una notifica con lo scopo di avvertire l'utente di un'intrusione rilevata dal robot. Inoltre, alla notifica viene allegata un'immagine dell'intruso. |
| **Alternative** | \- |
| **Postcondizioni** | L'utente può essere informato immediatamente quando viene rilevata un'intrusione. |

|||
|-|-|
| **Codice** | UC-13 |
| **Nome** | Innesca Antifurto |
| **Scopo** | Mitigare le intrusioni all'interno dell'ambiente del robot. |
| **Attori** | Intruso |
| **Precondizioni** | UC-03 |
| **Trigger** | La fotocamera del robot rileva del movimento all'interno dell'ambiente |
| **Descrizione** | Il robot invia una segnalazione di intrusione al dispositivo accoppiato ed emette un suono d'allarme. |
| **Alternative** | \- |
| **Postcondizioni** | L'intruso viene rilevato e la sua presenza viene segnalata all'utente. |

|||
|-|-|
| **Codice** | UC-14 |
| **Nome** | Scatta Fotografia Intruso |
| **Scopo** | Fornire all'utente un'immagine dell'intruso per tentare la sua identificazione. |
| **Attori** | Utente |
| **Precondizioni** | UC-13 |
| **Trigger** | La fotocamera del robot rileva del movimento all'interno dell'ambiente |
| **Descrizione** | Il robot invia un immagine dalla fotocamera puntata nella direzione in cui ha rilevato del movimento, dove probabilmente è presente l'intruso. |
| **Alternative** | \- |
| **Postcondizioni** | L'utente potrebbe avere una prova per identificare l'intruso. |

## 3.2 Definizione dei Requisiti Funzionali

### ROBOT

|          |  |
|----------|:-------------:|
|**Nome**|Accoppiamento ROBOT|
|**ID**|FR1|
|**Descrizione**|Si collega il dispositivo ROBOT allo smartphone del proprietario|
|**Motivazione**|Possibilità di visualizzare informazioni e comandare l'apparato a distanza, grazie ad una rete di collegamento|
|**Influisce**|Funzionalità principale del sistema d'allarme|
|**Specifica**|FRS1|


&nbsp;

|          |  |
|----------|:-------------:|
|**Nome**|Rilevamento Intrusi|
|**ID**|FR2|
|**Descrizione**|Se dovesse avvenire un movimento nell'ambiente il dispositivo Lego se ne accorgerà|
|**Motivazione**|Riuscire ad individuare eventuali intrusi da segnalare|
|**Influisce**|Notifiche da segnalare all'utilzzatore|
|**Specifica**|FRS2|

&nbsp;

|          |               |
|----------|:-------------:|
|**Nome**|Suono Allarme|
|**ID**|FR3|
|**Descrizione**|Se dovesse avvenire un movimento nell'ambiente e nessun utente qualificato ne darà il consenso, il sistema ROBOT comincerà ad emettere un suono di allarme|
|**Motivazione**|Scoraggiare eventuali entrusi a compire atti illeciti|
|**Influisce**|Utilizzo autoparlanti Lego per emissione suono allarme|
|**Specifica**||

&nbsp;

|          |  |
|----------|:-------------:|
|**Nome**|PIN disinnesco|
|**ID**|FR4|
|**Descrizione**|Immissione da parte di un utente qualificato a disattivare le funzioni d'allarme del ROBOT mediante un sistema di riconoscimento a PIN|
|**Motivazione**|Possibilità, da parte dell'utente, di disattivare il sistema senza l'utilizzo di uno smartphone|
|**Influisce**|Pressione tasti del sistema ROBOT per cambiare il suo stato da Attivo a Disattivo|
|**Specifica**|FRS4|

&nbsp;

### APPLICAZIONE

|          |               |
|----------|:-------------:|
|**Nome**|Primo Avvio|
|**ID**|FR5|
|**Descrizione**|Dopo aver installato l'applicazione e lanciata, viene chiesto all'utente di effettuare una primo paired (accoppiamento) con il ROBOT|
|**Motivazione**|Permettere il funzionamento del sistema mediante un accoppiamento con il ROBOT|
|**Influisce**|Successivi utilizzi dell'applicazione permetteranno il riconoscimento automatico del ROBOT precedentemente accoppiato|
|**Specifica**|FRS5|
&nbsp;

|          |               |
|----------|:-------------:|
|**Nome**|Settings' MENU|
|**ID**|FR6|
|**Descrizione**|Eseguendo un TAP sull'apposito campo dei Settings sarà possibile vedere le informazioni sullo stato del collegamento ed, eventualmente, cambiare le direttive|
|**Motivazione**|Dare la possibilità all'utente di poter scegliere le preferenze del comportamente del ROBOT|
|**Influisce**|Visualizzazione del MENU delle Impostazioni|
|**Specifica**|FRS6|

&nbsp;

|          |               |
|----------|:-------------:|
|**Nome**|Spegnimento e configurazione calendario programmato|
|**ID**|FR7|
|**Descrizione**|Possibilità di spegnere il sistema d'allarme da remoto. Si da, inoltre, la possibilità all'utente di impostare un calendario per la programmazione automatica delle accensioni e degli spegnimenti|
|**Motivazione**|Avere pieno controllo sul sistema d'allarme, potendolo bloccare quando non più necessario|
|**Influisce**|Spegnimento del sistema d'allarme|
|**Specifica**|FRS7|

&nbsp;

|          |               |
|----------|:-------------:|
|**Nome**|Visualizzazione LOG d'avviso|
|**ID**|FR8|
|**Descrizione**|L'applicazione notificherà eventuali intrusioni mediante un sistema di LOG a comparsa|
|**Motivazione**|Dare all'utente la consapevolezza di eventuali intromissioni di entità terze in ambienti dove è stato installato il sistema d'allarme|
|**Influisce**|Notifiche a video su smartphone|
|**Specifica**|FRS8|

&nbsp;

|          |               |
|----------|:-------------:|
|**Nome**|Spostamento remoto campo visivo del sistema d'allarme|
|**ID**|FR9|
|**Descrizione**|Dare la possibilità all'utente, mediante un'apposita sezione dell'applicazione, di effettuare uno spostamento remoto del campo visivo del ROBOT|
|**Motivazione**|Capacità, da parte dell'utente, di avere pieno controllo sulla scelta della porzione dell'ambiente dove focalizzarsi per le funzioni di sicurezza|
|**Influisce**|Mediante pressione di tasti si avrà lo spostamento della telecamera|
|**Specifica**|FRS9|

## 3.3 Definizione dei Requisiti non Funzionali

## 3.4 Evoluzione del sistema

## 3.5 Specifica dei Requisiti

|                              |                                          |
| ---------------------------- | ---------------------------------------- |
| **ID**                       | FRS1                                     |
| **Input**                    |                                          |
| **Output**                   | PIN d'accoppiamento                      |
| **Pre-condizioni**           | Avere un Robot con il programma caricato |
| **Post-condizioni**          | Robot pronto per l'accoppiamento         |
| **Requisiti non funzionali** |                                          |



|          |               |
|:---------|:--------------|
|**ID**|FRS2|
|**Input**|Un intruso entra nel campo visivo del Robot|
|**Output**|Il Robot emette un suono d'allarme ed invia una notifica all'utente|
|**Pre-condizioni**|L'allarme deve essere innescato|
|**Post-condizioni**|Esegue le azioni conseguenti alla scoperta dell'intruso|
|**Requisiti non funzionali**||

|                              |                                                              |
| ---------------------------- | ------------------------------------------------------------ |
| **ID**                       | FRS4                                                         |
| **Input**                    | Inserimento del PIN di disinnesco                            |
| **Output**                   | Il disinnesco dell'allarme senza dover ricorrere all'applicazione |
| **Pre-condizioni**           | L'allarme deve essere innescato                              |
| **Post-condizioni**          |                                                              |
| **Requisiti non funzionali** |                                                              |

|                              |                                                              |
| ---------------------------- | ------------------------------------------------------------ |
| **ID**                       | FRS5                                                         |
| **Input**                    | Inserimento di un PIN di accoppiamento, scelta di un PIN di disinnesco offline |
| **Output**                   |                                                              |
| **Pre-condizioni**           | É necessario avere un Robot pronto per l'accoppiamento       |
| **Post-condizioni**          | L'applicazione puó essere usata                              |
| **Requisiti non funzionali** |                                                              |

|                              |                                        |
| ---------------------------- | -------------------------------------- |
| **ID**                       | FRS6                                   |
| **Input**                    |                                        |
| **Output**                   | Scelta delle impostazioni per il Robot |
| **Pre-condizioni**           | L'applicazione deve essere operativa   |
| **Post-condizioni**          |                                        |
| **Requisiti non funzionali** |                                        |

|                              |                                                        |
| ---------------------------- | ------------------------------------------------------ |
| **ID**                       | FRS7                                                   |
| **Input**                    |                                                        |
| **Output**                   | Innesco e disinnesco automatico e manuale dell'allarme |
| **Pre-condizioni**           | L'applicazione deve essere operativa                   |
| **Post-condizioni**          | Andarsene via di casa tranquillo                       |
| **Requisiti non funzionali** |                                                        |

|                              |                                                              |
| ---------------------------- | ------------------------------------------------------------ |
| **ID**                       | FRS8                                                         |
| **Input**                    |                                                              |
| **Output**                   | Uno storico di tutte le intrusioni avvenute con foto allegate |
| **Pre-condizioni**           | L'allarme deve essersi innescato almeno una volta            |
| **Post-condizioni**          | Puó cancellare intrusioni dalla storico, qualora non le ritenga piú utili |
| **Requisiti non funzionali** |                                                              |

|                              |                                                 |
| ---------------------------- | ----------------------------------------------- |
| **ID**                       | FRS9                                            |
| **Input**                    | Cliccare sull'apposito pulsante                 |
| **Output**                   | Uno stream di immagini in diretta dal robot     |
| **Pre-condizioni**           | Il Robot deve essere acceso                     |
| **Post-condizioni**          | Possibilitá di muovere la webcam in tempo reale |
| **Requisiti non funzionali** |                                                 |

# 4 Appendici