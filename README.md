# ARShop

## Overview

This project aims to develop an augmented reality (AR) software application that projects virtual objects into the real world with their actual dimensions. Using OpenCV and C++, the software will allow users to evaluate whether a particular object fits well in an environment in terms of size, color, and overall aesthetics.

## Purpose
The primary purpose of this software is to provide a tool for interior designers, architects, and individuals who wish to visualize how different objects (furniture, artworks, etc.) would look in a specific real-world setting.

## Project Workflow

### 1. Camera Calibration

The initial stage includes the process of camera calibration. This step provides valuable information such as intrinsic camera parameters, as well as distortion coefficients. Correct calibration is essential for accurate object projection.

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

