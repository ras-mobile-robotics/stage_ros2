# A pioneer robot optionally equipped with a laser range sensor and/or a QR-code reader

define pioneer_base position 
(
  color "red"                   # Default color.
  drive "diff"                  # Differential steering model.
  gui_nose 1                    # Draw a nose on the robot so we can see which way it points
  obstacle_return 1             # Can hit things.
  ranger_return 0.5             # reflects sonar beams
  blob_return 1                 # Seen by blobfinders  
  fiducial_return 1             # Seen as "1" fiducial finders

  localization "odom"           # Change to "gps" to have impossibly perfect, global odometry 
  odom_error [ 0.1 0.1 0.0 0.1 ]  # Odometry error or slip in X, Y and Theta  (Uniform random distribution)   
  # localization_origin [0 0 0 0]   # Start odometry at (0, 0, 0).  By default, this is copied from the model's initial pose

  # four DOF kinematics limits
  # [ xmin xmax ymin ymax zmin zmax amin amax ]        
  velocity_bounds [-1 1 0 0 0 0 -45.0 45.0 ]          
  acceleration_bounds [-0.5 0.5 0 0 0 0 -45 45.0 ]
)

define pioneer2dx_base_no_sonar pioneer_base
(
  # actual size
  size [0.44 0.38 0.22] # sizes from MobileRobots' web site

  # the pioneer's center of rotation is offset from its center of area
  origin [-0.04 0 0 0]

  # draw a nose on the robot so we can see which way it points
  gui_nose 0

  # estimated mass in KG
  mass 23.0 
)

# as above, but with front sonar only
define pioneer2dx_no_sonar pioneer2dx_base_no_sonar
(  
  # simplified Body shape:
  block( 
    points 8
    point[0] [-0.2 0.12]
    point[1] [-0.2 -0.12]
    point[2] [-0.12 -0.2555]
    point[3] [0.12 -0.2555]
    point[4] [0.2 -0.12]
    point[5] [0.2 0.12]
    point[6] [0.12 0.2555]
    point[7] [-0.12 0.2555]
    z [0 0.22]
  )
)


define hokuyolaser ranger
(
  sensor(       
    # laser-specific properties
    # factory settings for LMS200  
    pose [ 0 0 0 0 ]
    size [ 0.07 0.07 0.05 ]
    range [ 0.0  5.0 ]
    range_noise 0.01
    fov 270.0
    samples 270
    color_rgba [ 0 0 1 0.15 ]
  )
  model
  (
    # generic model properties
    pose [ 0.0 0.0 -0.2 0.0 ]
    size [ 0.07 0.07 0.05 ]  
    color "blue"
  )
)

define camera_realsens_d435 camera
(
	range [ 0.3 3.0 ]
	resolution [ 160 90 ]  # 1280 × 720 / 8
 	fov [ 87 58 ]
	pantilt [ 0 0 ]
	alwayson 1
  size [ 0.025 0.09 0.025 ]
  color "gray"
)

define pioneer2dx_with_laser pioneer2dx_no_sonar 
(
  # can refer to the robot by this name
  hokuyolaser(pose [ 0.15 0 0 0 ])
  model
  (
    # generic model properties
    pose [ -0.1 0.0 0 0.0 ]
    size [ 0.2 0.2 0.05 ]  
    color "DimGray"
  )
)

define pioneer2dx_with_laser_and_fiducial pioneer2dx_no_sonar 
(
  # can refer to the robot by this name
  hokuyolaser(pose [ 0.15 0 0 0 ])
  model
  (
    # generic model properties
    pose [ -0.1 0.0 0 0.0 ]
    size [ 0.2 0.2 0.05 ]  
    color "DimGray"
  )

  fiducial
  (
    # fiducial properties
    range_min 0.0
    range_max 8.0
    
    range_error 0.5
    bearing_error 0.2

    range_max_id 5.0
    fov 270
    ignore_zloc 1

    pose [ -0.1 0.0 0.1 0.0 ]
    model
    (
      # generic model properties
      pose [ 0.0 0.0 0 -0.05 ]
      size [ 0.05 0.05 0.1]  
      color "RoyalBlue"
    )
    alwayson 1 
  )
)

define pioneer2dx_with_laser_and_camera pioneer2dx_with_laser 
(
  # can refer to the robot by this name
  camera_realsens_d435(pose [ 0 0 0.5 0 ])
  mount( pose [ 0 -0.15 0 0.000 ] color "gray")
  mount( pose [ 0  0.15 0 0.000 ] color "gray")
)


define pioneer2dx_with_two_laser pioneer2dx_no_sonar 
(
  # can refer to the robot by this name
  hokuyolaser(pose [ 0.15 0.15 0 45 ])
  model
  (
    # generic model properties
    pose [ -0.1 0.0 0 0 ]
    size [ 0.2 0.2 0.05 ]  
    color "DimGray"
  )  
  hokuyolaser(pose [ -0.20 -0.15 0 -135 ])
  model
  (
    # generic model properties
    pose [ -0.1 0.0 0 0.0 ]
    size [ 0.2 0.2 0.05 ]  
    color "DimGray"
  )
)
