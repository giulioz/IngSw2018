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
