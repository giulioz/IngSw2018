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

# 2 Glossario

# 3 WatchDoge

## 3.1 Modelli del Sistema

| **Codice** | UC-01 |
| **Nome** | Abilita Accoppiamento |
| **Scopo** | Associare il robot ad un dispositivo Android per permetterne il controllo all'utente. |
| **Attori** | Utente |
| **Precondizioni** | \- |
| **Trigger** | Pressione del pulsante *Abilita accoppiamento* (robot) |
| **Descrizione** | Il robot accetta richieste di accoppiamento per un certo tempo. |
| **Alternative** | \- |
| **Postcondizioni** | Il robot è accoppiato con un dispositivo Android, oppure non è accoppiato |

| **Codice** | UC-02 |
| **Nome** | Visualizza Codice per Accoppiamento |
| **Scopo** | Mitigare la presa di controllo indesiderata del robot da parte di qualcun altro diverso dall'utente. |
| **Attori** | Utente |
| **Precondizioni** | UC-01 |
| **Trigger** | Il robot riceve una richiesta di accoppiamento. |
| **Descrizione** | Il robot visualizza un codice con cui il dispositivo che ha inviato la richiesta di accoppiamento deve rispondere per poter completare la procedura di accoppiamento. |
| **Alternative** | \- |
| **Postcondizioni** | Il successo della verifica garantisce che il dispositivo che ha inviato la richiesta di accoppiamento è effettivamente quello dell'utente. |

| **Codice** | UC-03 |
| **Nome** | Accoppia Robot |
| **Scopo** | Associare il dispositivo Android al robot per permetterne il controllo all'utente. |
| **Attori** | Utente |
| **Precondizioni** | Connessione alla stessa rete del robot, UC-01 |
| **Trigger** | Primo avvio dell'applicazione Android e pressione del pulsante *Accoppia robot* (applicazione Android) |
| **Descrizione** | L'applicazione Android cerca robot presenti nella stessa rete dello smartphone entro un certo tempo. Al termine, l'applicazione Android visualizza la lista di robot trovati, permettendo all'utente di selezionare quello da associare. |
| **Alternative** | \- |
| **Postcondizioni** | Il dispositivo Android è accoppiato con il robot |

| **Codice** | UC-04 |
| **Nome** | Inserisci Codice per Accoppiamento |
| **Scopo** | Mitigare la presa di controllo indesiderata del robot da parte di qualcun altro diverso dall'utente. |
| **Attori** | Utente |
| **Precondizioni** | UC-03 |
| **Trigger** | Selezione di un robot da associare |
| **Descrizione** | L'utente inserisce il codice di accoppiamento visualizzato dal robot e lo inserisce in un apposito campo. Successivamente, l'applicazione Android invia il codice al robot per la verifica. |
| **Alternative** | \- |
| **Postcondizioni** | Il successo della verifica garantisce che il dispositivo che ha inviato la richiesta di accoppiamento al robot è effettivamente quello dell'utente. |

| **Codice** | UC-05 |
| **Nome** | Visualizza Stato Robot |
| **Scopo** | Consentire all'utente di visualizzare in tempo reale le informazioni relative al robot. |
| **Attori** | Utente |
| **Precondizioni** | UC-03 |
| **Trigger** | Aprire l'applicazione Android |
| **Descrizione** | L'utente visualizza in tempo reale se l'antifurto è abilitato oppure no e la sua programmazione attraverso un'apposita interfaccia grafica. |
| **Alternative** | \- |
| **Postcondizioni** | L'utente è al corrente dello stato del robot. |

| **Codice** | UC-06 |
| **Nome** | Abilita/Disabita Robot |
| **Scopo** | Consentire all'utente di attivare/disattivare la funzione di antifurto del robot. |
| **Attori** | Utente |
| **Precondizioni** | UC-03 |
| **Trigger** | Pressione del pulsante *ON/OFF* (applicazione Android) |
| **Descrizione** | L'utente cambia lo stato del robot ad attivo/disattivo. |
| **Alternative** | \- |
| **Postcondizioni** | Il robot è attivo/disattivo. |

| **Codice** | UC-07 |
| **Nome** | Imposta Programmazione |
| **Scopo** | Consentire all'utente di decidere quando il robot deve attivarsi/disattivarsi automaticamente in determinate fasce orarie. |
| **Attori** | Utente |
| **Precondizioni** | UC-03 |
| **Trigger** | Pressione del pulsante *Programma* |
| **Descrizione** | L'utente abilita/disabilita la modalità automatica attraverso un interrutore e imposta le fasce orarie di attivazione del robot attraverso una tabella oraria settimanale. |
| **Alternative** | \- |
| **Postcondizioni** | Il robot è configurato in modalità automatica per attivarsi negli orari stabiliti dall'utente. |

| **Codice** | UC-08 |
| **Nome** | Controllo Remoto |
| **Scopo** | Consentire all'utente di guardare in tempo reale le immagini catturate dal robot e spostare la visuale. |
| **Attori** | Utente |
| **Precondizioni** | UC-03 |
| **Trigger** | Pressione del pulsante *Controllo remoto* |
| **Descrizione** | L'utente può connettersi da remoto al robot e visualizza le immagini catturate dalla fotocamera incorporata; inoltre, attraverso dei pulsanti direzionali, può spostare la visuale della fotocamera in base all'angolo di rotazione. |
| **Alternative** | \- |
| **Postcondizioni** | L'utente acquisisce una panoramica istantanea dell'ambiente dove è disposto il robot. |

| **Codice** | UC-09 |
| **Nome** | Cambia Stato Robot |
| **Scopo** | Attivare/disattivare/configurare una o più funzioni del robot. |
| **Attori** | Utente |
| **Precondizioni** | UC-03 |
| **Trigger** | Una richiesta proveniente dall'applicazione Android |
| **Descrizione** | Attraverso l'interfaccia grafica, l'utente invia una richiesta al robot per cambiare il suo stato. |
| **Alternative** | \- |
| **Postcondizioni** | Lo stato del robot viene cambiato a seconda della richiesta inviata. |

| **Codice** | UC-10 |
| **Nome** | Ottieni Stato Robot |
| **Scopo** | Consentire all'applicazione Android di riportare le informazioni relative alle funzioni del robot. |
| **Attori** | Utente |
| **Precondizioni** | UC-03 |
| **Trigger** | Una richiesta proveniente dall'applicazione Android |
| **Descrizione** | L'applicazione Android invia una richiesta al robot per ottenere il suo stato. |
| **Alternative** | \- |
| **Postcondizioni** | L'applicazione Android ottiene lo stato del robot a seconda della richiesta inviata. |

| **Codice** | UC-11 |
| **Nome** | Visualizza Storico Segnalazioni |
| **Scopo** | Consentire all'utente di avere un archivio delle segnalazioni di intrusioni rilevate dal robot. |
| **Attori** | Utente |
| **Precondizioni** | UC-03 |
| **Trigger** | Pressione del pulsante *Storico* (applicazione Android) |
| **Descrizione** | L'applicazione Android visualizza la lista delle ultime segnalazioni. |
| **Alternative** | \- |
| **Postcondizioni** | L'utente ha una visione generale delle segnalazioni rilevate dal robot. |

| **Codice** | UC-12 |
| **Nome** | Visualizza Notifica Segnalazione |
| **Scopo** | Consentire all'utente di ricevere immediatamente una segnalazione di intrusione. |
| **Attori** | Utente |
| **Precondizioni** | UC-03 |
| **Trigger** | Ricezione di una segnalazione dal robot |
| **Descrizione** | L'applicazione Android mostra una notifica con lo scopo di avvertire l'utente di un'intrusione rilevata dal robot. Inoltre, alla notifica viene allegata un'immagine dell'intruso. |
| **Alternative** | \- |
| **Postcondizioni** | L'utente può essere informato immediatamente quando viene rilevata un'intrusione. |

| **Codice** | UC-13 |
| **Nome** | Innesca Antifurto |
| **Scopo** | Mitigare le intrusioni all'interno dell'ambiente del robot. |
| **Attori** | Intruso |
| **Precondizioni** | UC-03 |
| **Trigger** | La fotocamera del robot rileva del movimento all'interno dell'ambiente |
| **Descrizione** | Il robot invia una segnalazione di intrusione al dispositivo accoppiato ed emette un suono d'allarme. |
| **Alternative** | \- |
| **Postcondizioni** | L'intruso viene rilevato e la sua presenza viene segnalata all'utente. |

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

## 3.3 Definizione dei Requisiti non Funzionali

## 3.4 Evoluzione del sistema

## 3.5 Specifica dei Requisiti

# 4 Appendici
