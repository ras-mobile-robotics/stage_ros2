# stage_ros2 Install
## Install
```
# Install dependencies
sudo apt update
sudo apt install libfltk1.3-dev ros-jazzy-ackermann-msgs -y

# Clone repos
cd <YOUR_ROS2_WORKSPACE>
cd src
git clone https://github.com/ras-mobile-robotics/Stage.git
git clone https://github.com/ras-mobile-robotics/stage_ros2.git

# Init and Update rosdep
sudo rosdep init 
rosdep update

# Install ROS2 dependencies
rosdep install --from-paths ./Stage --ignore-src -r -y  # install dependencies for Stage
rosdep install --from-paths ./stage_ros2 --ignore-src -r -y  # install dependencies for stage_ros2

# Build Stage and Stage ROS2 Packages
cd <YOUR_ROS2_WORKSPACE>
colcon build --symlink-install 

```
