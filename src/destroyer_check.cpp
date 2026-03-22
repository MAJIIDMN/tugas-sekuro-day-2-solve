#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <std_msgs/msg/string.hpp>
#include <chrono> // Tambahan untuk memanipulasi waktu

class DestroyerCheck : public rclcpp::Node
{
public:
  DestroyerCheck() : Node("check_move_destroyer")
  {
    publisher_power_ = this->create_publisher<geometry_msgs::msg::Twist>("power_destroyer", 10);
    publisher_type_ = this->create_publisher<std_msgs::msg::String>("move_type", 10);
    
    subscription_autonomous_ = this->create_subscription<geometry_msgs::msg::Twist>(
      "autonomous_destroyer", 10, std::bind(&DestroyerCheck::auto_callback, this, std::placeholders::_1));
      
    subscription_drive_ = this->create_subscription<geometry_msgs::msg::Twist>(
      "drive_destroyer", 10, std::bind(&DestroyerCheck::drive_callback, this, std::placeholders::_1));

    last_keyboard_time_ = rclcpp::Time(0, 0, this->get_clock()->get_clock_type());
    
    RCLCPP_INFO(this->get_logger(), "Node Check Move Destroyer AKTIF. Multiplexer siap!");
  }

private:
  void drive_callback(const geometry_msgs::msg::Twist::SharedPtr msg)
  {
    last_keyboard_time_ = this->now();

    publisher_power_->publish(*msg);

    auto type_msg = std_msgs::msg::String();
    type_msg.data = "Driver";
    RCLCPP_INFO(this->get_logger(), "Received from Driver: linear.x=%.2f, linear.y=%.2f, yaw=%.2f",
                msg->linear.x, msg->linear.y, msg->angular.z);
    publisher_type_->publish(type_msg);
  }

  void auto_callback(const geometry_msgs::msg::Twist::SharedPtr msg)
  {
    auto current_time = this->now();
    double time_since_last_keyboard = (current_time - last_keyboard_time_).seconds();

    if (time_since_last_keyboard > 0.5) {
        publisher_power_->publish(*msg);

        auto type_msg = std_msgs::msg::String();
        type_msg.data = "Autonomous";
        publisher_type_->publish(type_msg);
        RCLCPP_INFO(this->get_logger(), "Received from Autonomous: linear.x=%.2f, linear.y=%.2f, yaw=%.2f",
                    msg->linear.x, msg->linear.y, msg->angular.z);
    }
  }

  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_power_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_type_;
  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_autonomous_;
  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_drive_;
  rclcpp::Time last_keyboard_time_; 
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<DestroyerCheck>());
  rclcpp::shutdown();
  return 0;
}