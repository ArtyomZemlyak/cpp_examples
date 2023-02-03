#include <stdexcept>
#include <cmath>
#include <boost/test/auto_unit_test.hpp>
#include "rectangle.hpp"

BOOST_AUTO_TEST_SUITE(testRectangle)

const double error = 0.0001;

BOOST_AUTO_TEST_CASE(rectangleAfterMoveParameters)
{
  zemlyak::Rectangle rectangle_test({1, 2}, 3, 5);
  const double initial_area = rectangle_test.getArea();
  const zemlyak::rectangle_t initial_frame_rect = rectangle_test.getFrameRect();

  rectangle_test.move(10, 15);
  double current_area = rectangle_test.getArea();
  zemlyak::rectangle_t current_frame_rect = rectangle_test.getFrameRect();

  BOOST_CHECK_CLOSE(initial_area, current_area, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.width, current_frame_rect.width, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.height, current_frame_rect.height, error);

  rectangle_test.move({0, 1});
  current_area = rectangle_test.getArea();
  current_frame_rect = rectangle_test.getFrameRect();

  BOOST_CHECK_CLOSE(initial_area, current_area, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.width, current_frame_rect.width, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.height, current_frame_rect.height, error);
}

BOOST_AUTO_TEST_CASE(rectangleAfterScaleParameters)
{
  zemlyak::Rectangle rectangle_test({1, 2}, 3, 5);
  const double initial_area = rectangle_test.getArea();
  const zemlyak::rectangle_t initial_frame_rect = rectangle_test.getFrameRect();

  const int factor = 2;
  rectangle_test.scale(factor);
  double current_area = rectangle_test.getArea();
  zemlyak::rectangle_t current_frame_rect = rectangle_test.getFrameRect();

  BOOST_CHECK_CLOSE(initial_area * factor * factor, current_area, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.width * factor, current_frame_rect.width, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.height * factor, current_frame_rect.height, error);
}

BOOST_AUTO_TEST_CASE(rectangleAfterRotateParameters)
{
  zemlyak::Rectangle test_rectangle({4, 4}, 5, 8);
  double area_before = test_rectangle.getArea();

  double angle = 97.2;
  test_rectangle.rotate(angle);
  BOOST_CHECK_CLOSE(area_before, test_rectangle.getArea(), error);
  area_before = test_rectangle.getArea();

  angle = -27.4;
  test_rectangle.rotate(angle);
  BOOST_CHECK_CLOSE(area_before, test_rectangle.getArea(), error);
  area_before = test_rectangle.getArea();

  angle = 1087.23;
  test_rectangle.rotate(angle);
  BOOST_CHECK_CLOSE(area_before, test_rectangle.getArea(), error);
  area_before = test_rectangle.getArea();

  angle = -597.2;
  test_rectangle.rotate(angle);
  BOOST_CHECK_CLOSE(area_before, test_rectangle.getArea(), error);
}

BOOST_AUTO_TEST_CASE(rectangleThrowException)
{
  BOOST_CHECK_THROW(zemlyak::Rectangle({1, 2}, -1, -2), std::invalid_argument);

  zemlyak::Rectangle rectangle_test({1, 2}, 10, 15);
  BOOST_CHECK_THROW(rectangle_test.scale(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
