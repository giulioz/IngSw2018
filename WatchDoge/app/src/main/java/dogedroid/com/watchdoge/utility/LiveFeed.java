package dogedroid.com.watchdoge.utility;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.AsyncTask;
import android.util.Log;
import android.widget.ImageView;

import com.squareup.picasso.MemoryPolicy;

import java.io.InputStream;

import dogedroid.com.watchdoge.DiscoveryActivity;

public class LiveFeed extends AsyncTask<Void, Bitmap, Void> {
    public final long frameRate = 0;

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
                mIcon11 = DiscoveryActivity.picasso
                        .load(DiscoveryActivity.getUrl("/shoot"))
                        .memoryPolicy(MemoryPolicy.NO_CACHE, MemoryPolicy.NO_STORE)
                        .get();
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
