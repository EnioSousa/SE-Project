package com.example.myapplication

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import java.net.Socket
import kotlin.concurrent.thread

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)


        val buttonliveviewbtn = findViewById<Button>(R.id.button_1)
        buttonliveviewbtn.setOnClickListener {
            val intent1 = Intent(this,LightsLiveView::class.java)
            startActivity(intent1)
        }

        val buttonsettingsbtn = findViewById<Button>(R.id.button2)
        buttonsettingsbtn.setOnClickListener {
            val intent2 = Intent(this,ButtonSettings::class.java)
            startActivity(intent2)
        }
    }
}