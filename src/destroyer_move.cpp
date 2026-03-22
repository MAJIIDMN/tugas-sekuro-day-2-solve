#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <std_msgs/msg/string.hpp>
#include <string>

class DestroyerMove : public rclcpp::Node
{
public:
  DestroyerMove() : Node("move_destroyer")
  {
    subscription_power_ = this->create_subscription<geometry_msgs::msg::Twist>(
      "power_destroyer", 10, std::bind(&DestroyerMove::topic_callback_power, this, std::placeholders::_1));
      
    subscription_type_ = this->create_subscription<std_msgs::msg::String>(
      "move_type", 10, std::bind(&DestroyerMove::topic_callback_type, this, std::placeholders::_1));
      
    RCLCPP_INFO(this->get_logger(), "Node Move Destroyer AKTIF. Menunggu instruksi...");
  }

private:
  void topic_callback_power(const geometry_msgs::msg::Twist::SharedPtr msg) const
  {
    std::string arah_gerak = "";

    if (msg->linear.x > 0.0) arah_gerak += "Maju ";
    else if (msg->linear.x < 0.0) arah_gerak += "Mundur ";

    if (msg->linear.y > 0.0) arah_gerak += "Geser Kiri ";
    else if (msg->linear.y < 0.0) arah_gerak += "Geser Kanan ";

    if (msg->angular.z > 0.0) arah_gerak += "Berputar Kiri ";
    else if (msg->angular.z < 0.0) arah_gerak += "Berputar Kanan ";

    if (msg->linear.x == 0.0 && msg->linear.y == 0.0 && msg->angular.z == 0.0) {
        arah_gerak = "Berhenti (Rem)";
    }

    RCLCPP_INFO(this->get_logger(), "Orientasi Gerak : %s", arah_gerak.c_str());
  }
  void topic_callback_type(const std_msgs::msg::String::SharedPtr msg) const
  {
    RCLCPP_INFO(this->get_logger(), "Tipe KendaliAktif: %s", msg->data.c_str());
  }
  
  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_power_;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_type_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<DestroyerMove>());
  rclcpp::shutdown();
  return 0;
}