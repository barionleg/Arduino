# Deskripsi Program

Ini adalah program pengamanan rumah. Program akan mengontrol arduino untuk 
mengunci pintu, jika ingin membuka pintu, masukkan <i>password</i> pintu yang telah diset,
kemudian apabila password cocok, pintu berhasil dibuka dan waktu terbukanya pintu
akan disimpan di database. Namun, jika sesorang memuka pintu tanpa memasukkan 
<i>password</i> yang benar, maka arduino akan mengirimkan sms peingatan keamanan 
kepada pemilik rumah.

# Fitur
## Input Password

Memasukkan password dengan keypad.
## Open The Door

Membuka pintu ketika password yang dimasukkan pengguna benar.
## isDoorOpen

Mengecek apakah pintu terbuka.
## Turn On The Light

Menyalakan lampu sesuai status isDoorOpen dan mengatur intensitas lampu
## isBroken

Mengecek apakah pintu dibuka dengan cara yang benar (password yang dimasukkan sudah benar.
## Database for Arduino

Menyambungkan database pada sql dengan arduino. 
# Pembagian Tugas

<b>Rizki Halasan</b>
1. Open The Door
2. Database for Arduino

<b>Leo Lambarita Nadeak</b>
1. Turn On The Lights
2. Input Password


<b>Robby Syaifullah</b>
1. isDoorOpen
2. isBroken