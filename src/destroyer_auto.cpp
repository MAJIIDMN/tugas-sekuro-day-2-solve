#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <random>

class DestroyerAuto : public rclcpp::Node
{
public:
  DestroyerAuto() : Node("auto_mode_destroyer")
  {
    publisher_auto_ = this->create_publisher<geometry_msgs::msg::Twist>("autonomous_destroyer", 10);

    std::random_device rd;
    linier_x_gen_ = std::mt19937(rd());
    linier_x_dist_ = std::uniform_real_distribution<double>(-5.0, 5.0);
    linier_y_gen_ = std::mt19937(rd());
    linier_y_dist_ = std::uniform_real_distribution<double>(-5.0, 5.0);
    angular_gen_ = std::mt19937(rd());
    angular_dist_ = std::uniform_real_distribution<double>(-1.0, 1.0);

    timer_ = this->create_wall_timer(
      std::chrono::milliseconds(500),
      std::bind(&DestroyerAuto::timer_callback, this));
  }

private:
  void timer_callback()
  {
    auto msg = geometry_msgs::msg::Twist();
    msg.linear.x = linier_x_dist_(linier_x_gen_);
    msg.linear.y = linier_y_dist_(linier_y_gen_);
    msg.angular.z = angular_dist_(angular_gen_);
    publisher_auto_->publish(msg);
  }
  
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_auto_;
  std::mt19937 linier_x_gen_;
  std::mt19937 linier_y_gen_;
  std::mt19937 angular_gen_;
  std::uniform_real_distribution<double> linier_x_dist_;
  std::uniform_real_distribution<double> linier_y_dist_;
  std::uniform_real_distribution<double> angular_dist_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<DestroyerAuto>());
  rclcpp::shutdown();
  return 0;
}