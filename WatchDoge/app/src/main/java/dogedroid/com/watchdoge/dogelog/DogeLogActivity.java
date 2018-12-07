package dogedroid.com.watchdoge.dogelog;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;

import dogedroid.com.watchdoge.R;

public class DogeLogActivity extends AppCompatActivity {

    RecyclerView list;
    ListaLog listAdaptor;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_doge_log);
        list = findViewById(R.id.log_list);
        listAdaptor = new ListaLog(getApplicationContext());
        list.setAdapter(listAdaptor);
        list.setLayoutManager(new LinearLayoutManager(this));

    }
}
