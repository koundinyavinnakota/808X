#ifndef INCLUDE_PID_HPP_
#define INCLUDE_PID_HPP_
/**
 * @Driver - Koundinya Vinnakota
 * @Navigator - Mayank Sharma
 * @version - 0.1
 * @copyright - 2022 - vkd@umd.edu
 * @return int - 0, if there is no error in the code.
 */
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::streamsize;
using std::string;
using std::vector;
/**
 * @brief This class computes velocity using the PID controller
 *
 */
class PID {
 private:
  double k_p;
  double k_i;
  double k_d;
  double dt;
  double min, max;
  double old_error, sum;

 public:
  PID(double kp, double k_d, double k_i, double dt, double max, double min);
  /**
   * @brief Function used for getting the Kp value
   * 
   * @return double
   */
  double Get_k_p();
  /**
   * @brief Function used for getting the K_d value
   *
   * @return double
   */
  double Get_k_d();
  /**
   * @brief Function used for getting the K_i value
   *
   * @return double
   */
  double Get_k_i();
  /**
   * @brief Function used to setting the K_p value
   *
   * @param value passed by user
   * @return auto
   */
  /**
   * @brief Function calculates the cummlative error
   *
   * @param cum_error
   * @return double cummalative error
   */
  double CalculateCummulativeError(double cum_error);
  /**
   * @brief Function to calcualte the derivative error
   *
   * @param error
   * @return double returns derivative error
   */
  double ErrorDerivativeCalculation(double error);
  /**
   * @brief Computes the velocity using reference setpoint
   *
   * @param position
   * @return auto
   */
  double ComputeVelocity(double process_value, double set_point);
  /**
   * @brief This fucntions validates the inputed parameters
   *
   * @param process_value The initial value for the PID controller
   * @param set_point The value we need from the controller
   */
  void CheckParams();
};
#endif  // INCLUDE_PID_HPP_
