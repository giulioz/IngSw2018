**PROBLEMA**: Molti dispositivi Smart Home lavorano in modo indipendente l'uno dall'altro, non consentendo di sfruttare le possibilità che è possibile ottenere incrociando i vari tipi di dati prodotti.

**SOLUZIONE**: Realizzare un sistema che permetta di unificare diverse sorgenti di dati eterogenei provenienti da dispositivi Smart Home e fornirli all'utente dando la migliore esperienza possibile.

## REQUISITI

- Il sistema deve essere in grado di permette la comunicazione in maniera semplice per l'utente tra vari dispositivi Smart Home
- Il robot deve rilevare ed inviare allo smartphone tramite Internet informazioni relative a variabili ambientali di tipo meteorologico del luogo in cui è situato (come temperatura, umidità e pressione)
- Il robot deve rilevare eventuali intrusioni nel luogo in cui è situato su attivazione dell'utente
  - Il robot deve inviare un messaggio di allarme allo smartphone tramite Internet
  - Il robot deve tentare di scattare una fotografia del volto dell'intruso ed inviarla allo smartphone tramite Internet (anche in assenza di luce?)
  - Il robot deve essere in grado di percepire una sua eventuale manomissione (lo spostamento dal luogo in cui è stato originariamente collocato)
- Il sistema deve poter registrare dei promemoria (scritti o vocali) e comunicarli all'utente quando da lui pianificato
- Il sistema deve permettere all'utente di ricevere sullo smartphone immagini in tempo reale del luogo in cui è situato il robot e di comandare il robot dallo smartphone tramite Internet
- Il sistema può essere attivo in modalità giorno o modalità notte (?)
- Le funzioni del sistema devono poter essere attivate attraverso l'interfaccia utente dell'applicazione Android o un comando vocale
- Il sistema comprende un robot realizzato con il set Lego Mindstorms EV3 e uno smartphone Android



-----

# define sistema Lego_EV3

1) Spegnere il sistema:
​	- pulsantone ON/OFF per accendere, spegnere allarme;
​	- programmare per ora e data accensione e spegnimento allarme (calendario eventi);
​	- disabilitare automaticamente quando sente prossimità telefono;
​	- timeout spegnimento prima di notifica log;
​	- timeout per uscire di casa e non avere notifica log (come 30 secondi ti timeout);

2) Ricevere notifiche dal sistema:
​	- log con cronologia delle intrusioni passate con relativa foto;
​	- notifica istantanea in caso di intrusione, con rilevamento persone (o oggenti moventi);
​	

3) Comandare il sistema:

	- set comandi per girare e impostare;

4) Vedere l'output dei sensori del sistema:

- visualizzare a schermo (quindi su smartphone) lo stato corrente della ripresa del sensore video.



----

# Riunione Serale 22/10

Il robottino:

-  avrà due **<u>*COSE - STATI - MODALITA*</u>**

- Deve essere in grado di rilevare intrusioni tramite utilizzo di sensori. 
- Una volta rilevato un intruso ne storicizza l'evento scattandone una fotografia.
- Salvarsi lo storico dei movimenti rendendoli disponibile in un secondo momento mediante internet.
- Essere in grado di fornire uno stream video a richiesta e muoversi da remoto.
- Emettere un segnale acustico nel caso vengano rilevati movimenti all'interno della casa.
- Possibiltà di attivare e disattivare l'allarme tramite telefono in maniera automatica tramite programmazione.
- Deve potersi disabilitare tramite codice definito da applicazione.

L'applicazione Android:

- Deve essere in grado di poter visualizzare lo stream video.
- Poter spostare l'inquadratura della videocamera dell'allarme.
- Deve poter associarsi automaticamente al sistema dall'allarme.
- Deve poter ricevere notifiche e notificarle.
- Deve poter programmare, accendere e spegnere l'allarme.
- Deve poter mostrare le ultime intrusioni non ancora viste.
- Deve poter mostrare la cronologia delle intrusioni.
- Si può impostare un codice di disabilitazione dell'allarme.