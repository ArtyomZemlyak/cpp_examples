#include <boost/test/auto_unit_test.hpp>

#include "circle.hpp"
#include "composite-shape.hpp"
#include "matrix.hpp"
#include "partition.hpp"
#include "rectangle.hpp"

using shape_ptr = std::shared_ptr<zemlyak::Shape>;

BOOST_AUTO_TEST_SUITE(matrixTestSuite)

BOOST_AUTO_TEST_CASE(copyAndMove)
{
  shape_ptr test_circle = std::make_shared<zemlyak::Circle>(1, 2, 3);
  zemlyak::CompositeShape test_composite;
  test_composite.add(test_circle);

  zemlyak::Matrix test_matrix = zemlyak::part(test_composite);

  BOOST_CHECK_NO_THROW(zemlyak::Matrix test_matrix2(test_matrix));
  BOOST_CHECK_NO_THROW(zemlyak::Matrix test_matrix2(std::move(test_matrix)));

  zemlyak::Matrix test_matrix2 = zemlyak::part(test_composite);
  zemlyak::Matrix test_matrix3;

  BOOST_CHECK_NO_THROW(test_matrix3 = test_matrix2);
  BOOST_CHECK_NO_THROW(test_matrix3 = std::move(test_matrix2));

  zemlyak::Matrix test_matrix4 = zemlyak::part(test_composite);
  zemlyak::Matrix test_matrix5;

  test_matrix5 = test_matrix4;
  BOOST_CHECK(test_matrix5 == test_matrix4);
  test_matrix5 = std::move(test_matrix4);

  BOOST_CHECK(test_matrix5 == test_matrix3);

  zemlyak::Matrix test_matrix6(test_matrix3);
  BOOST_CHECK(test_matrix6 == test_matrix3);
  zemlyak::Matrix test_matrix7(std::move(test_matrix3));

  BOOST_CHECK(test_matrix7 == test_matrix6);
}

BOOST_AUTO_TEST_CASE(exceptionThrow)
{
  shape_ptr test_circle = std::make_shared<zemlyak::Circle>(-3, 2.5, 5);
  shape_ptr test_rectangle = std::make_shared<zemlyak::Rectangle>(2, -4.5, 2, 6);
  zemlyak::CompositeShape test_composite;
  test_composite.add(test_circle);
  test_composite.add(test_rectangle);

  zemlyak::Matrix test_matrix = zemlyak::part(test_composite);

  BOOST_CHECK_THROW(test_matrix[3], std::out_of_range);
  BOOST_CHECK_THROW(test_matrix[-1], std::out_of_range);
}

BOOST_AUTO_TEST_SUITE_END()
