#include <boost/test/auto_unit_test.hpp>

#include "circle.hpp"
#include "composite-shape.hpp"
#include "matrix.hpp"
#include "partition.hpp"
#include "rectangle.hpp"

using shape_ptr = std::shared_ptr<zemlyak::Shape>;

BOOST_AUTO_TEST_SUITE(partitionTestSuite)

BOOST_AUTO_TEST_CASE(correctPartition)
{
  shape_ptr test_circle = std::make_shared<zemlyak::Circle>(-3, 2.5, 5);
  shape_ptr test_rectangle1 = std::make_shared<zemlyak::Rectangle>(2, -4.5, 2, 6);
  shape_ptr test_rectangle2 = std::make_shared<zemlyak::Rectangle>(0.5, -5.5, 11, 2);
  shape_ptr part_of_composite1 = std::make_shared<zemlyak::Rectangle>(2.5, -3, 5, 1);
  shape_ptr part_of_composite2 = std::make_shared<zemlyak::Rectangle>(-4, 0, 2, 17);
  zemlyak::CompositeShape composite;
  composite.add(part_of_composite1);
  composite.add(part_of_composite2);
  shape_ptr test_composite = std::make_shared<zemlyak::CompositeShape>(composite);

  zemlyak::CompositeShape test_composite1;
  test_composite1.add(test_circle);
  test_composite1.add(test_rectangle1);
  test_composite1.add(test_rectangle2);
  test_composite1.add(test_composite);

  zemlyak::Matrix test_matrix = zemlyak::part(test_composite1);

  BOOST_CHECK_EQUAL(test_matrix.getRows(), 3);
  BOOST_CHECK_EQUAL(test_matrix.getColumns(), 2);

  BOOST_CHECK(test_matrix[0][0] == test_circle);
  BOOST_CHECK(test_matrix[0][1] == test_rectangle2);
  BOOST_CHECK(test_matrix[1][0] == test_rectangle1);
  BOOST_CHECK(test_matrix[2][0] == test_composite);
}

BOOST_AUTO_TEST_SUITE_END()
