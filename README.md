# ARShop

## Overview

ARShop is a simple project designed to facilitate the visualization of two-dimensional objects, such as carpets or paintings, in a home environment, to help make purchasing decisions. The fundamental concept relies on the use of an ArUco marker, allowing us to define a real-world plane where the projection of objects will occur. This real-time visualization helps users determine if the object fits appropriately within the intended space by assessing size and dimensions.

## Project Workflow

### 1. Camera Calibration

The initial stage includes the crucial process of camera calibration. This step provides valuable information such as intrinsic camera parameters, as well as distortion coefficients. Correct calibration is essential for accurate object projection.

![Alt Camera Calibration](https://github.com/ange-nguetsop/ARShop/blob/master/CppCLR_WinformsProject-main/CppCLR_WinformsProject/Calibration.gif)
### 2. Object Projection

Once the camera has been calibrated, the desired object is projected. This process is based on the detection of the ArUco marker, which will represent the origin of our reference frame. When the ArUco marker is detected, the camera's position relative to the marker is determined, and the camera's matrix and distortion coefficients are used to establish a correspondence between the object's 3D coordinates and the coordinates in the image plane of the camera.

### 3. Augmented Reality Visualization

Once the 3D coordinates of the object have been matched to the 2D coordinates of the camera plane, augmented reality visualization becomes possible.We can now project the object in the real world. The object can be rotated, resized and moved in real time. Live projection of the object is also possible.

![Alt Camera Calibration](https://github.com/ange-nguetsop/ARShop/blob/master/CppCLR_WinformsProject-main/CppCLR_WinformsProject/ImageView.gif)

## Additional Features

- **Object Manipulation**: Users can interactively rotate, resize, and relocate the projected object.
- **Live Projection**: The system supports real-time projection of the object using a camera.
![Alt Camera Calibration](https://github.com/ange-nguetsop/ARShop/blob/master/CppCLR_WinformsProject-main/CppCLR_WinformsProject/LiveView.gif)

## Further Enhancements

The project's scope can be expanded by integrating additional functionalities, such as:
- Advanced object interaction controls.
- Support for various marker types and sizes.
- Integration of more sophisticated rendering techniques for enhanced realism.

