package dogedroid.com.watchdoge.dogelog;

import android.content.Context;
import android.content.Intent;
import android.graphics.PorterDuff;
import android.support.annotation.NonNull;
import android.support.constraint.ConstraintLayout;
import android.support.v4.content.ContextCompat;
import android.support.v4.widget.CircularProgressDrawable;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import com.dezlum.codelabs.getjson.GetJson;
import com.google.gson.JsonArray;
import com.google.gson.JsonParser;
import com.squareup.picasso.Picasso;

import java.util.ArrayList;
import java.util.concurrent.ExecutionException;

import dogedroid.com.watchdoge.Pairing;
import dogedroid.com.watchdoge.R;

public class ListaLog extends RecyclerView.Adapter<ListaLog.ViewHolder> {

    private ArrayList<String> id = new ArrayList<>();
    private ArrayList<String> date = new ArrayList<>();

    private Context myContex;

    public ListaLog(Context myContex) {
        getListe();
        this.myContex = myContex;
    }

    private void getListe() {
        String json = null;
        try {
            json = new GetJson().AsString("http:/" + Pairing.dogeAddress + ":8000/intrusions/unread");
        } catch (ExecutionException e) {
            e.printStackTrace();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        JsonArray reader = new JsonParser().parse(json).getAsJsonArray();
        JsonArray array = reader.getAsJsonArray();

        if (array != null) {
            int len = array.size();
            for (int i = 0; i < len; i++) {
                id.add(array.get(i).getAsJsonObject().get("id").toString());
                date.add(array.get(i).getAsJsonObject().get("date").toString());
            }
        }

    }

    private String generateUrl(int i){
        return "http:/" + Pairing.dogeAddress + ":8000/intrusions/"+id.get(i)+"/shoot";
    }

    @NonNull
    @Override
    public ListaLog.ViewHolder onCreateViewHolder(@NonNull ViewGroup viewGroup, int i) {
        View view = LayoutInflater.from(viewGroup.getContext()).inflate(R.layout.recview_dogelog, viewGroup, false);
        ViewHolder viewHolder = new ViewHolder(view);
        return viewHolder;
    }

    @Override
    public void onBindViewHolder(@NonNull ListaLog.ViewHolder viewHolder, final int i) {
        viewHolder.data.setText(date.get(i));
        CircularProgressDrawable progressCircle = new CircularProgressDrawable(myContex);
        progressCircle.setStrokeWidth(20f);
        progressCircle.setColorFilter(ContextCompat.getColor(myContex, R.color.colorPrimary), PorterDuff.Mode.SRC_IN );

        Picasso.get().load(generateUrl(i)).placeholder(progressCircle).into(viewHolder.image);
    }

    @Override
    public int getItemCount() {
        return id.size();
    }

    public class ViewHolder extends RecyclerView.ViewHolder {
        TextView data;
        ImageView image;
        ConstraintLayout containerLayout;

        public ViewHolder(@NonNull View itemView) {
            super(itemView);
            data = itemView.findViewById(R.id.log_date);
            image = itemView.findViewById(R.id.log_image);
            containerLayout = itemView.findViewById(R.id.log_layout);
        }

    }

}
