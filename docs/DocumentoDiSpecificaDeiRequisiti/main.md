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

## 3.2 Definizione dei Requisiti Funzionali

### ROBOT

|          |               |
|----------|:-------------:|
|**Nome**|Accoppiamento ROBOT|
|**ID**|FR1|
|**Descrizione**|Si collega il dispositivo ROBOT allo smartphone del proprietario|
|**Motivazione**|Possibilità di visualizzare informazioni e comandare l'apparato a distanza, grazie ad una rete di collegamento|
|**Influisce**|Funzionalità principale del sistema d'allarme|
|**Specifica**|FRS1|
||

&nbsp;

|          |               |
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

|          |               |
|----------|:-------------:|
|**Nome**|PIN conferma disaccoppiamento|
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
||

&nbsp;

|          |               |
|----------|:-------------:|
|**Nome**|Settings' MENU|
|**ID**|FR6|
|**Descrizione**|Eseguendo un TAP sull'apposito campo dei Settings sarà possibile vedere le informazioni sullo stato del colegamento ed, eventualmente, cambiare le direttive|
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

### Da cambiare la descrizione dei campi

|          |               |
|----------|:-------------:|
|**ID**|Codice univoco della specifica dei requisiti|
|**Input**|Azione che l'utente deve compiere sul sistema|
|**Output**|Il dispositivo mostra cosa produce come output in seguito all'input dato dall'utente|
|**Pre-condizioni**|Descrive le condizioni che sono necessarie affinché l'utente possa compiere una determinata azione|
|**Post-condizioni**|Descrive che cosa ha a disposizione l'utente dopo l'azione che ha compiuto sul dispositivo|
|**Requisiti non funzionali**|La specifica di un requisito può essere associato ad un particolare requisito non funzionale|

# 4 Appendici
