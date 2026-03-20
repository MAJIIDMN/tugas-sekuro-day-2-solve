#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>

class SimplePublisher : public rclcpp::Node
{
public:
  SimplePublisher() : Node("destroyer_publisher_node")
  {
    // Membuat publisher ke topik "cmd_vel"
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
    
    // Timer untuk publish data setiap 1 detik (1000 ms)
    timer_ = this->create_wall_timer(
      std::chrono::milliseconds(1000),
      std::bind(&SimplePublisher::timer_callback, this));
  }

private:
  void timer_callback()
  {
    auto message = geometry_msgs::msg::Twist();
    message.linear.x = 0.5; // Contoh: maju dengan kecepatan 0.5
    message.angular.z = 0.1; // Contoh: belok sedikit
    
    // Tampilkan di CLI
    RCLCPP_INFO(this->get_logger(), "Publishing: Linear X=%.2f, Angular Z=%.2f", message.linear.x, message.angular.z);
    
    // Kirim pesan
    publisher_->publish(message);
  }
  
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SimplePublisher>());
  rclcpp::shutdown();
  return 0;
}