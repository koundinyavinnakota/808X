/**
 * @Driver - Koundinya Vinnakota
 * @Navigator - Mayank Sharma
 * @version - 0.1
 * @copyright - 2022 - vkd@umd.edu
 * @return int - 0, if there is no error in the code.
 */
#include <gtest/gtest.h>
#include <pid.hpp>


TEST(test_checkParams, Check_dt) {
  EXPECT_THROW(PID pid(1.0, 2.0, 3.0, 0.0, 0.0, 0.0), std::domain_error);
  EXPECT_THROW(PID pid(1.0, 2.0, 3.0, -5.0, 0.0, 0.0), std::domain_error);
}
TEST(test_checkParams, Check_Gains) {
  //  invalid Kp
  EXPECT_THROW(PID pid(0.0, 4.0, 4.0, 1.0, 0.0, 0.0), std::domain_error);
  EXPECT_THROW(PID pid(-2.0, 5.0, 3.0, 2.0, 0.0, 0.0), std::domain_error);

  //  invalid Kd
  EXPECT_THROW(PID pid(2.0, 2.0, 0.0, 1.0, 0.0, 0.0), std::domain_error);
  EXPECT_THROW(PID pid(2.0, 4.0, -3.0, 1.0, 0.0, 1.0), std::domain_error);
}

TEST(Functional_Test, Check_Output){
  // Parameters
    double k_p{0.1};
    double k_d{0.01};
    double k_i{0.5};
    double dt{0.1};
    double max{50};
    double min{-50};

    
    // Object initialization for the class PID
    PID controller_1(k_p, k_d, k_i, dt, max, min);
    
    // Displaying the computed velocity to the user
    double process_value{20};
    double set_point{10};
    double current_difference{0};
    double total_time{10};

    for (int time_step = 0; time_step < static_cast<int>(total_time / dt); time_step++)
    {
        current_difference = controller_1.ComputeVelocity(process_value, set_point);
        process_value += current_difference;
    }
    ASSERT_NEAR(process_value, set_point, 2);
}
