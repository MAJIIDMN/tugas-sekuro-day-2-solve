<p align="center" style="width=100%;">
  <img src="resources/semangat.gif" width="100%" alt="semangat">
</p>

## Tugas Sekuro Day 2

Package ROS 2 ini berisi beberapa node untuk simulasi kontrol `Destroyer`:
- `auto_mode_destroyer`
- `check_move_destroyer`
- `drive_mode_destroyer`
- `move_destroyer`

![rqt graf](resources/graph.png)

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

5. Jalankan node sisanya di terminal yang berbeda

## Menjalankan Node Satu per Satu (di terminal yang berbeda)(opsional)

```bash
ros2 run tugas-sekuro-day-2 auto_mode_destroyer
ros2 run tugas-sekuro-day-2 check_move_destroyer
ros2 run tugas-sekuro-day-2 drive_mode_destroyer
ros2 run tugas-sekuro-day-2 move_destroyer
```

## Struktur Direktori Program

```text
tugas-sekuro-day-2/
├── CMakeLists.txt
├── package.xml
├── readme.md
├── LICENSE
├── semangat.gif
├── graph.png
├── include/
├── launch/ #launch file
│   └── destroyer.launch.py
└── src/ #node file
	├── destroyer_auto.cpp
	├── destroyer_check.cpp
	├── destroyer_drive.cpp
	└── destroyer_move.cpp
```