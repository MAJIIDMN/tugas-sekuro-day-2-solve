#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>

class SimpleSubscriber : public rclcpp::Node
{
public:
  SimpleSubscriber() : Node("destroyer_subscriber_node")
  {
    // Membuat subscriber dari topik "cmd_vel"
    subscription_ = this->create_subscription<geometry_msgs::msg::Twist>(
      "cmd_vel", 10, std::bind(&SimpleSubscriber::topic_callback, this, std::placeholders::_1));
  }

private:
  void topic_callback(const geometry_msgs::msg::Twist & msg) const
  {
    // Tampilkan data yang diterima ke CLI
    RCLCPP_INFO(this->get_logger(), "I heard: Linear X='%.2f'", msg.linear.x);
  }
  
  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SimpleSubscriber>());
  rclcpp::shutdown();
  return 0;
}