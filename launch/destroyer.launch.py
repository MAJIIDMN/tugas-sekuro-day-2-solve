from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    auto_mode_node = Node(
        package='tugas-sekuro-day-2',
        executable='auto_mode_destroyer',
        name='auto_mode_destroyer',
        output='screen',
    )

    check_move_node = Node(
        package='tugas-sekuro-day-2',
        executable='check_move_destroyer',
        name='check_move_destroyer',
        output='screen',
    )

    return LaunchDescription([
        auto_mode_node,
        check_move_node,
    ])
