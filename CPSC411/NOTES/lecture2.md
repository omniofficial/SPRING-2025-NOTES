# LECTURE 2: XCODE Code Generation for IOS Applications

## REVIEW THE FOLLOWING:

1. Client-Server SQL API
2. Embedded SQL API
3. Entity Relationship Model (ER Model)

We can generate code for our application using either the **Storyboard Approach** or the **SwiftUI Approach**.

## Storyboard Approach

-   There are options to create projects such as the storyboard -> swift option.
-   Code is generated from the MVC pattern.

## What is the MVC Pattern?

An MVC Pattern follow three layers as seen below:

**Model Layer**:

-   Implements logic of managing (retrieving, modifying) data.

**View Layer:**

-   Implements logic of creating UI screens.

**Control Layer:**

-   Implements the following logic of:
    -   Populating data on the UI screen
    -   Processing events triggered by users

**STUDY IOS APPLICATION FRAMEWORK**

## Code Generation for IOS Application Framework

AppDelegate class and SceneDelegate class are common classes for application skeleton.

Storyboard is the visual tool to define.

-   A default **View Controller** defined
    -   Set up with _is Initial View Controller_ checkbox (via Attributes inspector)
-   Root View of the **Initial View Controller**

-   The storyboard **View Controller** is configured with one swift ViewController class (via Identity inspector) which will be used by developers to implement the custom logic


Identity Inspector + Attribute Inspector