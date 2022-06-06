package com.example.myapplication

import android.os.Bundle
import android.widget.Button
import androidx.appcompat.app.AppCompatActivity
import java.net.Socket
import kotlin.concurrent.thread

class ButtonSettings : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_button_settings)

        thread {
            var socket = Socket("192.168.1.171", 8081)
            val writer = socket.getOutputStream()
            val reader = socket.getInputStream()
            val nextState = findViewById<Button>(R.id.button);
            val prevState = findViewById<Button>(R.id.button3);

            nextState.setOnClickListener {
                println("Request sent in order to change to next state!")
                writer.write(0);
            }

            prevState.setOnClickListener {
                println("Request sent in order to change to prev state!")
                writer.write(1);
            }

        }
    }
}