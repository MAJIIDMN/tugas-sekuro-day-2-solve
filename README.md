<p align="center" style="width=100%;">
  <img src="resources/semangat.gif" width="100%" alt="semangat">
</p>

## Tugas Sekuro Day 2

Package ROS 2 ini berisi beberapa node untuk simulasi kontrol `Destroyer`:
- `auto_mode_destroyer`
- `check_move_destroyer`
- `drive_mode_destroyer`
- `move_destroyer`

Node `move_destroyer` akan menampilkan:
- orientasi gerak robot (`Maju`, `Mundur`, `Geser`, `Berputar`, `Berhenti`)
- orientasi roda omni (`fr`, `br`, `fl`, `bl`) dalam bentuk `Maju/Mundur/Diam`

![rqt graph](resources/graph.png)

## Prasyarat

- ROS 2 sudah terpasang (disarankan distro yang sesuai dengan environment kamu, misalnya Humble).
- `colcon` dan `ament` tools sudah tersedia.

## Cara Build dan Run

1. Masuk ke root workspace ROS 2 kamu (folder yang berisi `src/`).
2. Build package:

```bash
colcon build --packages-select tugas-sekuro-day-2
```

3. Source environment hasil build:

```bash
source install/setup.bash
```

4. Jalankan launch file (node `auto_mode_destroyer` + `check_move_destroyer`):

```bash
ros2 launch tugas-sekuro-day-2 destroyer.launch.py
```

5. Jalankan node sisanya di terminal yang berbeda:

```bash
ros2 run tugas-sekuro-day-2 drive_mode_destroyer
ros2 run tugas-sekuro-day-2 move_destroyer
```

## Menjalankan Semua Node Satu per Satu (Opsional)

```bash
ros2 run tugas-sekuro-day-2 auto_mode_destroyer
ros2 run tugas-sekuro-day-2 check_move_destroyer
ros2 run tugas-sekuro-day-2 drive_mode_destroyer
ros2 run tugas-sekuro-day-2 move_destroyer
```

## Contoh Output Log Omni Wheels

Saat node `move_destroyer` menerima topic `power_destroyer`, log roda akan tampil dengan format:

```text
Orientasi Roda Omni | fr: <Maju/Mundur/Diam>, br: <Maju/Mundur/Diam>, fl: <Maju/Mundur/Diam>, bl: <Maju/Mundur/Diam>
```

Mapping arah omni wheels:
- `Maju`: `fr Maju`, `br Maju`, `fl Maju`, `bl Maju`
- `Mundur`: `fr Mundur`, `br Mundur`, `fl Mundur`, `bl Mundur`
- `Geser Kiri`: `fr Mundur`, `br Maju`, `fl Maju`, `bl Mundur`
- `Geser Kanan`: `fr Maju`, `br Mundur`, `fl Mundur`, `bl Maju`
- `Berputar Kiri`: `fr Mundur`, `br Mundur`, `fl Maju`, `bl Maju`
- `Berputar Kanan`: `fr Maju`, `br Maju`, `fl Mundur`, `bl Mundur`
- `Berhenti`: `fr Diam`, `br Diam`, `fl Diam`, `bl Diam`

Detail penilaian bonus tersedia di `docs/bonus/readme.md`.

## Struktur Direktori Program

```text
tugas-sekuro-day-2/
├── CMakeLists.txt
├── package.xml
├── README.md
├── LICENSE
├── docs/ # berisi intruksi penilaian dan jawaban
├── resources/
├── include/
├── launch/ # launch file
│   └── destroyer.launch.py
└── src/ # node file
	├── destroyer_auto.cpp
	├── destroyer_check.cpp
	├── destroyer_drive.cpp
	└── destroyer_move.cpp
```