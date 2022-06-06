package com.example.myapplication

import android.graphics.Color
import android.os.Bundle
import android.system.Os.socket
import android.widget.Button
import androidx.appcompat.app.AppCompatActivity
import java.io.OutputStream
import java.io.OutputStreamWriter
import java.io.PrintWriter
import java.net.Inet4Address
import java.net.Socket
import javax.net.ssl.HostnameVerifier
import kotlin.concurrent.thread
import kotlin.math.log

class LightsLiveView : AppCompatActivity() {


    private var currentState = 0;


    private fun state0() {
        val semaphore1 = findViewById<Button>(R.id.button5)
        val semaphore2 = findViewById<Button>(R.id.button6)
        val semaphore3 = findViewById<Button>(R.id.button7)
        val semaphore4 = findViewById<Button>(R.id.button8)
        val semaphore5 = findViewById<Button>(R.id.button9)
        semaphore1.setBackgroundColor(Color.GREEN)
        semaphore2.setBackgroundColor(Color.GREEN)
        semaphore3.setBackgroundColor(Color.RED)
        semaphore4.setBackgroundColor(Color.GREEN)
        semaphore5.setBackgroundColor(Color.RED)

    }

    private fun state1() {
        val semaphore1 = findViewById<Button>(R.id.button5)
        val semaphore2 = findViewById<Button>(R.id.button6)
        val semaphore3 = findViewById<Button>(R.id.button7)
        val semaphore4 = findViewById<Button>(R.id.button8)
        val semaphore5 = findViewById<Button>(R.id.button9)
        semaphore1.setBackgroundColor(Color.YELLOW)
        semaphore2.setBackgroundColor(Color.YELLOW)
        semaphore3.setBackgroundColor(Color.RED)
        semaphore4.setBackgroundColor(Color.GREEN)
        semaphore5.setBackgroundColor(Color.RED)

    }

    private fun state2() {
        val semaphore1 = findViewById<Button>(R.id.button5)
        val semaphore2 = findViewById<Button>(R.id.button6)
        val semaphore3 = findViewById<Button>(R.id.button7)
        val semaphore4 = findViewById<Button>(R.id.button8)
        val semaphore5 = findViewById<Button>(R.id.button9)
        semaphore1.setBackgroundColor(Color.RED)
        semaphore2.setBackgroundColor(Color.RED)
        semaphore3.setBackgroundColor(Color.GREEN)
        semaphore4.setBackgroundColor(Color.RED)
        semaphore5.setBackgroundColor(Color.GREEN)

    }

    private fun state3() {
        val semaphore1 = findViewById<Button>(R.id.button5)
        val semaphore2 = findViewById<Button>(R.id.button6)
        val semaphore3 = findViewById<Button>(R.id.button7)
        val semaphore4 = findViewById<Button>(R.id.button8)
        val semaphore5 = findViewById<Button>(R.id.button9)
        semaphore1.setBackgroundColor(Color.RED)
        semaphore2.setBackgroundColor(Color.RED)
        semaphore3.setBackgroundColor(Color.YELLOW)
        semaphore4.setBackgroundColor(Color.RED)
        semaphore5.setBackgroundColor(Color.GREEN)

    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_lights_live_view)

    }

    override fun onStart() {
        super.onStart()

        thread {
            val socket = Socket("192.168.1.171", 8080)
            val writer = socket.getOutputStream()
            val reader = socket.getInputStream()

            var message: Byte;
            var message1: Int;

            this@LightsLiveView.currentState = 0
            this@LightsLiveView.runOnUiThread(java.lang.Runnable {
                state0()
            })

            while (true) {
                message = reader.read().toByte()
                message1 = message.toInt();
                if (message1 == -1 || message1 == 10)
                    continue

                message1 -= 48;

                when (message1) {
                    0 -> {
                        this@LightsLiveView.currentState = 0
                        this@LightsLiveView.runOnUiThread(java.lang.Runnable {
                            state0()
                        })
                    }
                    1 -> {
                        this@LightsLiveView.currentState = 1;
                        this@LightsLiveView.runOnUiThread(java.lang.Runnable {
                            state1()
                        })
                    }
                    2 -> {
                        this@LightsLiveView.currentState = 2;
                        this@LightsLiveView.runOnUiThread(java.lang.Runnable {
                            state2()
                        })
                    }
                    3 -> {
                        this@LightsLiveView.currentState = 3;
                        this@LightsLiveView.runOnUiThread(java.lang.Runnable {
                            state3()
                        })
                    }
                }


                println(message1)
                message1 = -1

            }
        }
    }
}