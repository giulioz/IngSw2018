- PAIR

![pair: BENVENUTO](https://github.com/giulioz/IngSw2018/blob/master/docs/FinalMockup/Pair_mock/Pair_mock%20%E2%80%93%201.png)

Al primo avvio dell'applicazione avremo la fase di connessione al Doge (sistema Lego EV3).
La segente schermata darà all'utente il benvenuto e avvierà la fase guidata per il pair.

![pair: Accetta le condizioni](https://github.com/giulioz/IngSw2018/blob/master/docs/FinalMockup/Pair_mock/Pair_mock%20%E2%80%93%202.png)

La seconda schermata di pair chiederà all'utente di accettare le varie condizioni di utilizzo per permettere l'utilizzo del sistema (applicazione e robottino).
Se l'utente intende non accettare le condizioni (quindi tappare su RIFIUTA) verrà rimandato direttamente alla schermata di BENVENUTO.
Se l'utente intende accettare le condizioni verrà guidata alla fase successiva di pairing.

![pair: Doge nelle Vicinanze](https://github.com/giulioz/IngSw2018/blob/master/docs/FinalMockup/Pair_mock/Pair_mock%20%E2%80%93%203.png)

La terza schermata di pair avvierà nell'applicazione la fase di DISCOVER per permettere la ricerca nella vicinanze di sistemi DOGE (robottino).
Sarà quindi l'utente a scegliere il DOGE voluto (mediante la loro identificazione attraverso il loro nome in rete).

![pair: Connetti Doge](https://github.com/giulioz/IngSw2018/blob/master/docs/FinalMockup/Pair_mock/Pair_mock%20%E2%80%93%204.png)

La quarta schermata di pair obbligherà l'utente ad inserire il codice d'autentificazione (visualizzato nel display del Lego EV3) per consentire l'accoppiamento fra Doge (robottino) e l'applicazione, permettendo a quest'ultima di interagire con il sistema si sicurezza.

![pair: Connetti Doge_fail](https://github.com/giulioz/IngSw2018/blob/master/docs/FinalMockup/Pair_mock/Pair_mock%20%E2%80%93%206.png)

La quinta schermata di pair verrà mostrata solamente nel caso in cui l'utente inserisca un codice di autenficazione errato rispetto a quello mostrato nel display del LEGO EV3 (Doge) scelto.
L'utente sarà quindi invitato a ri-inserire il codice. Se anch'esso risulterà errato verrà visualizzata nuovamente questa quinta schermata, altrimenti verrà portato alla scherma successiva di pair.
L'utente avrà inoltre la possibilità di tornare alla scherma precedente (premendo il tasto: INDIETRO), potendo scegliere un Doge (robottino) diverso.

![pair: Complimenti](https://github.com/giulioz/IngSw2018/blob/master/docs/FinalMockup/Pair_mock/Pair_mock%20%E2%80%93%205.png)

La sesta schermata di pair dirà all'utente dell'avvenuto collegamento fra l'applicazione e il sistema dall'allarme Doge.
Tappando sul tasto INIZIA sarà quindi possibile cominicare ad utilizzare tutte le funzionalità offerte all'utente in merito al controllo del robottino.

- MAIN

![main: Main_activity](https://github.com/giulioz/IngSw2018/blob/master/docs/FinalMockup/Main_mock/Main_mock%20%E2%80%93%201.png)

Il Main Activty dell'applicazione permetterà all'utente una veloce visione di tutte le principale funzionalità offerte in merito al controllo a distanza del sistema di sicurezza.
Questa schermata si comporrà di più componenti:

1) Live Feed: questa finestra mostrarà un video in diretta dell'ambiente puntato dal Doge. L'utente sarà quindi in grado di vedere in live dell'area puntata della camera collegato al sistema di sicurezza;
2) Sistema di controllo: mediante alla frecce "SINISTRA" "DESTRA" l'utente sarà in gradi di spostare la camera, permettendo quindi di cambiare l'area di interesse del Live Feed.
3) ON/OFF: attraverso questo pulsante l'utente sarà in grado di Accendere o Spegnere il sistema di sicurezza, potendo abilitare o disabilitare il sensore Sonar del Lego EV3 che permetterà di intercettare passaggio di intrusi nell'area di interesse.
4) AUTO - PROGRAMMA: grazie alla spunta sul campo AUTO l'utente potrà pianificare l'accensione e lo spegnimento automatico del sistema di sicurezza (robottino), settato in precedenza mediante un tap su PROGRAMMA (che farà visualizzare un calendario per definire giorni ed orari in cui il sistema dovrà funzionare).
5) Ultime Intrusioni: questa porzione di schermata offrirà all'utente un sistema di notifiche veloce per le ultime intrusione non ancora visualizzate. Attraverso un tap su in questo campo l'utente verrà indirizzato alla schermata STORICO INTRUSIONI.

![main: Main_activity_settings](https://github.com/giulioz/IngSw2018/blob/master/docs/FinalMockup/Main_mock/Main_mock%20%E2%80%93%202.png)

Con un tap sul campo impostazioni (tre puntini verticali) l'utente sarò in grado di visualizzare la possibilità di disaccoppiare del sistema di sicurezza (Doge) precedentemente scelto (si tornaerà quindi alla prima schermata della fase di Pair - Accoppiamento) oppure alcune informazioni aggiuntive, per esempio gli sviluppatore del sistema di sicurezza (robottino e applicazione).

![main: STORICO INTRUSIONI](https://github.com/giulioz/IngSw2018/blob/master/docs/FinalMockup/Main_mock/Main_mock%20%E2%80%93%203.png)

In questa schermata l'utente potrà visualizzare una cronologia di tutte le intrusioni relevate dal sistema di sicurezza, potendo apprenderne il giorno e l'ora dell'intrusione.