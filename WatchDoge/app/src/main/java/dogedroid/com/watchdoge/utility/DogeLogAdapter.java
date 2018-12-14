package dogedroid.com.watchdoge.utility;

import android.content.Context;
import android.graphics.PorterDuff;
import android.icu.text.DateFormat;
import android.icu.text.SimpleDateFormat;
import android.support.annotation.NonNull;
import android.support.constraint.ConstraintLayout;
import android.support.v4.content.ContextCompat;
import android.support.v4.widget.CircularProgressDrawable;
import android.support.v7.widget.RecyclerView;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import com.android.volley.AuthFailureError;
import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.toolbox.JsonArrayRequest;
import com.android.volley.toolbox.Volley;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

import dogedroid.com.watchdoge.DiscoveryActivity;
import dogedroid.com.watchdoge.R;

public class DogeLogAdapter extends RecyclerView.Adapter<DogeLogAdapter.ViewHolder> {

    private ArrayList<String> id = new ArrayList<>();
    private ArrayList<Long> date = new ArrayList<>();

    private String addedLink;
    private Context myContex;

    public DogeLogAdapter(Context myContex, String addedLink) {
        this.myContex = myContex;
        this.addedLink = addedLink;

        fetchListe();
    }

    public DogeLogAdapter(Context myContex) {
        this(myContex, "");
    }

    private void fetchListe() {
        String url = DiscoveryActivity.getUrl("/intrusions" + this.addedLink);
        JsonArrayRequest request = new JsonArrayRequest(Request.Method.GET, url, null,
                (response) -> {
                    for(int i = 0 ; i < response.length() ; i++){
                        try {
                            JSONObject obj = response.getJSONObject(i);
                            id.add(obj.getString("id"));
                            date.add(obj.getLong("time"));
                        } catch (JSONException e) {
                            Log.d("LISTALOG", "fetchListe2: errore json");
                            e.printStackTrace();
                        }
                    }
                    this.notifyDataSetChanged();
                },
                (err) -> {
                    Log.d("LISTALOG", "fetchListe2: errore fetch");
                }
        ){
            @Override
            public Map<String, String> getHeaders() throws AuthFailureError {
                Map<String, String> params = new HashMap<String, String>();
                params.put("Content-Type", "application/json; charset=UTF-8");
                params.put("Authorization", "Bearer " + DiscoveryActivity.token);
                return params;
            }
        };
        RequestQueue queue = Volley.newRequestQueue(myContex);
        queue.add(request);

    }

    private String generateUrl(int i) {
        return DiscoveryActivity.getUrl("/intrusions/" + id.get(i) + "/shoot");
    }

    @NonNull
    @Override
    public DogeLogAdapter.ViewHolder onCreateViewHolder(@NonNull ViewGroup viewGroup, int i) {
        View view = LayoutInflater.from(viewGroup.getContext()).inflate(R.layout.recview_dogelog, viewGroup, false);
        ViewHolder viewHolder = new ViewHolder(view);
        return viewHolder;
    }

    @Override
    public void onBindViewHolder(@NonNull DogeLogAdapter.ViewHolder viewHolder, final int i) {

        Date data = new Date(date.get(i) * 1000);
        //Date data = new Date(1544626713 * 1000);

        DateFormat dataFormat = new SimpleDateFormat("d/M/y");
        DateFormat oraFormat = new SimpleDateFormat("H:m");

        viewHolder.data.setText(dataFormat.format(data));
        viewHolder.ora.setText(oraFormat.format(data));

        CircularProgressDrawable progressCircle = new CircularProgressDrawable(myContex);
        progressCircle.setStrokeWidth(20f);
        progressCircle.setColorFilter(ContextCompat.getColor(myContex, R.color.colorPrimary), PorterDuff.Mode.SRC_IN);

        DiscoveryActivity.picasso
                .load(generateUrl(i))
                .placeholder(progressCircle)
                .into(viewHolder.image);
    }

    @Override
    public int getItemCount() {
        return id.size();
    }

    public class ViewHolder extends RecyclerView.ViewHolder {
        TextView data;
        TextView ora;
        ImageView image;
        ConstraintLayout containerLayout;

        public ViewHolder(@NonNull View itemView) {
            super(itemView);
            data = itemView.findViewById(R.id.log_date);
            ora = itemView.findViewById(R.id.log_ora);
            image = itemView.findViewById(R.id.logo);
            containerLayout = itemView.findViewById(R.id.log_layout);
        }

    }

}
