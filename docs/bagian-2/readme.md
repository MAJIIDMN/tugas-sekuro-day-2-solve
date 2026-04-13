# Intruksi Penilaian

source codenya harus bisa di run sih, kalau gabisa kasih nilai sesuai progres aja

kalau tiap komponenenya sesuaiin sama ini:
(contoh jawaban yang sesuai bisa di cek pada folder ini)

1. first-move-destroyer: intinya bisa jalanin node move_destroyer tanpa error (output tidak diperdulikan)
2. check-node-destroyer: intinya bisa jalanin node check_move_destroyer tanpa error (output tidak diperdulikan)
3. auto-node-destroyer: intinya bisa jalanin node auto_mode_destroyer tanpa error (output tidak diperdulikan)
4. drive-node-destroyer: intinya bisa jalanin node drive_mode_destroyer tanpa error (output tidak diperdulikan)
5. check-autonomous-destroyer: log harus menunjukan bahwa yang disubscirbe adalah topic autonomous
6. check-drive-destroyer: log harus menunjukan bahwa yang disubscirbe adalah topic drive/manual
5. set-drive-destroyer: ini sama seperti no 4 sih (kesalahan intruksi aja, tapi harusnya aman)
6. move-node-destroyer: log harus menunjukan bahwa node melakukan subscribe twist untuk menjalankan robot 