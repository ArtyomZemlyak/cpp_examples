#include "base-types.hpp"

bool zemlyak::intersect(const rectangle_t& lhs, const rectangle_t& rhs)
{
  const point_t lhs_top_lft = {lhs.pos.x - lhs.width / 2, lhs.pos.y + lhs.height / 2};
  const point_t lhs_btm_rgt = {lhs.pos.x + lhs.width / 2, lhs.pos.y - lhs.height / 2};
  const point_t rhs_top_lft = {rhs.pos.x - rhs.width / 2, rhs.pos.y + rhs.height / 2};
  const point_t rhs_btm_rgt = {rhs.pos.x + rhs.width / 2, rhs.pos.y - rhs.height / 2};

  const bool top_lft_condition = (lhs_top_lft.x < rhs_btm_rgt.x) && (rhs_btm_rgt.y < lhs_top_lft.y);
  const bool btm_rgt_condition = (rhs_top_lft.x < lhs_btm_rgt.x) && (lhs_btm_rgt.y < rhs_top_lft.y);

  return top_lft_condition && btm_rgt_condition;
}
