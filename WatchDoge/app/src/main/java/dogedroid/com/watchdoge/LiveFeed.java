package dogedroid.com.watchdoge;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.AsyncTask;
import android.util.Log;
import android.widget.ImageView;

import java.io.InputStream;

public class LiveFeed extends AsyncTask<Void, Bitmap, Void> {
    public final long frameRate = 42;

    private ImageView image;
    private boolean run;

    public LiveFeed(ImageView im){
        this.image = im;
        this.run = true;
    }

    public void stopLive(){
        this.run = false;
    }

    @Override
    protected Void doInBackground(Void... voids) {
        while (run){
            Bitmap mIcon11 = null;
            try {
                InputStream in = new java.net.URL("http:/" + DiscoveryActivity.dogeAddress + ":8000/shoot").openStream();
                mIcon11 = BitmapFactory.decodeStream(in);
                publishProgress(mIcon11);
                // Frame Rate
                Thread.currentThread();
                Thread.sleep(this.frameRate);
            } catch (Exception e) {
                Log.e("Error", e.getMessage());
                e.printStackTrace();
            }
        }
        return null;
    }

    @Override
    protected void onProgressUpdate(Bitmap... values) {
        super.onProgressUpdate(values);
        image.setImageBitmap(values[0]);
    }

    @Override
    protected void onPostExecute(Void aVoid) {
        super.onPostExecute(aVoid);
        //image.setImageIcon();
    }
}
