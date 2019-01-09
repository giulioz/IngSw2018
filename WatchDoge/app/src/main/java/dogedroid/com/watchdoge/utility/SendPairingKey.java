package dogedroid.com.watchdoge.utility;

import android.os.AsyncTask;
import android.util.Log;
import android.widget.EditText;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.toolbox.StringRequest;

import org.json.JSONObject;

import java.util.HashMap;
import java.util.Map;

import dogedroid.com.watchdoge.onboarding.OnBoarding_3;

public class SendPairingKey extends AsyncTask<Void, Void, Void> {


    private static final String TAG = "PORCODIO";

    public interface SendInterface {
        void onPost(boolean succeded);
    }

    private final SendInterface sInterface;

    private RequestQueue queue;
    private String pairingKey;
    private EditText inputText;

    private boolean succeded;
    private boolean waiting;


    public SendPairingKey(SendInterface si, RequestQueue queue, String pairingKey, EditText inputText) {
        sInterface = si;
        this.queue = queue;
        this.pairingKey = pairingKey;
        this.inputText = inputText;
    }

    public void stopThread() {
        this.waiting = false;
    }

    @Override
    protected void onPostExecute(Void aVoid) {
        super.onPostExecute(aVoid);
        sInterface.onPost(succeded);
    }

    @Override
    protected Void doInBackground(Void... voids) {
        waiting = true;
        succeded = false;
        String url = "http:/" + OnBoarding_3.ip + ":8000/pair";


        Map<String, String> params = new HashMap<>();
        params.put("clientKey", pairingKey);
        params.put("pairKey", inputText.getText().toString());

        JSONObject json = new JSONObject(params);

        Log.d(TAG, "json: " + json.toString());


        while (waiting) {
            Log.d(TAG, "doInBackground: WAITING RESPONSE");
            StringRequest request = new StringRequest(Request.Method.POST, url,
                    (response) -> {
                        succeded = true;
                        waiting = false;
                    },
                    (error) -> {
                        Log.d(TAG, "sendKey: errore send",error);
                        waiting = false;
                        succeded = false;
                    }) {
                @Override
                public Map<String, String> getHeaders() {
                    Map<String, String> params = new HashMap<>();
                    params.put("Content-Type", "application/json");
                    return params;
                }

                @Override
                public byte[] getBody() {
                    return json.toString().getBytes();
                }
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
