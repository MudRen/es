#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

void init()
{
  tell_object(this_player(),set_color(
    "哎呀不好！一股腥臭的沼气让你一阵头晕目眩！\n","HIG"));
  (CONDITION_PREFIX + "simple_poison")->apply_effect( this_player(), 10, 2 );
}
    