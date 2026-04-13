# Instruksi Penilaian

## Omni Directional
1. Output arah gerak roda robot harus sesuai dengan konfigurasi omni wheels (`fr`, `br`, `fl`, `bl`) berikut:

- `Maju`:
	`fr: Maju`, `br: Maju`, `fl: Maju`, `bl: Maju`

- `Mundur`:
	`fr: Mundur`, `br: Mundur`, `fl: Mundur`, `bl: Mundur`

- `Geser Kiri`:
	`fr: Mundur`, `br: Maju`, `fl: Maju`, `bl: Mundur`

- `Geser Kanan`:
	`fr: Maju`, `br: Mundur`, `fl: Mundur`, `bl: Maju`

- `Berputar Kiri`:
	`fr: Mundur`, `br: Mundur`, `fl: Maju`, `bl: Maju`

- `Berputar Kanan`:
	`fr: Maju`, `br: Maju`, `fl: Mundur`, `bl: Mundur`

- `Berhenti (Rem)`:
	`fr: Diam`, `br: Diam`, `fl: Diam`, `bl: Diam`

## Switch ON
1. harus ada folder launch lengkap dengan launch filenya di repository program
2. launch file harus bisa dijalankan 
3. node yang dijalankan oleh lauch file harus auto_mode_destroyer dan check_move_destroyer
4. setelah launch file dijalankan log harus langsung menunjukan bahwa node check_move_destroyer berhasil melakukan subscribe dari topic /autonomous_destroyer


## The Revelation of the Destroyer II
ini mah cek aja videonya, nilainya sesuaikan ;v

