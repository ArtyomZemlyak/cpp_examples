#include <stdexcept>
#include <cmath>
#include <boost/test/auto_unit_test.hpp>
#include "composite-shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

BOOST_AUTO_TEST_SUITE(testCompositeShape)

using shape_ptr = std::shared_ptr<zemlyak::Shape>;

const double error = 0.0001;

BOOST_AUTO_TEST_CASE(compositeShapeAfterMoveParameters)
{
  shape_ptr circle_test = std::make_shared<zemlyak::Circle>(1, 2, 3);
  shape_ptr rectangle_test = std::make_shared<zemlyak::Rectangle>(1, 2, 3, 5);
  zemlyak::CompositeShape shapes_test;
  shapes_test.add(circle_test);
  shapes_test.add(rectangle_test);
  const double initial_area = shapes_test.getArea();
  const zemlyak::rectangle_t initial_frame_rect = shapes_test.getFrameRect();

  shapes_test.move({0, 1});
  double current_area = shapes_test.getArea();
  zemlyak::rectangle_t current_frame_rect = shapes_test.getFrameRect();

  BOOST_CHECK_CLOSE(initial_area, current_area, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.width, current_frame_rect.width, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.height, current_frame_rect.height, error);

  shapes_test.move(10, 15);
  current_area = shapes_test.getArea();
  current_frame_rect = shapes_test.getFrameRect();

  BOOST_CHECK_CLOSE(initial_area, current_area, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.width, current_frame_rect.width, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.height, current_frame_rect.height, error);
}

BOOST_AUTO_TEST_CASE(compositeShapeAfterScaleParameters)
{
  shape_ptr circle_test = std::make_shared<zemlyak::Circle>(1, 2, 3);
  shape_ptr rectangle_test = std::make_shared<zemlyak::Rectangle>(1, 2, 3, 5);
  zemlyak::CompositeShape shapes_test;
  shapes_test.add(circle_test);
  shapes_test.add(rectangle_test);
  const double initial_area = shapes_test.getArea();
  const zemlyak::rectangle_t initial_frame_rect = shapes_test.getFrameRect();

  const int factor = 2;
  shapes_test.scale(factor);
  double current_area = shapes_test.getArea();
  zemlyak::rectangle_t current_frame_rect = shapes_test.getFrameRect();

  BOOST_CHECK_CLOSE(initial_area * factor * factor, current_area, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.width * factor, current_frame_rect.width, error);
  BOOST_CHECK_CLOSE(initial_frame_rect.height * factor, current_frame_rect.height, error);
}

BOOST_AUTO_TEST_CASE(compositeShapeAfterRotateParameters)
{
  shape_ptr test_circle = std::make_shared<zemlyak::Circle>(4, 7, 1);
  shape_ptr test_rectangle = std::make_shared<zemlyak::Rectangle>(5, 6, 4.5, 1.25);
  zemlyak::CompositeShape test_composite;
  test_composite.add(test_circle);
  test_composite.add(test_rectangle);
  double area_before = test_composite.getArea();

  double angle = 48.2;
  test_composite.rotate(angle);
  BOOST_CHECK_CLOSE(area_before, test_composite.getArea(), error);
  area_before = test_composite.getArea();

  angle = -30.88;
  test_composite.rotate(angle);
  BOOST_CHECK_CLOSE(area_before, test_composite.getArea(), error);
  area_before = test_composite.getArea();

  angle = 765.2;
  test_composite.rotate(angle);
  BOOST_CHECK_CLOSE(area_before, test_composite.getArea(), error);
  area_before = test_composite.getArea();

  angle = -987.3;
  test_composite.rotate(angle);
  BOOST_CHECK_CLOSE(area_before, test_composite.getArea(), error);
}

BOOST_AUTO_TEST_CASE(compositeShapeThrowException)
{
  shape_ptr test_circle = std::make_shared<zemlyak::Circle>(1, 2, 3);
  shape_ptr test_rectangle = std::make_shared<zemlyak::Rectangle>(4, 5, 6, 7);
  zemlyak::CompositeShape test_composite;
  test_composite.add(test_circle);
  test_composite.add(test_rectangle);
  BOOST_CHECK_THROW(test_composite.scale(-2), std::invalid_argument);

  BOOST_CHECK_THROW(test_composite.add(nullptr), std::invalid_argument);
  BOOST_CHECK_THROW(test_composite.remove(4), std::out_of_range);
  BOOST_CHECK_THROW(test_composite.remove(-2), std::out_of_range);

  BOOST_CHECK_THROW(test_composite[100], std::out_of_range);
  BOOST_CHECK_THROW(test_composite[-1], std::out_of_range);

  test_composite.remove(1);
  test_composite.remove(0);
  BOOST_CHECK_THROW(test_composite.remove(0), std::out_of_range);

}

BOOST_AUTO_TEST_SUITE_END()
