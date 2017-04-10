package com.androidyuan.guetzliandroid;

import android.content.Intent;
import android.database.Cursor;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.os.AsyncTask;
import android.provider.MediaStore;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.util.Log;
import android.widget.Toast;

import com.androidyuan.compress.CompressJNI;

public class MainActivity extends AppCompatActivity {

    private static final int RESULT_LOAD_IMAGE=23123;

    private Button mButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        mButton = (Button) findViewById(R.id.button);
        mButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent i = new Intent(
                        Intent.ACTION_PICK,
                        android.provider.MediaStore.Images.Media.EXTERNAL_CONTENT_URI);
                startActivityForResult(i, RESULT_LOAD_IMAGE);

            }
        });


    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if (requestCode == RESULT_LOAD_IMAGE && resultCode == RESULT_OK && null != data) {
            Uri selectedImage = data.getData();
            String[] filePathColumn = { MediaStore.Images.Media.DATA };

            Cursor cursor = getContentResolver().query(selectedImage,
                    filePathColumn, null, null, null);
            cursor.moveToFirst();

            int columnIndex = cursor.getColumnIndex(filePathColumn[0]);
            String picturePath = cursor.getString(columnIndex);
            cursor.close();

            new  AsyncTask<String,String,String>(){

                @Override
                protected String doInBackground(String... strings) {

                    String path=strings.length>0?strings[0]:"";
                    if(TextUtils.isEmpty(path)) {
                        return null;
                    }
                    else {
                        int i=CompressJNI.compress(path,"/storage/emulated/0/Pictures/Screenshots/Screenshot_test.png");
                        return i+" --> /storage/emulated/0/Pictures/Screenshots/Screenshot_test.png";
                    }
                }

                @Override
                protected void onPostExecute(String s) {
                    super.onPostExecute(s);


                    toast("保存在：i="+s);
                }
            }.execute(picturePath);

        }

    }

    private void toast(String s) {
        Toast.makeText(this,s,Toast.LENGTH_SHORT).show();
        Log.d("",s);
    }


}
