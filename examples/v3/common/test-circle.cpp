#include <stdexcept>
#include <cmath>
#include <boost/test/auto_unit_test.hpp>
#include "circle.hpp"

BOOST_AUTO_TEST_SUITE(testCircle)

const double error = 0.0001;

BOOST_AUTO_TEST_CASE(circleAfterMoveParameters)
{
  zemlyak::Circle circle_test({1, 2}, 3);
  const double initial_area = circle_test.getArea();
  const zemlyak::rectangle_t initial_frame_rect = circle_test.getFrameRect();

  circle_test.move(10, 15);
  double current_area = circle_test.getArea();
  zemlyak::rectangle_t current_frame_rect = circle_test.getFrameRect();

  BOOST_CHECK_CLOSE(initial_area, current_area, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.width, current_frame_rect.width, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.height, current_frame_rect.height, error);

  circle_test.move({0, 1});
  current_area = circle_test.getArea();
  current_frame_rect = circle_test.getFrameRect();

  BOOST_CHECK_CLOSE(initial_area, current_area, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.width, current_frame_rect.width, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.height, current_frame_rect.height, error);
}

BOOST_AUTO_TEST_CASE(circleAfterScaleParameters)
{
  zemlyak::Circle circle_test({1, 2}, 3);
  const double initial_area = circle_test.getArea();
  const zemlyak::rectangle_t initial_frame_rect = circle_test.getFrameRect();

  const int factor = 2;
  circle_test.scale(factor);
  double current_area = circle_test.getArea();
  zemlyak::rectangle_t current_frame_rect = circle_test.getFrameRect();

  BOOST_CHECK_CLOSE(initial_area * factor * factor, current_area, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.width * factor, current_frame_rect.width, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.height * factor, current_frame_rect.height, error);
}

BOOST_AUTO_TEST_CASE(circleAfterRotateParameters)
{
  zemlyak::Circle test_circle({4, 4}, 5);
  double area_before = test_circle.getArea();

  double angle = 37.8;
  test_circle.rotate(angle);
  BOOST_CHECK_CLOSE(area_before, test_circle.getArea(), error);
  area_before = test_circle.getArea();

  angle = -56.88;
  test_circle.rotate(angle);
  BOOST_CHECK_CLOSE(area_before, test_circle.getArea(), error);
  area_before = test_circle.getArea();

  angle = 384.2;
  test_circle.rotate(angle);
  BOOST_CHECK_CLOSE(area_before, test_circle.getArea(), error);
  area_before = test_circle.getArea();

  angle = -887.3;
  test_circle.rotate(angle);
  BOOST_CHECK_CLOSE(area_before, test_circle.getArea(), error);
}

BOOST_AUTO_TEST_CASE(circleThrowException)
{
  BOOST_CHECK_THROW(zemlyak::Circle({1, 2}, -1), std::invalid_argument);

  zemlyak::Circle circle_test({1, 2}, 5);
  BOOST_CHECK_THROW(circle_test.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
