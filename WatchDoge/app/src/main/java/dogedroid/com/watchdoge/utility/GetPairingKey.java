package dogedroid.com.watchdoge.utility;

import android.os.AsyncTask;
import android.util.Log;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.toolbox.StringRequest;

import dogedroid.com.watchdoge.onboarding.OnBoarding_3;

public class GetPairingKey extends AsyncTask<Void, Void, Void> {
    private static final String TAG = "GetPairingKey";

    public interface GetInterface {
        void onPost(String response);
    }

    private final GetInterface sInterface;

    private String clientKey;
    private RequestQueue queue;

    private boolean waiting;


    public GetPairingKey(GetInterface si, RequestQueue queue) {
        sInterface = si;
        this.queue = queue;
    }

    public void stopThread() {
        this.waiting = false;
    }

    @Override
    protected void onPostExecute(Void aVoid) {
        super.onPostExecute(aVoid);
        sInterface.onPost(clientKey);
    }

    @Override
    protected Void doInBackground(Void... voids) {
        waiting = true;
        String url = "http:/" + OnBoarding_3.ip + ":8000/pair";

        while (waiting) {
            Log.d(TAG, "doInBackground: RICHESTA GET: " + url);
            StringRequest request = new StringRequest(Request.Method.GET, url,
                    (response) -> {
                        waiting = false;
                        clientKey = response;
                    },
                    (err) -> {
                        Log.d(TAG, "getClientKey: errore fetch " + err.getMessage());
                    }
            ) {
            };
            queue.add(request);
            Thread.currentThread();
            try {
                Thread.sleep(2000);
                request.cancel();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        return null;
    }
}
